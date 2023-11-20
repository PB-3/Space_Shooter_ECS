#include <space-shooter/ecs/systems/text_rendering_system.hpp>

#include <space-shooter/ecs/components/cooldown_component.hpp>
#include <space-shooter/ecs/components/tag_component.hpp>
#include <space-shooter/ecs/components/timer_component.hpp>
#include <space-shooter/ecs/manager.hpp>
#include <space-shooter/game_state.hpp>
#include <space-shooter/utils.hpp>

#include <SFML/Graphics.hpp>

#include <cassert>
#include <iostream>

namespace space_shooter::ecs {

    TextRenderingSystem::TextRenderingSystem()
        : System{
              type_list<TimerComponent>{} } {}

    void TextRenderingSystem::update(const sf::Time& delta_time,
        std::vector<Entity*>& entities, Manager& manager) {


        for (auto e : entities) {
            assert(hasRequiredComponents(*e));


            auto& timer = e->get<TimerComponent>();

            
            sf::Font font;
            std::filesystem::path font_path;
            font_path = manager.gameState().config.path_to_fonts / "IMMORTAL.ttf";
            font.loadFromFile(font_path.string());
            if (!font.loadFromFile(font_path.string()))
            {
                std::cout << "cant find font" << std::endl;
            }
            sf::Text text;
            
            sf::String s = std::to_string(timer.Timer.asSeconds());
            // select the font
            text.setFont(font); // font is a sf::Font

            // set the string to display
            text.setString(s);

            // set the character size
            text.setCharacterSize(10); // in pixels, not points!

            // set the color
            text.setFillColor(sf::Color::Red);

            // set the text style
            text.setStyle(sf::Text::Bold | sf::Text::Underlined);

            text.setOrigin(0, 0);
            sf::CircleShape shape(50.f);

            // set the shape color to green
            shape.setFillColor(sf::Color(100, 250, 50));


            manager.gameState().rendering_window->draw(text);
           

        }
    }

} // namespace space_shooter::ecs
