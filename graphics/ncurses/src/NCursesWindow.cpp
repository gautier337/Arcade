/*
** EPITECH PROJECT, 2023
** NCursesWindow
** File description:
** NCursesWindow
*/

#include "../include/NCursesWindow.hpp"

void Display::NCursesWindow::create(std::string const &title, int framerateLimit, int width, int height)
{
    initscr();
    raw();
    noecho();
    keypad(stdscr, TRUE);
    nodelay(stdscr, TRUE);
    start_color();
    curs_set(FALSE);
    init_pair(1, COLOR_RED, COLOR_RED);
    init_pair(2, COLOR_GREEN, COLOR_GREEN);
    init_pair(3, COLOR_BLUE, COLOR_BLUE);
    window = newwin(height, width, 0, 0);
    if (window == nullptr)
        throw std::runtime_error("Failed to create window");
    _title = title;
    width = width;
    height = height;
    framerateLimit = framerateLimit;
}

void Display::NCursesWindow::clear()
{
    wclear(window);
}

Display::KeyType Display::NCursesWindow::getEvent()
{
    int key = getch();
    if (key != ERR) {
        if (key == 'x' || key == 'X') {
            close();
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
        if (key == 'E' || key == 'e')
            return Display::KeyType::E;
        if (key == 'P' || key == 'p')
            return Display::KeyType::P;
        if (key == 'R' || key == 'r')
            return Display::KeyType::R;
    }
    return Display::KeyType::Unknown;
}

bool Display::NCursesWindow::isOpen()
{
    if (window == nullptr)
        return false;
    return true;
}

void Display::NCursesWindow::drawCharacter(int x, int y, char character)
{
    switch (character) {
        case 'P':
            wattron(window, COLOR_PAIR(1));
            mvwaddch(window, y, x, ' ');
            wattroff(window, COLOR_PAIR(1));
            break;
        case 'G':
            wattron(window, COLOR_PAIR(2));
            mvwaddch(window, y, x, ' ');
            wattroff(window, COLOR_PAIR(2));
            break;
        case '#':
            wattron(window, COLOR_PAIR(3));
            mvwaddch(window, y, x, ' ');
            wattroff(window, COLOR_PAIR(3));
            break;
        default:
            mvwaddch(window, y, x, character);
            break;
    }
}

void Display::NCursesWindow::display()
{
    wrefresh(window);
}

void Display::NCursesWindow::close()
{
    clear();
    if (window != nullptr) {
        delwin(window);
        window = nullptr;
    }
    endwin();
}

void Display::NCursesWindow::draw()
{
}

void Display::NCursesWindow::setTitle(std::string const &title)
{
    _title = title;
}

std::string Display::NCursesWindow::getTitle()
{
    return "";
}

Display::NCursesWindow::NCursesWindow() : window(nullptr)
{
}

Display::NCursesWindow::~NCursesWindow()
{
}

extern "C" std::unique_ptr<Display::NCursesWindow> createWindow()
{
    return std::make_unique<Display::NCursesWindow>();
}
