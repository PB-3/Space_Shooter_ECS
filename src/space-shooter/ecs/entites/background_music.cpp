#include "space-shooter/ecs/entities/background_music.hpp"

namespace space_shooter::ecs {
    BackgroundMusic::BackgroundMusic(const std::string& musicFile) {
        add<MusicComponent>(musicFile);
    }
}
