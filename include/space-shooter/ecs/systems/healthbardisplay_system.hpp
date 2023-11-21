#pragma once

#include <space-shooter/ecs/system.hpp>
#include <space-shooter/ecs/components/all.hpp>
#include <SFML/System/Time.hpp>

namespace space_shooter::ecs {

    class HealthBarDisplaySystem : public System {
    public:
        HealthBarDisplaySystem(); // Constructeur
        void update(const sf::Time& delta_time, std::vector<Entity*>& entities, Manager& manager) override; // M�thode de mise � jour
    };

} // namespace space_shooter::ecs
