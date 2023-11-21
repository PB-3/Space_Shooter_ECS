#pragma once

#include <space-shooter/ecs/component.hpp>
#include <SFML/Graphics/Color.hpp>

namespace space_shooter::ecs {

struct SpriteComponent : Component {
  enum class Resize { Crop, Scale };

  int width = 0;
  int height = 0;
  sf::Color color = sf::Color::White;
  Resize resize = Resize::Crop;

  SpriteComponent() = default;
  SpriteComponent(int width, int height, Resize resize = Resize::Crop)
      : width{width}, height{height}, resize{resize} {}
  SpriteComponent(int width, int height, sf::Color color, Resize resize = Resize::Crop)
      : width{ width }, height{ height }, color{ color }, resize{ resize } {}
};

} // namespace space_shooter::ecs