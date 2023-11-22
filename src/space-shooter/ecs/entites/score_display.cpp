#include <space-shooter/ecs/entities/score_display.hpp>

#include <space-shooter/ecs/components/tag_component.hpp>
#include <space-shooter/ecs/components/score_component.hpp>
#include <space-shooter/ecs/components/text_component.hpp>
//#include <space-shooter/ecs/components/scene_component.hpp>

#include <filesystem>

namespace space_shooter::ecs {

    ScoreDisplayEntity::ScoreDisplayEntity() {
        add<ScoreComponent>();
        add<TagComponent>("Score");
        add<TextComponent>();

       
    }

} // namespace space_shooter::ecs
