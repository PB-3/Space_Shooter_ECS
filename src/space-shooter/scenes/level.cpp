#include <space-shooter/scenes/level.hpp>
#include <space-shooter/ecs/entities/player_ship.hpp>
#include <space-shooter/ecs/entities/player_missile.hpp>
#include <space-shooter/ecs/entities/player_ship_healthbar.hpp>
#include <space-shooter/ecs/ecs.hpp>
#include <iostream>

namespace space_shooter {

void initLevel(ecs::Manager &manager) {
	
		std::cout << "initlevel\n";
		// Registering Systems
		manager.registerSystem<ecs::RenderingSystem>();
		manager.registerSystem<ecs::InputSystem>();
		manager.registerSystem<ecs::MovementSystem>();
		manager.registerSystem<ecs::SceneSystem>();
		manager.registerSystem<ecs::ClockSystem>();
		manager.registerSystem<ecs::ShootingSystem>();
		manager.registerSystem<ecs::EnemySystem>();
		manager.registerSystem<ecs::TimerSystem>();
		manager.registerSystem<ecs::TextRenderingSystem>();
		manager.registerSystem<ecs::EnemyChasingSystem>();
		manager.registerSystem<ecs::EnemyShootingSystem>();
	//	manager.registerSystem<ecs::SwitchToPauseMenuSystem>();
		manager.registerSystem<ecs::CleanKilledShipsSystem>();
		manager.registerSystem<ecs::CollisionSystem>();
		manager.registerSystem<ecs::HealthBarDisplaySystem>();
		manager.registerSystem<ecs::AudioSystem>();
		manager.registerSystem<ecs::MusicSystem>();

		// Registering Entity
		manager.registerEntity<ecs::SceneEntity>();
		manager.registerEntity<ecs::LevelTimerEntity>(sf::Time(sf::seconds(60)));
		manager.registerEntity<ecs::PauseMenuEntity>();


		//Background
		std::filesystem::path texture_background;
		texture_background = manager.gameState().config.path_to_textures / "solary.jpg";
		manager.registerEntity<ecs::BackgroundEntity>(texture_background, 900, 900);

		// Charger la musique de fond
		std::filesystem::path backgroundMusicPath = manager.gameState().config.path_to_audio / "background_music.mp3";
		manager.loadBackgroundMusic(backgroundMusicPath.string());

		// Jouer la musique de fond
		sf::Music& backgroundMusic = manager.getBackgroundMusic();
		backgroundMusic.play();

		//PlayerShip
		sf::Vector2f pos(300, 300);
		sf::Vector2f velocity(150, 150);
		std::filesystem::path texture_path;
		texture_path = manager.gameState().config.path_to_textures / "shuttle.png";
		manager.registerEntity<ecs::PlayerShipEntity>(pos, texture_path, velocity);

		//Health bar
		sf::Vector2f positionHealthBar(700, 0); // Position de la barre de santé
		float maxWidthHealthBar = 200; // Largeur maximale de la barre de santé
		manager.registerEntity<ecs::PlayerShipHealthBar>(positionHealthBar, maxWidthHealthBar);
		//std::cout << "PlayerShipHealthBar entity registered at position: " << positionHealthBar.x << ", " << positionHealthBar.y << " with width: " << maxWidthHealthBar << std::endl; 
		

		//Enemy Spawner
		sf::Vector2f EnemySpawnerPos(100, 50);
		std::filesystem::path texture_enemy;
		texture_enemy = manager.gameState().config.path_to_textures / "enemy.jpg";
		manager.registerEntity<ecs::EnemySpawnerEntity>(EnemySpawnerPos, texture_enemy);

		// End Init Level
		manager.gameState().switch_to_scene = GameState::Scene::None;
	
}
} // namespace space_shooter
