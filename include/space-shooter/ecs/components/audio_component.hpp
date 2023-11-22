#pragma once
#include <SFML/Audio/SoundBuffer.hpp>
#include <SFML/Audio/Sound.hpp>

namespace space_shooter::ecs {
    struct AudioComponent : Component {
        sf::SoundBuffer buffer;
        sf::Sound sound;
        bool playSound = false; // Ajout d'un flag pour jouer le son

        AudioComponent(const std::string& audioFile) {
            if (buffer.loadFromFile(audioFile)) {
                sound.setBuffer(buffer);
            }
        }
    };
}
