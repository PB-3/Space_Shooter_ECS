#include "space-shooter/ecs/entities/player_ship_healthbar.hpp"
#include <space-shooter/ecs/components/all.hpp>
#include <iostream>

namespace space_shooter::ecs {

    PlayerShipHealthBar::PlayerShipHealthBar(const sf::Vector2f& position, float Width)
        : healthBarOriginalWidth(Width) {
        // Définit la taille de la barre de santé.
        healthBar.setSize(sf::Vector2f(Width, 20));  // Hauteur fixe de 20 pixels par exemple.

        // Définit la couleur de la barre de santé.
        healthBar.setFillColor(sf::Color::Green);  // Couleur verte par défaut.

        // Positionne la barre de santé.
        healthBar.setPosition(position);

        // Ajoute un TagComponent si nécessaire pour l'identification dans le système ECS.
        add<TagComponent>("PlayerHealthBar");
        //auto& tag = get<TagComponent>();
        //std::cout << "le tag" << tag.TagName << "est bien cree" << std::endl;
    }

    void PlayerShipHealthBar::updateHealthBar(float healthPercentage) {
        // Assurez que le pourcentage de santé est compris entre 0.0 et 1.0.
        healthPercentage = std::max(0.0f, std::min(healthPercentage, 1.0f));

        // Met à jour la taille de la barre de santé en fonction du pourcentage.
        healthBar.setSize(sf::Vector2f(healthBarOriginalWidth * healthPercentage, healthBar.getSize().y));
    }

    sf::RectangleShape& PlayerShipHealthBar::getDrawable() {
        // Retourne la barre de santé pour le render.
        return healthBar;
    }

} // namespace space_shooter::ecs
