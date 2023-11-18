#include <space-shooter/ecs/systems/clock_system.hpp>

#include <space-shooter/ecs/components/cooldown_component.hpp>
#include <space-shooter/ecs/components/tag_component.hpp>
#include <space-shooter/ecs/components/clock_component.hpp>
#include <space-shooter/ecs/manager.hpp>
#include <space-shooter/game_state.hpp>
#include <space-shooter/utils.hpp>

#include <SFML/Graphics.hpp>

#include <cassert>
#include <iostream>

namespace space_shooter::ecs {

    ClockSystem::ClockSystem()
        : System{
              type_list<CooldownComponent,TagComponent,ClockComponent>{} } {}

    void ClockSystem::update(const sf::Time& delta_time,
        std::vector<Entity*>& entities, Manager& manager) {


        for (auto e : entities) {
            assert(hasRequiredComponents(*e));

            auto& cd = e->get<CooldownComponent>();
            auto& tag = e->get<TagComponent>();
            auto& clock = e->get<ClockComponent>();

            clock.delta_time = delta_time;
            clock.elapsed_time += clock.delta_time;
            if (tag.TagName == "PlayerShip") {

                if (cd.elapsed_time < sf::Time::Zero)
                    cd.elapsed_time = sf::Time::Zero;
                // Update cooldown timers
                if (cd.elapsed_time > sf::Time::Zero) {
                    cd.elapsed_time -= delta_time;
                }


            }
            if (tag.TagName == "EnemySpawner") {

                if (cd.elapsed_time < sf::Time::Zero)
                    cd.elapsed_time = sf::Time::Zero;
                // Update cooldown timers
                if (cd.elapsed_time > sf::Time::Zero) {
                    cd.elapsed_time -= delta_time;
                }


            }
        }
    }

} // namespace space_shooter::ecs
