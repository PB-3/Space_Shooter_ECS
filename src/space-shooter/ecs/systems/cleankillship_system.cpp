#include <space-shooter/ecs/systems/cleankilledship_system.hpp>
#include <space-shooter/ecs/components/all.hpp>
#include <iostream>

namespace space_shooter::ecs {

    CleanKilledShipsSystem::CleanKilledShipsSystem()
        : System(type_list<HealthComponent, TagComponent>()) {}

    void CleanKilledShipsSystem::update(const sf::Time& delta_time, std::vector<Entity*>& entities, Manager& manager) {
        for (auto& entity : entities) {
            if (entity->isAlive() && entity->has<HealthComponent>() && entity->has<TagComponent>()) {
                auto& health = entity->get<HealthComponent>();
                auto& tag = entity->get<TagComponent>();

                if ((tag.TagName == "EnemyShip" || tag.TagName == "PlayerShip" || tag.TagName == "EnemySpawner") && health.health <= 0) {
                    entity->kill(); 

                }
            }
        }
    }

} // namespace space_shooter::ecs
