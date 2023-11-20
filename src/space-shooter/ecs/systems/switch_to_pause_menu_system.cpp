#include <space-shooter/ecs/systems/switch_to_pause_menu_system.hpp>
#include <space-shooter/scenes/scene_pause.hpp>

#include <space-shooter/ecs/components/tag_component.hpp>
#include <space-shooter/ecs/components/input_component.hpp>

#include <space-shooter/ecs/entities/background.hpp>


#include <space-shooter/ecs/system.hpp>
#include <space-shooter/ecs/manager.hpp>
#include <space-shooter/game_state.hpp>
#include <space-shooter/utils.hpp>

#include <SFML/Graphics.hpp>

#include <cassert>
#include <iostream>

namespace space_shooter::ecs {

    SwitchToPauseMenuSystem::SwitchToPauseMenuSystem()
        : System{
              type_list<InputComponent,TagComponent>{} } {}

    void SwitchToPauseMenuSystem::update(const sf::Time& delta_time,
        std::vector<Entity*>& entities, Manager& manager) {


        for (auto e : entities) {
            assert(hasRequiredComponents(*e));

            auto& input = e->get<InputComponent>();
            const auto& tag = e->get<TagComponent>();
            
            // const auto& scene_input = e->get<SceneCompoenent>();

            if (tag.TagName == "pause") {
                if (input.pause)
                {
                    manager.gameState().keep_entities = true;
                    manager.gameState().keep_systems = true;
                    manager.disableAllSystems();
                    manager.gameState().switch_to_scene = GameState::Scene::Pause;
                    input.pause = false;

   
                }
                if (input.resume)
                {

                    manager.gameState().keep_entities = false;
                    manager.gameState().keep_systems = false;                   
                    manager.enableAllSystems();
                }
            }
        }
    }

} // namespace space_shooter::ecs
