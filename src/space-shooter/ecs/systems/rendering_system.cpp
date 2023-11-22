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
        : System(type_list<TextureComponent, PositionComponent, SpriteComponent>{}) {}

    void RenderingSystem::update(const sf::Time& delta_time, std::vector<Entity*>& entities, Manager& manager)
    {
        for (auto e : entities) {
            assert(hasRequiredComponents(*e));

            const auto& pos = e->get<PositionComponent>();
            const auto& spr = e->get<SpriteComponent>();
            auto& tex = e->get<TextureComponent>();

            // TODO load texture (if needed) into the texture component
            // TODO then set boolean of component to true

            // TODO build SFML sprite to render the texture
            // TODO render the sprite at the correct position via manager -> game state
            // -> rendering window -> draw

            if (!tex.loaded)
            {
                if (tex.texture.loadFromFile(tex.texture_path.string()))
                {
                    tex.loaded = true;
                    //tex.texture.setRepeated(tex.repeated);
                }
                else
                {
                    std::cerr << "Probleme texture : " << tex.texture_path.string() << std::endl;
                }
            }
            
            sf::Sprite sprite;
            sprite.setTexture(tex.texture);
            sprite.setPosition(pos.x, pos.y);
            
            sprite.setTextureRect(sf::IntRect(0, 0, spr.width, spr.height));
            //if (spr.resize == SpriteComponent::Resize::Scale)
            //{
            //    sprite.setScale(spr.size, spr.size); // adapte à la size donnée
            //}

            manager.gameState().rendering_window->draw(sprite);
        }
    }

} // namespace space_shooter::ecs