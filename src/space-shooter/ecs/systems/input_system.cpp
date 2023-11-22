#include <SFML/Window/Keyboard.hpp>
#include <space-shooter/ecs/systems/input_system.hpp>
#include <space-shooter/ecs/components/input_component.hpp>
#include <space-shooter/ecs/systems/scene_system.hpp>
//#include <space-shooter/ecs/components/scene_component.hpp>
#include <space-shooter/ecs/entity.hpp>
#include <space-shooter/ecs/system.hpp>
#include <space-shooter/game_state.hpp>
#include <SFML/Graphics.hpp>

#include <cassert>
#include <iostream>

namespace space_shooter::ecs {

    InputSystem::InputSystem() : System{ type_list<InputComponent>{} } {}

    void InputSystem::update(const sf::Time& delta_time, std::vector<Entity*>& entities, Manager& manager) {
        for (auto e : entities) {
            assert(hasRequiredComponents(*e));

            auto& input = e->get<InputComponent>();
         //   auto& scene_input = e->get<SceneComponent>();

            // Reset detected input from keyboard
            input.move_top = false;
            input.move_bottom = false;
            input.move_left = false;
            input.move_right = false;
            input.switch_scene_level = false;
            input.switch_scene_exit = false;
            input.switch_scene_menu = false;
            input.shooting = false;
            input.pause = false;
            input.resume = false;

            // Detect key pressed with SFML and set the boolean state accordingly
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z) || sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
                input.move_top = true;
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) || sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
                input.move_bottom = true;
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
                input.move_left = true;
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
                input.move_right = true;
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::L))
            {
                input.switch_scene_level = true;
                
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::M))
            {
                input.switch_scene_menu = true;
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
            {
                input.switch_scene_exit = true;
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
            {
                input.shooting = true;
            }
           /* if (sf::Keyboard::isKeyPressed(sf::Keyboard::R))
            {
                input.resume = true;
                
            }*/
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad1))
            {
                input.volumeUp = true;
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad2))
            {
                input.volumeDown = true;
            }
        }
    }

} // namespace space_shooter::ecs
