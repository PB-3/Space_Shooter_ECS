#include "space-shooter/ecs/systems/music_system.hpp"
#include "space-shooter/ecs/components/music_component.hpp"
#include <space-shooter/ecs/manager.hpp>
#include <space-shooter/game_state.hpp>
#include <space-shooter/utils.hpp>

#include <cassert>
#include <iostream>

namespace space_shooter::ecs {
    MusicSystem::MusicSystem() 
        : System(type_list<ecs::MusicComponent>{}) {}

    void MusicSystem::update(const sf::Time& delta_time, std::vector<Entity*>& entities, Manager& manager) {
        for (auto e : entities) {
            assert(hasRequiredComponents(*e));

            auto& musicComponent = e->get<MusicComponent>();

            // Exemple de gestion de la musique
            if (musicComponent.music.getStatus() != sf::Music::Playing) {
                // Démarrer la musique si elle n'est pas déjà en train de jouer
                musicComponent.music.play();
            }
        }
    }
}
