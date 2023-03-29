/*
** EPITECH PROJECT, 2023
** NCursesWindow
** File description:
** NCursesWindow
*/

#include "../include/NCursesWindow.hpp"

void Display::NCursesWindow::create(std::string const &title, int framerateLimit, int width, int height)
{
    int winWidth, winHeight = 0;
    getmaxyx(stdscr, winHeight, winWidth);
    initscr();
    noecho();
    raw();
    keypad(stdscr, TRUE);
    nodelay(stdscr, TRUE);
    this->window = newwin(height, width, (winHeight - height) / 2, (winWidth - width) / 2);
    this->title = title;
    this->width = width;
    this->height = height;
    this->framerateLimit = framerateLimit;
}

Display::NCursesWindow::NCursesWindow()
{
    return;
}

Display::NCursesWindow::~NCursesWindow()
{
    return;
}

void Display::NCursesWindow::clear()
{
    std::cout << "NCursesWindow clear called" << std::endl;
    return;
}

std::unique_ptr<Display::IEvent> Display::NCursesWindow::getEvent()
{
    return nullptr;
}

std::string Display::NCursesWindow::getTitle()
{
    return "";
}

void Display::NCursesWindow::setTitle(std::string const &title)
{
    std::cout << "test title:" << title << std::endl;
}

bool Display::NCursesWindow::isOpen()
{
    return true;
}

void Display::NCursesWindow::draw()
{
}

void Display::NCursesWindow::display()
{
}

void Display::NCursesWindow::close()
{
}

extern "C" std::unique_ptr<Display::IWindow> createWindow() {
    return std::make_unique<Display::NCursesWindow>();
}
