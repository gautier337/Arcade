/*
** EPITECH PROJECT, 2023
** NCursesWindow
** File description:
** NCursesWindow
*/

#include "../include/NCursesWindow.hpp"
#include <curses.h>

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
        if (key == 'x' || key == 'X')
            return Display::KeyType::X;
        if (key == 'a' || key == 'A')
            return Display::KeyType::A;
        if (key == 'b' || key == 'B')
            return Display::KeyType::B;
        if (key == 'c' || key == 'C')
            return Display::KeyType::C;
        if (key == 'd' || key == 'D')
            return Display::KeyType::D;
        if (key == 'e' || key == 'E')
            return Display::KeyType::E;
        if (key == 'f' || key == 'F')
            return Display::KeyType::F;
        if (key == 'g' || key == 'G')
            return Display::KeyType::G;
        if (key == 'h' || key == 'H')
            return Display::KeyType::H;
        if (key == 'i' || key == 'I')
            return Display::KeyType::I;
        if (key == 'j' || key == 'J')
            return Display::KeyType::J;
        if (key == 'k' || key == 'K')
            return Display::KeyType::K;
        if (key == 'l' || key == 'L')
            return Display::KeyType::L;
        if (key == 'm' || key == 'M')   
            return Display::KeyType::M;
        if (key == 'n' || key == 'N')   
            return Display::KeyType::N;
        if (key == 'o' || key == 'O')
            return Display::KeyType::O;
        if (key == 'p' || key == 'P')
            return Display::KeyType::P;
        if (key == 'q' || key == 'Q')
            return Display::KeyType::Q;
        if (key == 'r' || key == 'R')
            return Display::KeyType::R;
        if (key == 's' || key == 'S')
            return Display::KeyType::S;
        if (key == 't' || key == 'T')
            return Display::KeyType::T;
        if (key == 'u' || key == 'U')
            return Display::KeyType::U;
        if (key == 'v' || key == 'V')
            return Display::KeyType::V;
        if (key == 'w' || key == 'W')
            return Display::KeyType::W;
        if (key == 'x' || key == 'X')
            return Display::KeyType::X;
        if (key == 'y' || key == 'Y')
            return Display::KeyType::Y;
        if (key == 'z' || key == 'Z')
            return Display::KeyType::Z;
        if (key == KEY_BACKSPACE)
            return Display::KeyType::Backspace;
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
