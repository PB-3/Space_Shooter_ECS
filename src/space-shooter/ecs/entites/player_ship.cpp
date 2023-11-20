#include <space-shooter/ecs/entities/player_ship.hpp>

#include <space-shooter/ecs/components/all.hpp>

#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/Time.hpp>

namespace space_shooter::ecs {


PlayerShipEntity::PlayerShipEntity(sf::Vector2f pos,
                                   const std::filesystem::path &texture_path,
                                   sf::Vector2f velocity) {
  add<PositionComponent>(pos.x, pos.y);
  add<InputComponent>();
  add<TextureComponent>(texture_path);
  add<SpriteComponent>(50, 20, SpriteComponent::Resize::Scale);
  add<VelocityComponent>(velocity.x, velocity.y);
  add<CooldownComponent>(sf::seconds(1));
  add<ClockComponent>();
  add<HealthComponent>(100);
  add<TagComponent>("PlayerShip");
 


}

} // namespace space_shooter::ecs
