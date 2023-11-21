#include <space-shooter/ecs/systems/healthbardisplay_system.hpp>
#include <space-shooter/ecs/components/all.hpp>
#include <space-shooter/ecs/entities/player_ship_healthbar.hpp>
#include <space-shooter/ecs/manager.hpp>
#include <iostream>

namespace space_shooter::ecs {

    // Constructeur de HealthBarDisplaySystem
    HealthBarDisplaySystem::HealthBarDisplaySystem()
        : System{ type_list<TagComponent>() } {} // Il fallait juste mettre un composant

    // Méthode de mise à jour appelée à chaque frame
    void HealthBarDisplaySystem::update(const sf::Time& delta_time, std::vector<Entity*>& entities, Manager& manager) {
        float playerHealthPercentage = 0.0f; // Pourcentage de santé du joueur
        PlayerShipHealthBar* healthBarEntity = nullptr; // Pointeur vers l'entité de la barre de santé

        //std::cout << "Nombre total d'entites recues: " << entities.size() << std::endl;

        // Parcours de toutes les entités
        for (auto& entity : entities) {
            if (entity->has<TagComponent>()) {
                auto& tag = entity->get<TagComponent>();
                //std::cout << "Entité trouvee avec le tag: " << tag.TagName << std::endl;

                // Si l'entité est le vaisseau du joueur
                if (tag.TagName == "PlayerShip" && entity->has<HealthComponent>()) {
                    auto& health = entity->get<HealthComponent>();
                    playerHealthPercentage = static_cast<float>(health.health) / 100.0f; // Calcul du pourcentage de santé
                }

                // Si l'entité est la barre de santé
                if (tag.TagName == "PlayerHealthBar") {
                    //std::cout << "tag found: " << tag.TagName << std::endl;
                    healthBarEntity = static_cast<PlayerShipHealthBar*>(entity); // Casting vers PlayerShipHealthBar
                }

            }
        }

        // Si la barre de santé est trouvée, la mettre à jour et la dessiner
        if (healthBarEntity) {
            healthBarEntity->updateHealthBar(playerHealthPercentage); // Mise à jour de la barre
            sf::RectangleShape& healthBarDrawable = healthBarEntity->getDrawable(); // Obtention du drawable
            manager.gameState().rendering_window->draw(healthBarDrawable); // Dessin de la barre de santé
        }
    }
} // namespace space_shooter::ecs