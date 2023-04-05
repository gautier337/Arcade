# Arcade - Games platform

# Description:

    Arcade is a game platform that allows the user to choose a game from a menu.
    The project is developed in C++ and uses dynamic libraries for games and graphical interfaces.

# Required configuration:

    Compiler: g++ (supporting the C++11 standard)
    Libraries: SFML, Ncurses, SDL2

# To compile the project, use the makefile:

    ## Makefile
        Run the following command in the terminal:
        make

# Usage:

    Launch the program specifying the graphics library to use at startup. For example:
        ./arcade ./lib/arcade_sfml.so

# Features:

    - Choice of the game among the games available in the directory ./lib/
    - Choice of the graphic library among those available in the ./lib/ directory
    - Display of scores
    - Username entry
    - Changing the graphics library on the fly
    - Key mapping for different actions (switch game, restart game, return to menu, exit)
    - Graphic libraries

    The project includes the following graphics libraries:

        SFML (arcade_sfml.so)
        nCurses (arcade_ncurses.so)
        SDL2 (arcade_sdl2.so)
        Games included

    Here is the list of keys in the menu:

        When you get to the menu if you press 'O' keys on the keyboard
        allow you to enter your nickname, if you press 'O' again
        keys will have the following functions:

        'E' key to launch a game from the menu
        'R' key to restart the game
        'X' key to return to the menu or exit the menu
        'P' key to change graphics library during game or menu
        'Q' key to exit the program from the game without returning to the menu
        'L' key to quit the program

    Here is the list of keys in the game:

        When you arrive in the game your control keys are as follows:

        'Z' key to go up
        'S' key to go down
        'Q' key to go left
        'D' key to go right
        'L' key to quit the program

# The project includes the following games:

    Snake (arcade_snake.so)
    Nibbler (arcade_nibbler.so)