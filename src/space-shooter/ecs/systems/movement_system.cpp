#include <space-shooter/ecs/systems/movement_system.hpp>

#include <space-shooter/ecs/components/input_component.hpp>
#include <space-shooter/ecs/components/position_component.hpp>
#include <space-shooter/ecs/components/velocity_component.hpp>
#include <space-shooter/ecs/manager.hpp>
#include <space-shooter/game_state.hpp>
#include <space-shooter/utils.hpp>

#include <SFML/Graphics.hpp>

#include <cassert>
#include <iostream>

namespace space_shooter::ecs {

MovementSystem::MovementSystem()
    : System{
          type_list<VelocityComponent, PositionComponent, InputComponent>{}} {}

void MovementSystem::update(const sf::Time &delta_time,
                            std::vector<Entity *> &entities, Manager &manager) {


    for (auto e : entities) {
        assert(hasRequiredComponents(*e));

        const auto& vel = e->get<VelocityComponent>();
        auto& pos = e->get<PositionComponent>();
        const auto& input = e->get<InputComponent>();
        //update position coordinates depending on which input was triggered
        // the formula is simple : coord = coord +/- (velocity * deltatime)
        // the velocity needs to be > 100 to observe any significant change

        if (input.move_bottom) {
            if (pos.y > manager.gameState().height - 50)
                pos.y -= vel.vy * delta_time.asSeconds();
            pos.y = pos.y + (vel.vy * delta_time.asSeconds());

        }
        if (input.move_top) {
            if (pos.y < 5)
                pos.y += vel.vy * delta_time.asSeconds();
            pos.y = pos.y - (vel.vy * delta_time.asSeconds());

        }
        if (input.move_left) {
        if (pos.x < 5)
            pos.x += vel.vx * delta_time.asSeconds();
        pos.x = pos.x - (vel.vx * delta_time.asSeconds());

    }
    if (input.move_right) {
        if (pos.x > manager.gameState().width-50)
            pos.x -= vel.vx * delta_time.asSeconds();
    
        pos.x += vel.vx * delta_time.asSeconds();
    
    }
  }
}

} // namespace space_shooter::ecs
