#include <space-shooter/ecs/systems/healthbardisplay_system.hpp>
#include <space-shooter/ecs/components/all.hpp>
#include <space-shooter/ecs/entities/player_ship_healthbar.hpp>
#include <space-shooter/ecs/manager.hpp>
#include <iostream>

namespace space_shooter::ecs {

    // Constructeur de HealthBarDisplaySystem
    HealthBarDisplaySystem::HealthBarDisplaySystem()
        : System{ type_list<TagComponent>() } {} // Il fallait juste mettre un composant

    // M�thode de mise � jour appel�e � chaque frame
    void HealthBarDisplaySystem::update(const sf::Time& delta_time, std::vector<Entity*>& entities, Manager& manager) {
        float playerHealthPercentage = 0.0f; // Pourcentage de sant� du joueur
        PlayerShipHealthBar* healthBarEntity = nullptr; // Pointeur vers l'entit� de la barre de sant�

        //std::cout << "Nombre total d'entites recues: " << entities.size() << std::endl;

        // Parcours de toutes les entit�s
        for (auto& entity : entities) {
            if (entity->has<TagComponent>()) {
                auto& tag = entity->get<TagComponent>();
                //std::cout << "Entit� trouvee avec le tag: " << tag.TagName << std::endl;

                // Si l'entit� est le vaisseau du joueur
                if (tag.TagName == "PlayerShip" && entity->has<HealthComponent>()) {
                    auto& health = entity->get<HealthComponent>();
                    playerHealthPercentage = static_cast<float>(health.health) / 100.0f; // Calcul du pourcentage de sant�
                }

                // Si l'entit� est la barre de sant�
                if (tag.TagName == "PlayerHealthBar") {
                    //std::cout << "tag found: " << tag.TagName << std::endl;
                    healthBarEntity = static_cast<PlayerShipHealthBar*>(entity); // Casting vers PlayerShipHealthBar
                }

            }
        }

        // Si la barre de sant� est trouv�e, la mettre � jour et la dessiner
        if (healthBarEntity) {
            healthBarEntity->updateHealthBar(playerHealthPercentage); // Mise � jour de la barre
            sf::RectangleShape& healthBarDrawable = healthBarEntity->getDrawable(); // Obtention du drawable
            manager.gameState().rendering_window->draw(healthBarDrawable); // Dessin de la barre de sant�
        }
    }
} // namespace space_shooter::ecs