#pragma once

#include <space-shooter/ecs/component.hpp>

namespace space_shooter::ecs {

    struct HealthComponent : Component {
        int health;

        HealthComponent(int health) : health(health) {}
    };

} // namespace space_shooter::ecs
