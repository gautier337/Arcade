/*
** EPITECH PROJECT, 2023
** NcursesDisplay
** File description:
** NcursesDisplay
*/

#include "../include/NcursesDisplay.hpp"
#include <iostream>

Display::NcursesDisplay::NcursesDisplay()
{
    std::cout << "NcursesDisplay constructor called" << std::endl;
}

Display::NcursesDisplay::~NcursesDisplay()
{
    destroy();
}

void Display::NcursesDisplay::create()
{
    std::cout << "NcursesDisplay create function called" << std::endl;
    // mainwin = initscr();
    // if (mainwin == nullptr) {
    //     fprintf(stderr, "Error: Failed to initialize ncurses screen.\n");
    //     exit(84);
    // }
    // raw();
    // keypad(mainwin, TRUE);
    // noecho();
    // curs_set(0);
    // timeout(0);
}

void Display::NcursesDisplay::update()
{
    // int ch = getch();
}

void Display::NcursesDisplay::destroy() {
    if (mainwin) {
        endwin();
    }
}

void Display::NcursesDisplay::clear()
{
    ::clear(); // Utiliser l'opérateur de résolution de portée pour éviter la confusion avec la fonction membre clear()
}

void Display::NcursesDisplay::draw(ISprite *sprite)
{
    // Récupérer la position et les dimensions du sprite
    // int y = sprite->getPosition().y;
    // int x = sprite->getPosition().x;
    // int width = sprite->getDimensions().x;
    // int height = sprite->getDimensions().y;

    // // Dessiner le sprite dans la fenêtre principale
    // for (int i = 0; i < height; i++) {
    //     for (int j = 0; j < width; j++) {
    //         mvwaddch(mainwin, y+i, x+j, sprite->getPixel(j, i));
    //     }
    // }
    sprite = sprite;
    refresh();
}

extern "C"
{
    Display::IDisplayModule *create() {
        return new Display::NcursesDisplay();
    };
}

extern "C"
{
    void destroy(Display::IDisplayModule *displayModule) {
        delete displayModule;
    };
}
