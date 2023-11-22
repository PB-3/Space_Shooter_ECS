#include <space-shooter/ecs/entities/text_entity.hpp>

#include <space-shooter/ecs/components/input_component.hpp>
#include <space-shooter/ecs/components/text_component.hpp>
#include <space-shooter/ecs/components/texture_component.hpp>
//#include <space-shooter/ecs/components/scene_component.hpp>

#include <filesystem>

namespace space_shooter::ecs {

    TextEntity::TextEntity(const std::filesystem::path& font_path,
        std::string message) {
        add<InputComponent>();
        add<TextComponent>(font_path,message);
        // add<PositionComponent>(0.f, 0.f);
         //add<TextureComponent>(texture_path, true);
         //add<SpriteComponent>(window_width, window_height);
    }

} // namespace space_shooter::ecs
