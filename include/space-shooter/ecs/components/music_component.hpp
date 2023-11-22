#pragma once
#include <SFML/Audio/Music.hpp>

namespace space_shooter::ecs {
    struct MusicComponent : Component {
        sf::Music music;
        float volume = 100.0f;

        MusicComponent(const std::string& musicFile) {
            music.openFromFile(musicFile);
        }
    };
}
