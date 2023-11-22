// enemy_chasing_system.cpp
#include <space-shooter/ecs/systems/enemy_chasing_system.hpp>
#include <space-shooter/ecs/components/position_component.hpp>
#include <space-shooter/ecs/components/velocity_component.hpp>
#include <space-shooter/ecs/components/tag_component.hpp>
#include <space-shooter/ecs/entities/player_ship.hpp>

#include <space-shooter/ecs/manager.hpp>

#include <cassert>
namespace space_shooter::ecs {

    EnemyChasingSystem::EnemyChasingSystem()
        : System(type_list<ecs::PositionComponent, ecs::VelocityComponent,ecs::TagComponent>{}) {}

    void EnemyChasingSystem::update(const sf::Time& delta_time,
        std::vector<Entity*>& entities,
        Manager& manager) {
        for (auto e : entities) {
            assert(hasRequiredComponents(*e));

            auto& enemy_position = e->get<ecs::PositionComponent>();
            auto& enemy_velocity = e->get<ecs::VelocityComponent>();
            auto& tag = e->get<ecs::TagComponent>();

            if (tag.TagName == "EnemyShip") {
                
                auto player_position_opt = manager.getFromEntity<ecs::PlayerShipEntity>(
                    [](auto& player) { return player.get<ecs::PositionComponent>().getPosition(); });

                if (player_position_opt) {
                    const auto& player_position = *player_position_opt;

                    
                    sf::Vector2f direction = player_position - enemy_position.getPosition();
                    
                    float length = std::sqrt(direction.x * direction.x + direction.y * direction.y);
                    direction /= length;

                   
                    float speed = 50.0f; 
                    enemy_velocity.setVelocity(direction * speed);

                    enemy_position.x += enemy_velocity.vx * delta_time.asSeconds();
                    enemy_position.y += enemy_velocity.vy * delta_time.asSeconds();
                }
            }
        }
    }

} // namespace space_shooter::ecs
