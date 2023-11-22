#include "space-shooter/ecs/systems/audio_system.hpp"
#include "space-shooter/ecs/components/all.hpp"
#include <space-shooter/ecs/manager.hpp>
#include <space-shooter/game_state.hpp>
#include <space-shooter/utils.hpp>

#include <cassert>
#include <iostream>

namespace space_shooter::ecs {
    AudioSystem::AudioSystem() : System(type_list<ecs::AudioComponent>{}) {}
    void AudioSystem::update(const sf::Time& delta_time, std::vector<Entity*>& entities, Manager& manager) {
        for (auto e : entities) {
            if (e->has<AudioComponent>()) {
                auto& audio = e->get<AudioComponent>();
                if (audio.playSound && audio.sound.getStatus() != sf::Sound::Playing) {
                    audio.sound.play();
                    audio.playSound = false; 
                }
            }
        }
    }
}