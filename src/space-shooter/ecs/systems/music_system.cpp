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
                
                if (musicComponent.music.getStatus() != sf::Music::Playing) {
                    musicComponent.music.play();
                }
             
            }
        }
    }
}
