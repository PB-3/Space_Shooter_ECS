#pragma once

#include <space-shooter/ecs/component.hpp>

namespace space_shooter::ecs {

struct VelocityComponent : Component {
  float vx = 0.f; // no velocity = fixed
  float vy = 0.f; // no velocity = fixed

  VelocityComponent() = default;
  VelocityComponent(float vx, float vy) : vx{vx}, vy{vy} {}

  void setVelocity(sf::Vector2f x)
  {
	  this->vx = x.x;
	  this->vy = x.y;
  }
};

} // namespace space_shooter::ecs