#pragma once

#include <space-shooter/ecs/component.hpp>
#include <SFML/System/Vector2.hpp>

namespace space_shooter::ecs {

struct PositionComponent : Component {
  float x = 0.f;
  float y = 0.f;

  PositionComponent() = default;
  PositionComponent(float x, float y) : x{ x }, y{ y } {};

  sf::Vector2f getPosition() {
	  return sf::Vector2f(this->x, this->y);
  }
};

} // namespace space_shooter::ecs