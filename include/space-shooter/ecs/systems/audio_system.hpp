#pragma once
#include <space-shooter/ecs/system.hpp>
#include <space-shooter/ecs/components/audio_component.hpp>
#include <vector>
#include <SFML/System/Time.hpp>

namespace space_shooter::ecs {
    class AudioSystem : public System {
    public:
        AudioSystem();

        void update(const sf::Time& delta_time, std::vector<Entity*>& entities, Manager& manager) override;
    };
}
