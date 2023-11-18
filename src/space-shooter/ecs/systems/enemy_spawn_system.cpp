#include <space-shooter/ecs/systems/enemy_spawn_system.hpp>

#include <space-shooter/ecs/components/position_component.hpp>
#include <space-shooter/ecs/components/texture_component.hpp>
#include <space-shooter/ecs/components/tag_component.hpp>
#include <space-shooter/ecs/components/clock_component.hpp>
#include <space-shooter/ecs/components/cooldown_component.hpp>

#include <space-shooter/ecs/entities/enemy_ship.hpp>

#include <space-shooter/ecs/manager.hpp>
#include <space-shooter/utils.hpp>

#include <SFML/Graphics.hpp>

#include <cassert>
#include <iostream>
namespace space_shooter::ecs {

    EnemySystem::EnemySystem()
        : System(
            type_list<TextureComponent, PositionComponent, CooldownComponent,ClockComponent,TagComponent>{}) {}

    void EnemySystem::update(const sf::Time& delta_time,
        std::vector<Entity*>& entities,
        Manager& manager) {
        for (auto e : entities) {
            assert(hasRequiredComponents(*e));

            auto& pos = e->get<PositionComponent>();
            auto& cd =  e->get<CooldownComponent>();
            const auto& tag = e->get<TagComponent>();
            const auto& tex = e->get<TextureComponent>();

            
            if (tag.TagName == "EnemySpawner" && cd.elapsed_time == sf::Time::Zero)
            {
                pos.x += 60;
                if (pos.x < 900) {
                    cd.elapsed_time = cd.cooldown_duration;
                    sf::Vector2f enemyPos(pos.x, pos.y);
                    std::cout << "creation" <<pos.x<<","<<pos.y<< std::endl;
                    std::filesystem::path texture = manager.gameState().config.path_to_textures / "enemy.jpg";
                    manager.registerEntity<ecs::EnemyShipEntity>(enemyPos, texture, sf::Vector2f(100, 100));
                }
            }




        }
    }

} // namespace space_shooter::ecs