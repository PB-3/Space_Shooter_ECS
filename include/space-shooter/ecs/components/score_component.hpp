#pragma once

#include <space-shooter/ecs/component.hpp>

namespace space_shooter::ecs {

    struct ScoreComponent : Component {
        int score=0;

        ScoreComponent() = default;

        int getScore() {
            return this->score;
        }
    };

} // namespace space_shooter::ecs
