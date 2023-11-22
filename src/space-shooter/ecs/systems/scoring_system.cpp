#include <space-shooter/ecs/systems/scoring_system.hpp>

#include <space-shooter/ecs/components/cooldown_component.hpp>
#include <space-shooter/ecs/components/tag_component.hpp>
#include <space-shooter/ecs/components/health_component.hpp>
#include <space-shooter/ecs/components/score_component.hpp>

#include <space-shooter/ecs/entities/score_display.hpp>

#include <space-shooter/ecs/manager.hpp>
#include <space-shooter/game_state.hpp>
#include <space-shooter/utils.hpp>

#include <SFML/Graphics.hpp>

#include <cassert>
#include <iostream>

namespace space_shooter::ecs {

    ScoringSystem::ScoringSystem()
        : System{
              type_list<HealthComponent,TagComponent>{} } {}

    void ScoringSystem::update(const sf::Time& delta_time,
        std::vector<Entity*>& entities, Manager& manager) {


        for (auto e : entities) {
            assert(hasRequiredComponents(*e));
          

            auto& hp = e->get<HealthComponent>();
            const auto& tag = e->get<TagComponent>();

            if (hp.health <= 0 && tag.TagName == "EnemyShip")
            {
                    manager.sendToEntity<ScoreDisplayEntity>([&](auto &score_) {
                        auto& scoree = score_.get<ScoreComponent>();
                        scoree.score += 10;
                        
                        
                    });
                
            }
        }
    }

} // namespace space_shooter::ecs
