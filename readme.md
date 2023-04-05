Arcade - Plateforme de jeux

Description:

    Arcade est une plateforme de jeux qui permet à l'utilisateur de choisir un jeu depuis un menu.
    Le projet est développé en C++ et utilise des bibliothèques dynamiques pour les jeux et les interfaces graphiques.

Configuration requise:

    Compilateur : g++ (supportant le standard C++11)
    Bibliothèques : SFML, nCurses, SDL2

Pour compiler le projet, utilisez le makefile :

    Makefile
        Exécutez la commande suivante dans le terminal :
        make

Utilisation:

    Lancez le programme en spécifiant la bibliothèque graphique à utiliser au démarrage. Par exemple:
        ./arcade ./lib/arcade_sfml.so

Fonctionnalités:

    - Choix du jeu parmi les jeux disponibles dans le répertoire ./lib/
    - Choix de la bibliothèque graphique parmi celles disponibles dans le répertoire ./lib/
    - Affichage des scores
    - Entrée du nom d'utilisateur
    - Changement de la bibliothèque graphique à la volée
    - Mappage des touches pour différentes actions (changer de jeu, redémarrer le jeu, revenir au menu, quitter)
    - Bibliothèques graphiques

    Le projet inclut les bibliothèques graphiques suivantes :

        SFML (arcade_sfml.so)
        nCurses (arcade_ncurses.so)
        SDL2 (arcade_sdl2.so)
        Jeux inclus

    Voici la liste des touches:

        Touche 'E' pour lancer un jeu depuis le menu
        Touche 'R' pour redémarrer le jeu
        Touche 'X' pour revenir au menu ou quitter le menu
        Touche 'P' pour changer de librairie graphique pendant le jeu ou le menu
        Touche 'Q' pour quitter le programme depuis le jeu sans revenir au menu

Le projet inclut les jeux suivants :

    Snake (arcade_snake.so)
    Nibbler (arcade_nibbler.so)
