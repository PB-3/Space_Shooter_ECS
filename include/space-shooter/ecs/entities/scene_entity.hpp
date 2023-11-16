#pragma once

#include <space-shooter/ecs/entity.hpp>

#include <filesystem>
#include <memory>

namespace space_shooter::ecs {

    class SceneEntity : public Entity {
    public:
        SceneEntity();
        

        using Entity::Entity;
    };

} // namespace space_shooter::ecs
