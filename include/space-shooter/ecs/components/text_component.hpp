#pragma once

#include <space-shooter/ecs/component.hpp>

#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Font.hpp>

#include <filesystem>

namespace space_shooter::ecs {

    struct TextComponent : Component {
        std::filesystem::path font_path;
        std::string message;
        sf::Text text;
        bool loaded = false;

        explicit TextComponent(const std::filesystem::path& font_path,
           std::string message)
            : font_path{ font_path }, message{ message } {}
        TextComponent() = default;
    };

} // namespace space_shooter::ecs
