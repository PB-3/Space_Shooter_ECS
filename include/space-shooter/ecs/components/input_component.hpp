#pragma once

#include <space-shooter/ecs/component.hpp>

namespace space_shooter::ecs {

struct InputComponent : Component {

  // TODO all supported input in the form of boolean here
  bool move_left = false;
  bool move_right = false;
  bool move_top = false;
  bool move_bottom = false;
  bool shooting = false;
  bool escape = false;
  bool enter = false;
  bool switch_scene_menu = false;
  bool switch_scene_level = false;
  bool switch_scene_exit = false;
  bool pause = false;
  bool resume = false;
  bool volumeUp = false;
  bool volumeDown = false;
  InputComponent() = default;

};

} // namespace space_shooter::ecs
