#include <space-shooter/ecs/entities/player_ship_health_bar.hpp>

#include <space-shooter/ecs/components/all.hpp>

#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/Time.hpp>

namespace space_shooter::ecs {


    PlayerShipHealthBar::PlayerShipHealthBar(sf::Vector2f pos,
        const std::filesystem::path& texture_path) {
        add<PositionComponent>(pos.x, pos.y);
        add<TextureComponent>(texture_path);
        add<SpriteComponent>(400, 376, SpriteComponent::Resize::Scale);
        add<HealthComponent>(100);
        add<TagComponent>("PlayerShipHealthBar");



    }

} // namespace space_shooter::ecs
