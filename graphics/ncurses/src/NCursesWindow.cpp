/*
** EPITECH PROJECT, 2023
** NCursesWindow
** File description:
** NCursesWindow
*/

#include "../include/NCursesWindow.hpp"
#include <iostream>

Display::NCursesWindow::NCursesWindow()
{
    std::cout << "NCursesWindow constructor called" << std::endl;
}

Display::NCursesWindow::~NCursesWindow()
{
    std::cout << "NCursesWindow destructor called" << std::endl;
}

void Display::NCursesWindow::create(std::string const &title, int framerateLimit, int width, int height)
{
    std::cout << "NCursesWindow create function called" << std::endl;
}

void Display::NCursesWindow::clear()
{
    ::clear(); // Utiliser l'opérateur de résolution de portée pour éviter la confusion avec la fonction membre clear()
}

extern "C"
{
    Display::NCursesWindow *create() {
        return new Display::NCursesWindow();
    };
}

extern "C"
{
    void destroy(Display::NCursesWindow *NCursesWindow) {
        delete NCursesWindow;
    };
}
