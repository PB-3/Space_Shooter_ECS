#pragma once

#include <space-shooter/ecs/system.hpp>
#include <space-shooter/ecs/manager.hpp>
#include <SFML/System/Time.hpp>

namespace space_shooter::ecs {

    class CleanKilledShipsSystem : public System {
    public:
        CleanKilledShipsSystem();
        void update(const sf::Time& delta_time, std::vector<Entity*>& entities, Manager& manager) override;
    };

} // namespace space_shooter::ecs
