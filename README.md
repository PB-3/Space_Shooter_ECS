# Space_Shooter_ECS

## Description du Projet

Le projet Space_Shooter_ECS a pour objectif de développer un jeu en utilisant le modèle entité,
composants, systèmes (ECS). Le jeu est un space shooter où le joueur contrôle un vaisseau spatial,
visant à éliminer les ennemis qui approchent. Les ennemis apparaissent depuis un spawner,
et le but ultime est de détruire ce spawner. Une fois le spawner détruit, le joueur remporte la partie.
Les ennemis tirent des missiles, et le joueur doit les éviter tout en pouvant également tirer des missiles pour détruire les vaisseaux ennemis et les spawners.

## Options Implémentées

### Menu Principal
- **Aller/Retourner au menu :** Appuyer sur M
- **Commencer le jeu :** Appuyer sur L
- **Quitter le jeu :** Appuyer sur Echap

### Commandes en Jeu
- **Tirer avec le vaisseau :** Appuyer sur Espace
- **Se déplacer avec le vaisseau :**
  - Z, Q, S, D ou flèches Haut, Gauche, Bas, Droite : Avancer, Aller à gauche, Reculer, Aller à droite
- ** Quiter le jeu : Appuyer sur Echap **

### Features ECS Implémentées

#### 3..1 Rendering Feature (4pts)
- Components : TextureComponent, PositionComponent, SpriteComponent
- Entities : Toutes les entités nécessitant une représentation visuelle à l'écran
- Systems : RenderingSystem

#### 3..2 Background Image Display (2pts)
- Components : TextureComponent
- Entities : BackgroundEntity
- Systems : RenderingSystem

#### 3..3 Moving Feature (4pts)
- Components : PositionComponent, VelocityComponent, InputComponent
- Entities : PlayerShip
- Systems : MovementSystem, InputSystem

#### 4..1 Tag Feature for Entities (2pts)
- Components : TagComponent
- Entities : Toutes les entités nécessitant une classification
- Systems : Tous les systèmes nécessitant cette balise (principalement le ColliderSystem)

#### 4..2 Shooting Feature for PlayerShip (2pts)
- Components : PositionComponent, VelocityComponent, TextureComponent, TagComponent
- Entities : PlayerShip, PlayerMissile
- Systems : ShootingSystem, MovementSystem, InputSystem

#### 4..3 Cooldown Between Missile Shots (2pts)
- Components : ClockComponent, CooldownComponent
- Entities : PlayerShip, Missile
- Systems : ClockSystem, ShootingSystem

#### 4.a Enemy Ship Spawner (2pts)
- Components : PositionComponent, CooldownComponent, ClockComponent, TextureComponent, TagComponent
- Entities : EnemyShip, EnemySpawner
- Systems : EnemySpawnSystem

#### 4.b Enemy Shooting System (2pts)
- Components : CooldownComponent, ClockComponent, PositionComponent, VelocityComponent, TextureComponent, TagComponent
- Entities : EnemyShip, Missile
- Systems : EnemyShootingSystem

#### 4.c Collider and Health/Damage System (4pts)
- Components : HealthComponent (vaissaux), DamageComponent (missile), TagComponent
- Entities : PlayerShip, EnemyShip, Missile
- Systems : CollisionSystem, CleanKilledShipsSystem

#### 4.d Enemy Movement/Chase Feature (2pts)
- Components : PositionComponent, VelocityComponent
- Entities : EnemyShip
- Systems : EnemyChasingSystem

#### 4.e Player Death Detection (2pts)
- Entities : PlayerShip
- Systems : Collider
- Core Code : GameState (pour gérer les changements de scène)

#### 4.f Health Bar Display (2pts)
- Components : HealthComponent, PositionComponent, TextureComponent, SpriteComponent
- Entities : PlayerShipHealthBar
- Systems : HealthBarDisplaySystem

#### 4.g Countdown Timer (2pts)
- Components : TimerComponent
- Entities : LevelTimer
- Systems : TimerSystem, TextRenderingSystem

#### 4.h Scoring Mechanism (2pts)
- Components : ScoreComponent
- Entities : ScoreDisplay
- Systems : ScoringSystem, SwitchToScoreSceneSystem

#### 4.j Audio Integration (2–4pts)
- Objectif : Ajouter des effets sonores et de la musique de fond pour améliorer le gameplay.
- Components : AudioComponent, MusicComponent
- Entities : BackgroundMusic, SoundEffects
- Systems : AudioSystem, MusicSystem

## Bugs Connus ou spécifications 

- Les changements de scènes sont toutes traités dans un seul fichier qui est scene_system  pour le changement de scène entre le menu et le jeu ou lorsque le joueur n'a plus de points de vie. 
