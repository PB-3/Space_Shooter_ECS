3..4 Scene Changing Feature (2-3pts)

Pour implementer le changement de scene j'ai crée un nouveau systeme qui va gérer les scenes
en fonction d'une input pour changer la scene pour l'instant j'ai mis des touches de clavier
on verra par la suite. les transitions de scenes ne sont pas des mouvements donc j'ai mis ça
dans un autre systeme. techniquement ça se rapproche du rendering vu que l'on change ce que 
l'on souhaite afficher à l'écran mais bon je sais pas trop.

4..2 Shooting Feature for PlayerShip (2pts)

Création d'une entité missile, il faut utiliser un tag componenent "PlayerMissile" afin de 
pouvoir le detecter dans le mouvement system afin de performer le déplacement du missile.
D'abord l'input system detecte qu'on veut tirer puis il met l'input.shooting a true et 
ensuite le shooting system va créer un missile le register dans le manager puis le mouvement
system va déplacer le missile.


4..3 Cooldown Between Missile Shots (2pts)

Pour les cooldowns on a cree un cd component qui contient le cd max et le cd en cours
ensuite il y a un clock system qui gère tant que le cd est pas à 0 il decrease le cd
ensuite il le met a zero a la fin. si le cd est à Zero on peut créer un missile et on mets le
cd à Zero. ce cooldown component est dans le PlayerShip.

j'ai également rajouté le clock system qui permet de gérer les updates etc

4.a Enemy Ship Spawner (2pts)
 création d'un spawner qui fait spawn des ennemis en haut pr l'instant rien ne se passe ça fait
 juste apparaitre des ennemis. 