#include <space-shooter/ecs/systems/switch_to_score_scene_system.hpp>
#include <space-shooter/scenes/scene_pause.hpp>

#include <space-shooter/ecs/components/tag_component.hpp>
#include <space-shooter/ecs/components/all.hpp>

#include <space-shooter/ecs/entities/background.hpp>


#include <space-shooter/ecs/system.hpp>
#include <space-shooter/ecs/manager.hpp>
#include <space-shooter/game_state.hpp>
#include <space-shooter/utils.hpp>

#include <SFML/Graphics.hpp>

#include <cassert>
#include <iostream>

namespace space_shooter::ecs {

    SwitchToScoreMenuSystem::SwitchToScoreMenuSystem()
        : System{
              type_list<TagComponent,HealthComponent>{} } {}

    void SwitchToScoreMenuSystem::update(const sf::Time& delta_time,
        std::vector<Entity*>& entities, Manager& manager) {


        for (auto e : entities) {
            assert(hasRequiredComponents(*e));

            auto& hp = e->get<HealthComponent>();
            const auto& tag = e->get<TagComponent>();

            if (tag.TagName == "EnemySpawner")
            {
                if (hp.health <= 0)
                {
                    manager.gameState().switch_to_scene = GameState::Scene::Score;
                }
            }
            // const auto& scene_input = e->get<SceneCompoenent>();

            
        }
    }

} // namespace space_shooter::ecs
