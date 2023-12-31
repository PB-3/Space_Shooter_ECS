#include <space-shooter/ecs/entities/level_timer.hpp>

#include <space-shooter/ecs/components/input_component.hpp>
#include <space-shooter/ecs/components/sprite_component.hpp>
#include <space-shooter/ecs/components/texture_component.hpp>
#include <space-shooter/ecs/components/timer_component.hpp>
#include <space-shooter/ecs/components/tag_component.hpp>
#include <space-shooter/ecs/components/text_component.hpp>

#include <filesystem>

namespace space_shooter::ecs {

    LevelTimerEntity::LevelTimerEntity(sf::Time t) {

        add<TimerComponent>(t);
        add<TagComponent>("Timer");
        add<TextComponent>();

        
        
    }

} // namespace space_shooter::ecs
