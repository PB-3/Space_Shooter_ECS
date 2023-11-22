
#include <space-shooter/ecs/manager.hpp>
#include <space-shooter/scenes/score.hpp>

#include <space-shooter/ecs/ecs.hpp>
#include <iostream>

namespace space_shooter
{

	void Score(space_shooter::ecs::Manager& manager)
	{
		manager.registerSystem<ecs::RenderingSystem>();
		manager.registerSystem<ecs::InputSystem>();
		manager.registerSystem<ecs::SceneSystem>();
		manager.registerEntity<ecs::SceneEntity>();


		//Background
		std::filesystem::path texture_background;
		texture_background = manager.gameState().config.path_to_textures / "victory.jpg";
		manager.registerEntity<ecs::BackgroundEntity>(texture_background, 900, 900);

		





	


		manager.gameState().switch_to_scene = GameState::Scene::None;
	}

}
