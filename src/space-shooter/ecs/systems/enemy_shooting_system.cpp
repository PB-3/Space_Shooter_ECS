#include <space-shooter/ecs/systems/enemy_shooting_system.hpp>

#include <space-shooter/ecs/components/tag_component.hpp>
#include <space-shooter/ecs/components/position_component.hpp>
#include <space-shooter/ecs/components/cooldown_component.hpp>
#include <space-shooter/ecs/components/clock_component.hpp>

#include <space-shooter/ecs/system.hpp>
#include <space-shooter/ecs/manager.hpp>
#include <space-shooter/game_state.hpp>
#include <space-shooter/utils.hpp>

#include <space-shooter/ecs/entities/enemy_missile.hpp>


#include <SFML/Graphics.hpp>

#include <cassert>
#include <iostream>

namespace space_shooter::ecs {

    EnemyShootingSystem::EnemyShootingSystem()
        : System{
              type_list<TagComponent, PositionComponent, CooldownComponent>{} } {}

    void EnemyShootingSystem::update(const sf::Time& delta_time, std::vector<Entity*>& entities, Manager& manager) {
        for (auto e : entities) {
            assert(hasRequiredComponents(*e));

            const auto& tag = e->get<TagComponent>();
            auto& pos = e->get<PositionComponent>();
            auto& cd = e->get<CooldownComponent>();

            //std::cout<<tag.TagName<<std::endl;
            if (tag.TagName == "EnemyShip") {
                cd.elapsed_time -= delta_time;

                if (cd.elapsed_time <= sf::Time::Zero) {
                    cd.elapsed_time = cd.cooldown_duration;

                    sf::Vector2f enemyPosition(pos.x, pos.y);
                    sf::Vector2f missileVelocity(100, 100); // La vitesse vers le bas
                    //std::cout << "Creating enemy missile with velocity: " << missileVelocity.x << ", " << missileVelocity.y << std::endl;
                    //std::cout << "Cooldown remaining: " << cd.elapsed_time.asSeconds() << " seconds" << std::endl;
                    std::filesystem::path texture_missile = manager.gameState().config.path_to_textures / "enemy_missile.png";
                    manager.registerEntity<ecs::EnemyMissileEntity>(enemyPosition, texture_missile, missileVelocity);
                }
            }
        }
    }

} // namespace space_shooter::ecs
