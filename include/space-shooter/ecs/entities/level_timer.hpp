#pragma once

#include <space-shooter/ecs/entity.hpp>

#include <SFML/Graphics/Color.hpp>
#include <SFML/System/Vector2.hpp>

#include <filesystem>
#include <memory>

namespace space_shooter::ecs {

    class LevelTimerEntity : public Entity {
    public:
        LevelTimerEntity(sf::Time t);

        using Entity::Entity;
    };

} // namespace space_shooter::ecs
