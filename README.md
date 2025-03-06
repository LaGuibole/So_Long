so_long - Pac-Man Edition

🟡 Présentation

Ce projet est une implémentation du jeu Pac-Man dans le cadre du projet so_long de l'école 42. Il a été développé en C avec la MiniLibX et propose une version revisitée du célèbre jeu d'arcade, où le joueur contrôle Pac-Man à travers un labyrinthe en collectant des pac-gommes et en évitant les fantômes.

🎮 Fonctionnalités principales

Animation fluide de Pac-Man avec 3 sprites par direction.

Animation de mastication même à l'arrêt.

Déplacement des ennemis inspiré des fantômes de Pac-Man, avec un mouvement aléatoire.

Gestion des collisions : si Pac-Man touche un ennemi, il meurt.

Lecture d'une carte au format .ber, permettant de personnaliser les niveaux.

Aucune fuite mémoire (validé par Valgrind et tests rigoureux).

⚙️ Installation et compilation

Prérequis

Un environnement Unix/Linux ou macOS.

La MiniLibX installée.

Un compilateur C (gcc ou clang).

Compilation

make

Cela génère un exécutable so_long.

📜 Utilisation

Lancement du jeu

./so_long maps/map1.ber

Remplace map1.ber par n'importe quelle carte compatible.

Commandes du jeu

Touche

Action

W / ↑

Aller en haut

A / ←

Aller à gauche

S / ↓

Aller en bas

D / →

Aller à droite

ESC

Quitter le jeu

🖼️ Visuels

(Ajoute ici des images ou des GIFs montrant le gameplay et les animations)

💡 Aspects techniques

MiniLibX utilisée pour l'affichage et la gestion des événements.

Chargement des sprites en XPM.

Animation basée sur un compteur de frames pour un rendu fluide.

Pas de structure dédiée aux ennemis, ils sont gérés directement dans la structure principale du jeu.

📜 Licence

Ce projet a été réalisé dans le cadre de l'école 42. Libre à vous de l'explorer et de le modifier !

🚀 Auteur

Guillaume (La Guibole) - GitHub
