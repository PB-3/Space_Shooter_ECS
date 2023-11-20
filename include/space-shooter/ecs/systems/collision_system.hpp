#pragma once

#include <space-shooter/ecs/system.hpp>
#include <space-shooter/ecs/manager.hpp>
#include <SFML/System/Time.hpp>

namespace space_shooter::ecs {

    class CollisionSystem : public System {
    public:
        CollisionSystem();
        void update(const sf::Time& delta_time, std::vector<Entity*>& entities, Manager& manager) override;

    private:
        bool checkCollision(Entity& entity1, Entity& entity2);
        void applyDamage(Entity* missile, Entity* ship);
    };

} // namespace space_shooter::ecs