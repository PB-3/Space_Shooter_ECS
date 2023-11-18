#include <space-shooter/ecs/systems/rendering_system.hpp>

#include <space-shooter/ecs/components/position_component.hpp>
#include <space-shooter/ecs/components/sprite_component.hpp>
#include <space-shooter/ecs/components/texture_component.hpp>
#include <space-shooter/ecs/manager.hpp>
#include <space-shooter/utils.hpp>

#include <SFML/Graphics.hpp>

#include <cassert>
#include <iostream>
namespace space_shooter::ecs {

RenderingSystem::RenderingSystem()
    : System(
          type_list<TextureComponent, PositionComponent, SpriteComponent>{}) {}

void RenderingSystem::update(const sf::Time &delta_time ,
                             std::vector<Entity *> &entities,
                             Manager &manager) {
  for (auto e : entities) {
    assert(hasRequiredComponents(*e));

    const auto &pos = e->get<PositionComponent>();
    const auto &spr = e->get<SpriteComponent>();
     auto &tex = e->get<TextureComponent>();


     if (!tex.loaded) {

         tex.texture.loadFromFile(tex.texture_path.string());
         tex.loaded = true;
         
        
     }
     sf::Sprite sp(tex.texture);
     sp.setPosition(pos.x, pos.y);
     manager.gameState().rendering_window->draw(sp);
    
  }
}

} // namespace space_shooter::ecs