#pragma once
#include <SFML/Audio/Music.hpp>

namespace space_shooter::ecs {
    struct MusicComponent : Component {
        sf::Music music;

        MusicComponent(const std::string& musicFile) {
            music.openFromFile(musicFile);
        }
    };
}
