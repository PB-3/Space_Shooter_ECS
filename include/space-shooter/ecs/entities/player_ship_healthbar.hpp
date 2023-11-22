#pragma once

#include <space-shooter/ecs/entity.hpp>
#include <space-shooter/ecs/components/all.hpp>

#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/System/Vector2.hpp>

namespace space_shooter::ecs {

    class PlayerShipHealthBar : public Entity {
    public:
        // Constructeur prenant la position initiale et la largeur de la barre de sant�.
        PlayerShipHealthBar(const sf::Vector2f& position, float Width);

        // M�thode pour mettre � jour la barre de sant� en fonction du pourcentage de sant�.
        void updateHealthBar(float healthPercentage);

        // M�thode pour obtenir un drawable (une forme graphique) de la barre de sant�.
        sf::RectangleShape& getDrawable();

    private:
        sf::RectangleShape healthBar; // RectangleShape de SFML utilis� pour dessiner la barre de sant�.
        float healthBarOriginalWidth; // Stocke la largeur originale de la barre de sant�.
    };

} // namespace space_shooter::ecs
