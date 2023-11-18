#include <space-shooter/scenes/level.hpp>
#include <space-shooter/ecs/entities/player_ship.hpp>
#include <space-shooter/ecs/entities/player_missile.hpp>
#include <space-shooter/ecs/ecs.hpp>
#include <iostream>

namespace space_shooter {

void initLevel(ecs::Manager &manager) {

  manager.gameState().switch_to_scene = GameState::Scene::Level;

  // Registering Systems
  manager.registerSystem<ecs::RenderingSystem>();
  manager.registerSystem<ecs::InputSystem>();
  manager.registerSystem<ecs::MovementSystem>();
  manager.registerSystem<ecs::SceneSystem>();
  manager.registerSystem<ecs::ClockSystem>();
  manager.registerSystem<ecs::ShootingSystem>();
  manager.registerSystem<ecs::EnemySystem>();

  // Registering Entity
  manager.registerEntity<ecs::SceneEntity>();



  //Background
  std::filesystem::path texture_background;
  texture_background = manager.gameState().config.path_to_textures / "solary.jpg";
  manager.registerEntity<ecs::BackgroundEntity>(texture_background, 900, 900);

  //PlayerShip
  sf::Vector2f pos(300, 300);
  sf::Vector2f velocity(150, 150);
  std::filesystem::path texture_path;
  texture_path = manager.gameState().config.path_to_textures / "shuttle.png";
  manager.registerEntity<ecs::PlayerShipEntity>(pos,texture_path,velocity);
  
  //Enemy Spawner
  sf::Vector2f EnemySpawnerPos(100, 50);
  std::filesystem::path texture_enemy;
  texture_enemy = manager.gameState().config.path_to_textures / "enemy.jpg";
  manager.registerEntity<ecs::EnemySpawnerEntity>(EnemySpawnerPos, texture_enemy);



  // End Init Level
  manager.gameState().switch_to_scene = GameState::Scene::None;

}
} // namespace space_shooter
