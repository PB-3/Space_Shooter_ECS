#include "space-shooter/ecs/systems/audio_system.hpp"

namespace space_shooter::ecs {
    AudioSystem::AudioSystem() 
        : System(type_list<ecs::AudioComponent>{}) {}

    void AudioSystem::update(const sf::Time& delta_time, std::vector<Entity*>& entities, Manager& manager) {
        // Impl�mentation de la logique de mise � jour des effets sonores
    }
}
