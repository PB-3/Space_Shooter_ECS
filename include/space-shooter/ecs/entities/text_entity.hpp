#pragma once

#include <space-shooter/ecs/entity.hpp>

#include <filesystem>
#include <memory>

namespace space_shooter::ecs {

    class TextEntity : public Entity {
    public:
        TextEntity(const std::filesystem::path& font_path,
            std::string message);
       TextEntity() = delete;

        using Entity::Entity;
    };

} // namespace space_shooter::ecs
