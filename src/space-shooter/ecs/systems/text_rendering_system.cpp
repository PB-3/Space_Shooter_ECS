#include <space-shooter/ecs/systems/text_rendering_system.hpp>

#include <space-shooter/ecs/components/timer_component.hpp>
#include <space-shooter/ecs/components/tag_component.hpp>
#include <space-shooter/ecs/components/text_component.hpp>
#include <space-shooter/ecs/components/score_component.hpp>

#include <space-shooter/ecs/entities/text_entity.hpp>

#include <space-shooter/ecs/manager.hpp>
#include <space-shooter/game_state.hpp>
#include <space-shooter/utils.hpp>

#include <SFML/Graphics.hpp>

#include <cassert>
#include <iostream>

namespace space_shooter::ecs {

    TextRenderingSystem::TextRenderingSystem()
        : System(type_list<TagComponent, TextComponent>{}) {}

    void TextRenderingSystem::update(const sf::Time& delta_time,
        std::vector<Entity*>& entities, Manager& manager) {
        for (auto e : entities) {
            
            assert(hasRequiredComponents(*e));

            sf::Font font;
            std::filesystem::path font_path_;
            sf::CircleShape shape(50.f);

            font_path_ = manager.gameState().config.path_to_fonts / "IMMORTAL.ttf";

            font.loadFromFile(font_path_.string());

            if (!font.loadFromFile(font_path_.string())) {
                std::cout << "Can't find font" << std::endl;
            }

            auto& Text = e->get<TextComponent>();
            auto& tag = e->get<TagComponent>();
            Text.font_path = font_path_;

            if (tag.TagName == "Score") {
                auto& score = e->get<ScoreComponent>();
                sf::String ss = std::to_string(score.score);

                Text.text.setFont(font);
                Text.text.setString(ss);
                Text.text.setCharacterSize(30);
                Text.text.setFillColor(sf::Color::Green);
                Text.text.setStyle(sf::Text::Bold | sf::Text::Underlined);
                Text.text.setOrigin(0, -20);

                manager.gameState().rendering_window->draw(Text.text);
            }

            if (tag.TagName == "Timer") {
                auto& timer = e->get<TimerComponent>();
                sf::String s = std::to_string(timer.Timer.asSeconds());

                Text.text.setFont(font);
                Text.text.setString(s);
                Text.text.setCharacterSize(10);
                Text.text.setFillColor(sf::Color::Red);
                Text.text.setStyle(sf::Text::Bold | sf::Text::Underlined);
                Text.text.setOrigin(0, 0);
                shape.setFillColor(sf::Color(100, 250, 50));
                Text.text.setString(s);

                manager.gameState().rendering_window->draw(Text.text);
            }

           
            
        }
    }

} // namespace space_shooter::ecs
