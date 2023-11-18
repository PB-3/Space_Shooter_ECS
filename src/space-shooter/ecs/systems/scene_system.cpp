#include <space-shooter/ecs/systems/scene_system.hpp>

//#include <space-shooter/ecs/components/scene_component.hpp>

#include <space-shooter/ecs/components/input_component.hpp>
#include <space-shooter/ecs/system.hpp>
#include <space-shooter/ecs/manager.hpp>
#include <space-shooter/game_state.hpp>
#include <space-shooter/utils.hpp>

#include <SFML/Graphics.hpp>

#include <cassert>
#include <iostream>

namespace space_shooter::ecs {

    SceneSystem::SceneSystem()
        : System{
              type_list<InputComponent>{} } {}

    void SceneSystem::update(const sf::Time& delta_time,
        std::vector<Entity*>& entities, Manager& manager) {
        

        for (auto e : entities) {
            assert(hasRequiredComponents(*e));

            const auto& input = e->get<InputComponent>();
            // const auto& scene_input = e->get<SceneCompoenent>();

            
            if (input.switch_scene_menu)
            {
                manager.gameState().switch_to_scene = GameState::Scene::Menu;
            }
            if (input.switch_scene_level)
            {
                manager.gameState().switch_to_scene = GameState::Scene::Level;
            }
            if (input.switch_scene_exit)
            {
                manager.gameState().switch_to_scene = GameState::Scene::Exit;
            }
        }
    }

} // namespace space_shooter::ecs
