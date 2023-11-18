#pragma once

#include <space-shooter/ecs/entity.hpp>

#include <SFML/Graphics/Color.hpp>
#include <SFML/System/Vector2.hpp>

#include <filesystem>
#include <memory>

namespace space_shooter::ecs {

    class EnemySpawnerEntity : public Entity {
    public:
        EnemySpawnerEntity(sf::Vector2f pos, const std::filesystem::path& texture_path);
        EnemySpawnerEntity() = delete;

        using Entity::Entity;
    };

} // namespace space_shooter::ecs
