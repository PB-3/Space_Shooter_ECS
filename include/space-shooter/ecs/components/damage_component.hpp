#pragma once

#include <space-shooter/ecs/component.hpp>

namespace space_shooter::ecs {

    struct DamageComponent : Component {
        int damage;

        DamageComponent(int damage) : damage(damage) {}
    };

} // namespace space_shooter::ecs
