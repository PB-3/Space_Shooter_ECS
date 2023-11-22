#include "space-shooter/ecs/entities/soundeffects.hpp"

namespace space_shooter::ecs {
    SoundEffects::SoundEffects(const std::string& audioFile) {
        add<AudioComponent>(audioFile);
    }
}
