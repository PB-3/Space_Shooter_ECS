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

    void RenderingSystem::update(const sf::Time& /*delta_time*/,
        std::vector<Entity*>& entities,
        Manager& manager) {
        for (auto e : entities) {
            assert(hasRequiredComponents(*e));

            const auto& pos = e->get<PositionComponent>();
            const auto& spr = e->get<SpriteComponent>();
            auto& tex = e->get<TextureComponent>();

            // Charger la texture si nécessaire
            if (!tex.loaded) {
                if (!tex.texture.loadFromFile(tex.texture_path.string())) {
                    std::cerr << "Erreur de chargement de la texture : " << tex.texture_path.string() << std::endl;
                    continue;
                }
                tex.texture.setRepeated(tex.repeated);
                tex.loaded = true;
            }

            // Construire le sprite SFML pour rendre la texture
            sf::Sprite sprite;
            sprite.setTexture(tex.texture);
            sprite.setPosition(sf::Vector2f(pos.x, pos.y));
            sprite.setScale(spr.width / static_cast<float>(tex.texture.getSize().x),
                spr.height / static_cast<float>(tex.texture.getSize().y));

            // Rendre le sprite à la position correcte
            manager.gameState().rendering_window->draw(sprite);
        }
    }

} // namespace space_shooter::ecs
