#pragma once

#include <space-shooter/ecs/entity.hpp>
#include <space-shooter/ecs/components/all.hpp>

#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/System/Vector2.hpp>

namespace space_shooter::ecs {

    class PlayerShipHealthBar : public Entity {
    public:
        // Constructeur prenant la position initiale et la largeur de la barre de santé.
        PlayerShipHealthBar(const sf::Vector2f& position, float Width);

        // Méthode pour mettre à jour la barre de santé en fonction du pourcentage de santé.
        void updateHealthBar(float healthPercentage);

        // Méthode pour obtenir un drawable (une forme graphique) de la barre de santé.
        sf::RectangleShape& getDrawable();

    private:
        sf::RectangleShape healthBar; // RectangleShape de SFML utilisé pour dessiner la barre de santé.
        float healthBarOriginalWidth; // Stocke la largeur originale de la barre de santé.
    };

} // namespace space_shooter::ecs
