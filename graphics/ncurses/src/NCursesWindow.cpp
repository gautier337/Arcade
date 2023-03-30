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
    start_color();
    init_pair(1, COLOR_RED, COLOR_RED);
    init_pair(2, COLOR_GREEN, COLOR_GREEN);
    init_pair(3, COLOR_BLUE, COLOR_BLUE);
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
    switch (character) {
    case 'P':
        attron(COLOR_PAIR(1));
        mvaddch(y, x, ' ');
        attroff(COLOR_PAIR(1));
        break;
    case 'G':
        attron(COLOR_PAIR(2));
        mvaddch(y, x, ' ');
        attroff(COLOR_PAIR(2));
        break;
    case '#':
        attron(COLOR_PAIR(3));
        mvaddch(y, x, ' ');
        attroff(COLOR_PAIR(3));
        break;
    default:
        mvaddch(y, x, character);
        break;
    }
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

void Display::NCursesWindow::draw()
{
    drawCharacter(1, 1, 'P');
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
