#include <space-shooter/ecs/entities/scene_entity.hpp>

#include <space-shooter/ecs/components/input_component.hpp>
#include <space-shooter/ecs/components/sprite_component.hpp>
#include <space-shooter/ecs/components/texture_component.hpp>
//#include <space-shooter/ecs/components/scene_component.hpp>

#include <filesystem>

namespace space_shooter::ecs {

    SceneEntity::SceneEntity() {
        add<InputComponent>();
       // add<PositionComponent>(0.f, 0.f);
        //add<TextureComponent>(texture_path, true);
        //add<SpriteComponent>(window_width, window_height);
    }

} // namespace space_shooter::ecs
