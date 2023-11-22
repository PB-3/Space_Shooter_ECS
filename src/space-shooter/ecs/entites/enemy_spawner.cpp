#include <space-shooter/ecs/entities/enemy_spawner.hpp>

#include <space-shooter/ecs/components/input_component.hpp>
#include <space-shooter/ecs/components/position_component.hpp>
#include <space-shooter/ecs/components/sprite_component.hpp>
#include <space-shooter/ecs/components/texture_component.hpp>
#include <space-shooter/ecs/components/velocity_component.hpp>
#include <space-shooter/ecs/components/tag_component.hpp>
#include <space-shooter/ecs/components/cooldown_component.hpp>
#include <space-shooter/ecs/components/clock_component.hpp>
#include <space-shooter/ecs/components/health_component.hpp>

#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/Time.hpp>

namespace space_shooter::ecs {


    EnemySpawnerEntity::EnemySpawnerEntity(sf::Vector2f pos,
        const std::filesystem::path& texture_path)
    {
        add<PositionComponent>(pos.x, pos.y);
        //add<InputComponent>();
        add<TextureComponent>(texture_path);
        add<SpriteComponent>(50, 67, SpriteComponent::Resize::Scale);
        add<CooldownComponent>(sf::seconds(1));
        add<ClockComponent>();
        add<HealthComponent>(200);
        add<TagComponent>("EnemySpawner");



    }

} // namespace space_shooter::ecs
