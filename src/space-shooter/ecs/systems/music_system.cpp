#include "space-shooter/ecs/systems/music_system.hpp"

namespace space_shooter::ecs {
    MusicSystem::MusicSystem()
        : System(type_list<ecs::MusicComponent>{}) {}

    void MusicSystem::update(const sf::Time& delta_time, std::vector<Entity*>& entities, Manager& manager) {
        // Implémentation de la logique de mise à jour de la musique
    }
}
