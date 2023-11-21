#pragma once
#include <string>
#include "space-shooter/ecs/entity.hpp"
#include "space-shooter/ecs/components/music_component.hpp"

namespace space_shooter::ecs {
    class BackgroundMusic : public Entity {
    public:
        BackgroundMusic(const std::string& musicFile);
    };
}
