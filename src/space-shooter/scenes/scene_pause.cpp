#include <space-shooter/scenes/scene_pause.hpp>
#include <space-shooter/ecs/ecs.hpp>
#include <iostream>

#include <SFML/Graphics.hpp>

namespace space_shooter {

	void Pause(ecs::Manager& manager) {

		//manager.gameState().switch_to_scene = GameState::Scene::Pause;

		manager.registerSystem<ecs::RenderingSystem>();
		manager.registerSystem<ecs::InputSystem>();
		manager.registerSystem<ecs::SwitchToPauseMenuSystem>();

		manager.registerEntity<ecs::PauseMenuEntity>();
		//Background
		std::filesystem::path texture_background;
		texture_background = manager.gameState().config.path_to_textures / "missile.png";
		std::cout << texture_background << std::endl;
		manager.registerEntity<ecs::BackgroundEntity>(texture_background, 900, 900);

		

	//	manager.gameState().switch_to_scene = GameState::Scene::None;

	}
} // namespace space_shooter
