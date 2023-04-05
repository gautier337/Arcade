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

### Project made by:

<div align="center" href="">
<table>
    <td align="center">
        <a href="https://github.com/Hugo-code-dev">
            <img src="https://avatars.githubusercontent.com/Hugo-code-dev" width="150px;" alt="Hugo DUBOIS profile picture"/>
            <br />
            <b>Hugo DUBOIS</b>
        </a>
        <br />
        <a href="mailto:hugo.dubois@epitech.eu">📧</a>
    </td>
    <td align="center">
        <a href="https://github.com/gautier337">
            <img src="https://avatars.githubusercontent.com/gautier337" width="150px;" alt="Gautier BONHUR profile picture"/>
            <br />
            <b>Gautier BONHUR</b>
        </a>
        <br />
        <a href="mailto:hugo.dubois@epitech.eu">📧</a>
    </td>
</table>

</div>

### In collaboration with:

<div align="center" href="">
<table>
    <td align="center">
        <a href="https://github.com/X-VINCENT">
            <img src="https://avatars.githubusercontent.com/X-VINCENT" width="100px;" alt="Xavier VINCENT profile picture"/>
            <br />
            <b>Xavier VINCENT</b>
        </a>
        <br />
        <div>
            <a href="https://github.com/EpitechPromo2026/B-OOP-400-BDX-4-1-arcade-max.peixoto/commits?author=X-VINCENT" title="Code">💻</a>
            <a href="mailto:xavier.vincent@epitech.eu">📧</a>
        </div>
    </td>
    <td align="center">
        <a href="https://github.com/MaxPeix">
            <img src="https://avatars.githubusercontent.com/MaxPeix" width="100px;" alt="Max PEIXOTO profile picture"/>
            <br />
            <b>Max PEIXOTO</b>
        </a>
        <br />
        <div>
            <a href="https://github.com/EpitechPromo2026/B-OOP-400-BDX-4-1-arcade-max.peixoto/commits?author=MaxPeix" title="Code">💻</a>
            <a href="mailto:max.peixoto.chhang@epitech.eu">📧</a>
        </div>
    </td>
    <td align="center">
        <a href="https://github.com/EpiDoubleHaxe">
            <img src="https://avatars.githubusercontent.com/EpiDoubleHaxe" width="100px;" alt="Edouard CHHANG profile picture"/>
            <br />
            <b>Edouard CHHANG</b>
        </a>
        <br />
        <div>
            <a href="https://github.com/EpitechPromo2026/B-OOP-400-BDX-4-1-arcade-max.peixoto/commits?author=EpiDoubleHaxe" title="Code">💻</a>
            <a href="mailto:edouard.chhang@epitech.eu">📧</a>
        </div>
    </td>
</table>

</div>