#pragma once

#include <space-shooter/ecs/entity.hpp>

#include <filesystem>
#include <memory>

namespace space_shooter::ecs {

    class ScoreDisplayEntity : public Entity {
    public:
        ScoreDisplayEntity();


        using Entity::Entity;
    };

} // namespace space_shooter::ecs
