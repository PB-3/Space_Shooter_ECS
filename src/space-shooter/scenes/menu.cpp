#include <space-shooter/scenes/menu.hpp>
#include <space-shooter/ecs/ecs.hpp>
#include <iostream>


namespace space_shooter {

	void Menu(ecs::Manager& manager) {

		manager.gameState().switch_to_scene = GameState::Scene::Menu;

		manager.registerSystem<ecs::RenderingSystem>();
		manager.registerSystem<ecs::InputSystem>();
		manager.registerSystem<ecs::SceneSystem>();

		manager.registerEntity<ecs::SceneEntity>();
		
		
		//Background
		std::filesystem::path texture_background;
		texture_background = manager.gameState().config.path_to_textures / "fd_solary_3.jpg";
		std::cout << texture_background << std::endl;
		manager.registerEntity<ecs::BackgroundEntity>(texture_background, 900, 900);

		manager.gameState().switch_to_scene = GameState::Scene::None;

	}
} // namespace space_shooter
