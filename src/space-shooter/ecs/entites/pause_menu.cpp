#include <space-shooter/ecs/entities/pause_menu.hpp>

#include <space-shooter/ecs/components/input_component.hpp>
#include <space-shooter/ecs/components/tag_component.hpp>
#include <space-shooter/ecs/components/texture_component.hpp>
//#include <space-shooter/ecs/components/scene_component.hpp>

#include <filesystem>

namespace space_shooter::ecs {

    PauseMenuEntity::PauseMenuEntity() {
        add<InputComponent>();
        add<TagComponent>("pause");
    }

} // namespace space_shooter::ecs
