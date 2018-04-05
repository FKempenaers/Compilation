# Compilation

Généralités
***********

On a une tour en 3D composée d’étages, dans laquelle on peut passer de l’un à l’autre grâce à des montées et/ou descentes. 
Le but est de monter au sommet de la tour.

La vue est en 3eme personne, par rapport à la tête du serpent.
On a des ennemis qui se génèrent aléatoirement dans l’étage (des IA).

On se déplace sur un seul étage à la fois.
Les étages sont générés aléatoirement, mais doivent être constitués de manière à ce qu’on puisse monter à l’étage supérieur.
Il y a une mini-carte de l’étage avec indication de la sortie, et curseur du serpent. Et peut-être les ennemis.

Direction du serpent donné avec le curseur de la souris, déplacement continu vers l'avant.
L'angle de déplacement est donné par la position du curseur, à gauche ou à droite du milieu de l'écran.
En cas de collision avec un mur, le serpent glisse le long du mur et aucun dégât n'est infligé.

Collision avec le serpent lui-même, diminuton du serpent selon la partie dans laquelle il est rentré.
Collision avec un ennemi, coupure du serpent à la partie touchée.
Possibilité de récupérer de la vie en mangeant des trucs au sol (augmentation de la taille du serpent).

Les entrées d'étages sont TOUJOURS en bas à gauche et les sorties sont TOUJOURS en haut à droite.
Lors d'une montée d'étage, le serpent prend la pente, ellipse, on est passé à l'étage du dessus et on voit le serpent monter la fin de la pente.

Fonctionnalités supplémentaires : 
  - Défense contre les ennemis (tir de projectiles, invincibilité, ...),
  - Sprint avec un cooldown,
  - Effets visuels sur les tirs, 
  - Textures / effets de lumière,
  - Sauvegarde, tableau des scores, timer,
  - D’autres obstacles (dalles piégées : tu prends des dégâts, ou tu retombes d’un étage, par ex),
  - Menu de jeu.  
  
Détails de l'implémentation
***************************

Entités :
  - Position du serpent joueur en variable globale.
  - Les boules font une case de diamètre.
  - Le serpent du joueur doit faire AU MOINS 2 boules de longueur, sinon il meurt.

Carte :
  - Points des limitations (xmin, xmax, ymin, ymax) d'un objet (mur, rampe haute ou rampe basse) dans un tableau.
  - Tableau en 2 dimensions, contenant un code pour les obstacles et les ennemis.
  - Les murs ont une épaisseur, ie, ils ne prennent pas une case en entier lors de la visualisation MAIS ils sont codés sur toutes les cases de la carte qu'ils travèrsent.
 
 Ennemis :
  - Tableau contenant toutes les boules composant les serpents ennemis, identificateur par serpent, en même temps que les coordonées en x et en y.
