#include "space-shooter/ecs/systems/music_system.hpp"
#include "space-shooter/ecs/components/all.hpp"
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

            if (e->has<MusicComponent>()) {
                auto& musicComponent = e->get<MusicComponent>();

                // Exemple de gestion de la musique
                if (musicComponent.music.getStatus() != sf::Music::Playing) {
                    // Démarrer la musique si elle n'est pas déjà en train de jouer
                    musicComponent.music.play();
                }
                /* // Récupérer les commandes de volume de l'InputComponent
                auto volumeInput = manager.getFromEntity<InputComponent>([](InputComponent& ic) {
                    return &ic;
                    });
                if (volumeInput) {
                    if (volumeInput.value()->volumeUp) {
                        musicComponent.volume = std::min(100.0f, musicComponent.volume + 5.0f); // Augmenter le volume
                    }
                    if (volumeInput.value()->volumeDown) {
                        musicComponent.volume = std::max(0.0f, musicComponent.volume - 5.0f); // Diminuer le volume
                    }
                }

                musicComponent.music.setVolume(musicComponent.volume);*/
            }
        }
    }
}
