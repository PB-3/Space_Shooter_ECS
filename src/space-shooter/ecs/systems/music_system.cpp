#include "space-shooter/ecs/systems/music_system.hpp"

namespace space_shooter::ecs {
    MusicSystem::MusicSystem()
        : System(type_list<ecs::MusicComponent>{}) {}

    void MusicSystem::update(const sf::Time& delta_time, std::vector<Entity*>& entities, Manager& manager) {
        // Impl�mentation de la logique de mise � jour de la musique
    }
}
