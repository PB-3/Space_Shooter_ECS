#include <space-shooter/scenes/level.hpp>
#include <space-shooter/ecs/entities/player_ship.hpp>
#include <space-shooter/ecs/entities/player_missile.hpp>
#include <space-shooter/ecs/ecs.hpp>
#include <iostream>

namespace space_shooter {

void initLevel(ecs::Manager &manager) {
	
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
		manager.registerSystem<ecs::CleanKilledShipsSystem>();
		manager.registerSystem<ecs::CollisionSystem>();
		manager.registerSystem<ecs::ScoringSystem>();
		manager.registerSystem<ecs::SwitchToScoreMenuSystem>();
		manager.registerSystem<ecs::HealthBarDisplaySystem>();
		manager.registerSystem<ecs::AudioSystem>();
		manager.registerSystem<ecs::MusicSystem>();

		// Registering Entity

		//Scene 
		manager.registerEntity<ecs::SceneEntity>();

		// Level countdown
		manager.registerEntity<ecs::LevelTimerEntity>(sf::Time(sf::seconds(60)));

		//Display Score 
		manager.registerEntity<ecs::ScoreDisplayEntity>();

		//Audio background
		std::filesystem::path backgroundMusicPath;
		backgroundMusicPath = manager.gameState().config.path_to_audio / "background_music.mp3";
		manager.registerEntity<ecs::BackgroundMusic>(backgroundMusicPath.string());

		// Audio player shoot
		std::filesystem::path shootSoundPath = manager.gameState().config.path_to_audio / "player_shoot.wav";
		manager.registerEntity<ecs::SoundEffects>(shootSoundPath.string());


		//Background
		std::filesystem::path texture_background;
		texture_background = manager.gameState().config.path_to_textures / "solary.jpg";
		manager.registerEntity<ecs::BackgroundEntity>(texture_background, 900, 900);

		//PlayerShip
		sf::Vector2f pos(300, 300);
		sf::Vector2f velocity(150, 150);
		std::filesystem::path texture_path;
		texture_path = manager.gameState().config.path_to_textures / "shuttle.png";
		manager.registerEntity<ecs::PlayerShipEntity>(pos, texture_path, velocity);

		//Enemy Spawner
		sf::Vector2f EnemySpawnerPos(100, 50);
		std::filesystem::path texture_enemy;
		texture_enemy = manager.gameState().config.path_to_textures / "enemy.jpg";
		manager.registerEntity<ecs::EnemySpawnerEntity>(EnemySpawnerPos, texture_enemy);

		//HealthBar
		sf::Vector2f HealthBarPos(300, -150);
		std::filesystem::path texture_health_bar;
		texture_health_bar = manager.gameState().config.path_to_textures / "health_bar.png";
		manager.registerEntity<ecs::PlayerShipHealthBar>(HealthBarPos, texture_health_bar);

		// End Init Level
		manager.gameState().switch_to_scene = GameState::Scene::None;
	
}
} // namespace space_shooter
