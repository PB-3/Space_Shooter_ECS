#include <space-shooter/ecs/systems/cleankilledship_system.hpp>
#include <space-shooter/ecs/components/all.hpp>
#include <iostream>

namespace space_shooter::ecs {

    CleanKilledShipsSystem::CleanKilledShipsSystem()
        : System(type_list<HealthComponent, TagComponent>()) {}

    void CleanKilledShipsSystem::update(const sf::Time& delta_time, std::vector<Entity*>& entities, Manager& manager) {
        for (auto& entity : entities) {
            // V�rifiez si l'entit� est vivante et a les composants n�cessaires
            if (entity->isAlive() && entity->has<HealthComponent>() && entity->has<TagComponent>()) {
                auto& health = entity->get<HealthComponent>();
                auto& tag = entity->get<TagComponent>();

                // V�rifie si c'est un vaisseau et si sa sant� est � z�ro ou moins
                if ((tag.TagName == "EnemyShip" || tag.TagName == "PlayerShip") && health.health <= 0) {
                    std::cout << "Ship destroyed: " << tag.TagName << std::endl;
                    entity->kill(); // Marquez l'entit� comme non vivante
                }
            }
        }
    }

} // namespace space_shooter::ecs
