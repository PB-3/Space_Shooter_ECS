#include <space-shooter/ecs/systems/health_bar_display_system.hpp>

#include <space-shooter/ecs/components/sprite_component.hpp>
#include <space-shooter/ecs/components/position_component.hpp>
#include <space-shooter/ecs/components/health_component.hpp>
#include <space-shooter/ecs/components/texture_component.hpp>
#include <space-shooter/ecs/components/tag_component.hpp>

#include<space-shooter/ecs/entities/player_ship.hpp>

#include <space-shooter/ecs/manager.hpp>
#include <space-shooter/game_state.hpp>
#include <space-shooter/utils.hpp>

#include <SFML/Graphics.hpp>

#include <cassert>
#include <iostream>

namespace space_shooter::ecs {

    HealthBarDisplaySystem::HealthBarDisplaySystem()
        : System{
              type_list<HealthComponent, PositionComponent, TextureComponent,TagComponent,SpriteComponent>{} } {}

    void HealthBarDisplaySystem::update(const sf::Time& delta_time,
        std::vector<Entity*>& entities, Manager& manager) {

        

        for (auto e : entities) {

            assert(hasRequiredComponents(*e));
            const auto& tag = e->get<TagComponent>();

            if (tag.TagName == "PlayerShipHealthBar")
            {
                auto player_health = manager.getFromEntity<ecs::PlayerShipEntity>(
                    [](auto& player) { return player.get<ecs::HealthComponent>().health; });

                if (player_health)
                {
                    auto& hp = *player_health;
                    auto& sprite = e->get<SpriteComponent>();
                    auto& pos = e->get<PositionComponent>();
                    auto& tex = e->get<TextureComponent>();
                    float maxHealth = 100.0f;  

                    float healthPercentage = static_cast<float>(hp) / maxHealth;

                    sprite.width = 376 *  healthPercentage;

                }
            }

            
        }
    }

} // namespace space_shooter::ecs
