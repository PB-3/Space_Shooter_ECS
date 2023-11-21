#pragma once
#include <string>
#include "space-shooter/ecs/entity.hpp"
#include "space-shooter/ecs/components/audio_component.hpp"

namespace space_shooter::ecs {
    class SoundEffects : public Entity {
    public:
        SoundEffects(const std::string& audioFile);
    };
}
