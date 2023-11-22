#include <space-shooter/ecs/entities/player_missile.hpp>

#include <space-shooter/ecs/components/all.hpp>

#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/Time.hpp>

namespace space_shooter::ecs {


    PlayerMissileEntity::PlayerMissileEntity(sf::Vector2f pos,
        const std::filesystem::path& texture_path,
        sf::Vector2f velocity) {
        add<PositionComponent>(pos.x, pos.y);
        add<InputComponent>();
        add<TextureComponent>(texture_path);
        add<SpriteComponent>(30, 33, SpriteComponent::Resize::Scale);
        add<VelocityComponent>(velocity.x, velocity.y);
        add<DamageComponent>(50);
        add<TagComponent>("PlayerMissile");

    }

} // namespace space_shooter::ecs
