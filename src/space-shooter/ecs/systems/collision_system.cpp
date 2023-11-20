#include <space-shooter/ecs/systems/collision_system.hpp>
#include <space-shooter/ecs/components/all.hpp>
#include <iostream>

namespace space_shooter::ecs {

    CollisionSystem::CollisionSystem()
        : System{ type_list<PositionComponent, SpriteComponent>() } { }

    void CollisionSystem::update(const sf::Time& delta_time, std::vector<Entity*>& entities, Manager& manager) {
        for (auto& entity1 : entities) {
            if (entity1->isAlive() && entity1->has<PositionComponent>() && entity1->has<SpriteComponent>() && entity1->has<TagComponent>()) {
                for (auto& entity2 : entities) {
                    if (entity1 != entity2 && entity2->isAlive() && entity2->has<PositionComponent>() && entity2->has<SpriteComponent>() && entity2->has<TagComponent>()) {
                        const auto& tag1 = entity1->get<TagComponent>();
                        const auto& tag2 = entity2->get<TagComponent>();

                        if ((tag1.TagName == "PlayerMissile" && tag2.TagName == "EnemyShip") ||
                            (tag1.TagName == "EnemyMissile" && tag2.TagName == "PlayerShip")) {
                            if (checkCollision(*entity1, *entity2)) {
                                entity1->kill();
                                applyDamage(entity1,entity2);
                                std::cout << "collision" << std::endl;
                            }

                        }
                    }
                }
            }
        }
    }

    bool CollisionSystem::checkCollision(Entity& entity1, Entity& entity2) {
        const auto& pos1 = entity1.get<PositionComponent>();
        const auto& sprite1 = entity1.get<SpriteComponent>();
        const auto& pos2 = entity2.get<PositionComponent>();
        const auto& sprite2 = entity2.get<SpriteComponent>();

        sf::FloatRect rect1(pos1.x, pos1.y, sprite1.width, sprite1.height);
        sf::FloatRect rect2(pos2.x, pos2.y, sprite2.width, sprite2.height);

        return rect1.intersects(rect2);
    }

   void CollisionSystem::applyDamage(Entity* missile, Entity* ship) {
       std::cout << missile->has<DamageComponent>() << ship->has<HealthComponent>() << std::endl;

        if (missile->has<DamageComponent>() && ship->has<HealthComponent>()) {
            auto& damage = missile->get<DamageComponent>();
            auto& health = ship->get<HealthComponent>();

            health.health -= damage.damage; // Réduire la santé du vaisseau ennemi
            std::cout << "Ship health after damage: " << health.health << std::endl; // Débogage de la santé
        }
    }

} // namespace space_shooter::ecs
