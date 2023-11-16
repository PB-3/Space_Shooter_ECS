#pragma once

#include <space-shooter/ecs/system.hpp>

#include <vector>

namespace space_shooter::ecs {

    class SceneSystem : public System {
    public:
        SceneSystem();
        void update(const sf::Time& delta_time, std::vector<Entity*>& entities,
            Manager& manager) override;
    };

} // namespace space_shooter::ecs