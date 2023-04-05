Arcade - Plateforme de jeux rétro

Description
Arcade est une plateforme de jeux rétro qui permet à l'utilisateur de choisir un jeu et de conserver un registre des scores des joueurs. Le projet est développé en C++ et utilise des bibliothèques dynamiques pour les jeux et les interfaces graphiques.

Configuration requise
Système d'exploitation : Linux
Compilateur : g++ (supportant le standard C++11)
Bibliothèques : SFML, nCurses, SDL2
Compilation
Pour compiler le projet, utilisez Makefile ou CMake :

Makefile
Exécutez les commandes suivantes dans le terminal :

make all
CMake
Exécutez les commandes suivantes dans le terminal :

mkdir build
cd build
cmake ..
make
Utilisation
Lancez le programme en spécifiant la bibliothèque graphique à utiliser au démarrage. Par exemple :

./arcade ./lib/arcade_sfml.so
Fonctionnalités
Choix du jeu parmi les jeux disponibles dans le répertoire ./lib/
Choix de la bibliothèque graphique parmi celles disponibles dans le répertoire ./lib/
Affichage des scores
Entrée du nom d'utilisateur
Changement de la bibliothèque graphique à la volée
Mappage des touches pour différentes actions (changer de jeu, redémarrer le jeu, revenir au menu, quitter)
Bibliothèques graphiques
Le projet inclut les bibliothèques graphiques suivantes :

SFML (arcade_sfml.so)
nCurses (arcade_ncurses.so)
SDL2 (arcade_sdl2.so)
Jeux inclus
Le projet inclut les jeux suivants :

Snake (arcade_snake.so)
Nibbler (arcade_nibbler.so)