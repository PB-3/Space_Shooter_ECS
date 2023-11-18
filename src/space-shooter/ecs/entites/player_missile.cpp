#include <space-shooter/ecs/entities/player_missile.hpp>

#include <space-shooter/ecs/components/input_component.hpp>
#include <space-shooter/ecs/components/position_component.hpp>
#include <space-shooter/ecs/components/sprite_component.hpp>
#include <space-shooter/ecs/components/texture_component.hpp>
#include <space-shooter/ecs/components/velocity_component.hpp>
#include <space-shooter/ecs/components/tag_component.hpp>
#include <space-shooter/ecs/components/cooldown_component.hpp>

#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/Time.hpp>

namespace space_shooter::ecs {


    PlayerMissileEntity::PlayerMissileEntity(sf::Vector2f pos,
        const std::filesystem::path& texture_path,
        sf::Vector2f velocity) {
        add<PositionComponent>(pos.x, pos.y);
        add<InputComponent>();
        add<TextureComponent>(texture_path);
        add<SpriteComponent>(50, 20, SpriteComponent::Resize::Scale);
        add<VelocityComponent>(velocity.x, velocity.y);
        add<TagComponent>("PlayerMissile");

    }

} // namespace space_shooter::ecs
