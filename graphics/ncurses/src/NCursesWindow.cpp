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

void Display::NCursesWindow::clear()
{
    wclear(this->window);
}

Display::KeyType Display::NCursesWindow::getEvent()
{
    int key = getch();
    if (key != ERR) {
        if (key == 'x' || key == 'X') {
            this->close();
            return Display::KeyType::X;
        }
        if (key == 'Z' || key == 'z')
            return Display::KeyType::Z;
        if (key == 'S' || key == 's')
            return Display::KeyType::S;
        if (key == 'Q' || key == 'q')
            return Display::KeyType::Q;
        if (key == 'D' || key == 'd')
            return Display::KeyType::D;
    }
    return Display::KeyType::Unknown;
}

bool Display::NCursesWindow::isOpen()
{
    if (this->window == nullptr)
        return false;
    return true;
}

void Display::NCursesWindow::drawCharacter(int x, int y, char character)
{
    mvaddch(y, x, character);
}

void Display::NCursesWindow::draw()
{
    drawCharacter(1, 1, 'S');
}

void Display::NCursesWindow::display()
{
    wrefresh(this->window);
}

void Display::NCursesWindow::close()
{
    if (this->window != nullptr)
        delwin(this->window);
    endwin();
}

void Display::NCursesWindow::setTitle(std::string const &title)
{
    std::cout << "test title:" << title << std::endl;
}

std::string Display::NCursesWindow::getTitle()
{
    return "";
}

Display::NCursesWindow::NCursesWindow()
{
    return;
}

Display::NCursesWindow::~NCursesWindow()
{
    return;
}

extern "C" std::unique_ptr<Display::IWindow> createWindow()
{
    return std::make_unique<Display::NCursesWindow>();
}
