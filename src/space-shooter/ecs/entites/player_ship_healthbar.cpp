#include "space-shooter/ecs/entities/player_ship_healthbar.hpp"
#include <space-shooter/ecs/components/all.hpp>
#include <iostream>

namespace space_shooter::ecs {

    PlayerShipHealthBar::PlayerShipHealthBar(const sf::Vector2f& position, float Width)
        : healthBarOriginalWidth(Width) {
        // D�finit la taille de la barre de sant�.
        healthBar.setSize(sf::Vector2f(Width, 20));  // Hauteur fixe de 20 pixels par exemple.

        // D�finit la couleur de la barre de sant�.
        healthBar.setFillColor(sf::Color::Green);  // Couleur verte par d�faut.

        // Positionne la barre de sant�.
        healthBar.setPosition(position);

        // Ajoute un TagComponent si n�cessaire pour l'identification dans le syst�me ECS.
        add<TagComponent>("PlayerHealthBar");
        //auto& tag = get<TagComponent>();
        //std::cout << "le tag" << tag.TagName << "est bien cree" << std::endl;
    }

    void PlayerShipHealthBar::updateHealthBar(float healthPercentage) {
        // Assurez que le pourcentage de sant� est compris entre 0.0 et 1.0.
        healthPercentage = std::max(0.0f, std::min(healthPercentage, 1.0f));

        // Met � jour la taille de la barre de sant� en fonction du pourcentage.
        healthBar.setSize(sf::Vector2f(healthBarOriginalWidth * healthPercentage, healthBar.getSize().y));
    }

    sf::RectangleShape& PlayerShipHealthBar::getDrawable() {
        // Retourne la barre de sant� pour le render.
        return healthBar;
    }

} // namespace space_shooter::ecs
