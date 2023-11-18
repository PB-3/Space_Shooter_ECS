#pragma once

#include <space-shooter/ecs/entity.hpp>

#include <SFML/Graphics/Color.hpp>
#include <SFML/System/Vector2.hpp>

#include <filesystem>
#include <memory>

namespace space_shooter::ecs {

    class PlayerMissileEntity : public Entity {
    public:
        PlayerMissileEntity(sf::Vector2f pos, const std::filesystem::path& texture_path,
            sf::Vector2f velocity);
        PlayerMissileEntity() = delete;

        using Entity::Entity;
    };

} // namespace space_shooter::ecs
