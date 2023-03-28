/*
** EPITECH PROJECT, 2023
** NCursesWindow
** File description:
** NCursesWindow
*/

#include "../include/NCursesWindow.hpp"

void Display::NCursesWindow::create(std::string const &title, int framerateLimit, int width, int height)
{
    std::cout << "NCursesWindow create called " << title << framerateLimit << width << height << std::endl;
    // int winWidth, winHeight = 0;
    // getmaxyx(stdscr, winHeight, winWidth);
    // initscr();
    // noecho();
    // raw();
    // keypad(stdscr, TRUE);
    // nodelay(stdscr, TRUE);
    // this->window = newwin(height, width, (winHeight - height) / 2, (winWidth - width) / 2);
    // this->title = title;
}

Display::NCursesWindow::NCursesWindow()
{
    return;
    // Implémentez le constructeur ici
}

Display::NCursesWindow::~NCursesWindow()
{
    return;
    // Implémentez le destructeur ici
}

void Display::NCursesWindow::clear()
{
    return;
    // Implémentez le clear ici
}

std::unique_ptr<Display::IEvent> Display::NCursesWindow::getEvent()
{
    // Implémentez la récupération des événements ici
    return nullptr;
}

std::string Display::NCursesWindow::getTitle()
{
    // Implémentez la récupération du titre ici
    return "";
}

void Display::NCursesWindow::setTitle(std::string const &title)
{
    std::cout << title;
    // Implémentez la modification du titre ici
}

bool Display::NCursesWindow::isOpen()
{
    // Implémentez la vérification pour savoir si la fenêtre est ouverte ici
    return true;
}

void Display::NCursesWindow::draw()
{
    return;
    // Implémentez le dessin ici
}

void Display::NCursesWindow::display()
{
    return;
    // Implémentez l'affichage ici
}

void Display::NCursesWindow::close()
{
    return;
    // Implémentez la fermeture de la fenêtre ici
}

extern "C" std::unique_ptr<Display::IWindow> createWindow() {
    return std::make_unique<Display::NCursesWindow>();
}
