#include <space-shooter/ecs/systems/shooting_system.hpp>

#include <space-shooter/ecs/components/input_component.hpp>
#include <space-shooter/ecs/components/tag_component.hpp>
#include <space-shooter/ecs/components/position_component.hpp>
#include <space-shooter/ecs/components/velocity_component.hpp>
#include <space-shooter/ecs/components/cooldown_component.hpp>

#include <space-shooter/ecs/system.hpp>
#include <space-shooter/ecs/manager.hpp>
#include <space-shooter/game_state.hpp>
#include <space-shooter/utils.hpp>

#include <space-shooter/ecs/entities/player_missile.hpp>

#include <SFML/Graphics.hpp>

#include <cassert>
#include <iostream>

namespace space_shooter::ecs {

    ShootingSystem::ShootingSystem()
        : System{
              type_list<InputComponent, TagComponent, PositionComponent, CooldownComponent>{} } {}

    void ShootingSystem::update(const sf::Time& delta_time, std::vector<Entity*>& entities, Manager& manager) {

        sf::Vector2f posShip;

        for (auto e : entities) {
            assert(hasRequiredComponents(*e));

            const auto& input = e->get<InputComponent>();
            auto& tag = e->get<TagComponent>();
            auto& pos = e->get<PositionComponent>();
            auto& cd  = e->get<CooldownComponent>();

            if (tag.TagName == "PlayerShip") {
                posShip.x = pos.x;
                posShip.y = pos.y;


                if (cd.elapsed_time == sf::Time::Zero && input.shooting) {

                    // Créer une nouvelle entité de missile
                    sf::Vector2f velocityM(100, 100);
                    std::filesystem::path texture_missile;
                    texture_missile = manager.gameState().config.path_to_textures / "penguin.png";
                    manager.registerEntity<ecs::PlayerMissileEntity>(posShip, texture_missile, velocityM);
                    cd.elapsed_time = cd.cooldown_duration;

                }
            }
        }
    }

} // namespace space_shooter::ecs
