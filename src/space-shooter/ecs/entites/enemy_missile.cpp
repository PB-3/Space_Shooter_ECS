#include <space-shooter/ecs/entities/enemy_missile.hpp>

#include <space-shooter/ecs/components/all.hpp>

#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/Time.hpp>

#include <iostream>

namespace space_shooter::ecs {

    EnemyMissileEntity::EnemyMissileEntity(sf::Vector2f pos,
        const std::filesystem::path& texture_path,
        sf::Vector2f velocity) {
        add<PositionComponent>(pos.x, pos.y);
        add<InputComponent>();
        add<TextureComponent>(texture_path);
        add<SpriteComponent>(50, 20, SpriteComponent::Resize::Scale);
        add<VelocityComponent>(velocity.x, velocity.y);
        add<DamageComponent>(10);
        add<TagComponent>("EnemyMissile");
    }

} // namespace space_shooter::ecs
