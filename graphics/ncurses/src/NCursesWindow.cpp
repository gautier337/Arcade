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
    this->window = newwin(height, width, 0, 0);
    if (this->window == nullptr)
        throw std::runtime_error("Failed to create window");
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
        if (key == 'E' || key == 'e')
            return Display::KeyType::E;
        if (key == 'P' || key == 'p')
            return Display::KeyType::P;
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
            wattron(this->window, COLOR_PAIR(1));
            mvwaddch(this->window, y, x, ' ');
            wattroff(this->window, COLOR_PAIR(1));
            break;
        case 'G':
            wattron(this->window, COLOR_PAIR(2));
            mvwaddch(this->window, y, x, ' ');
            wattroff(this->window, COLOR_PAIR(2));
            break;
        case '#':
            wattron(this->window, COLOR_PAIR(3));
            mvwaddch(this->window, y, x, ' ');
            wattroff(this->window, COLOR_PAIR(3));
            break;
        default:
            mvwaddch(this->window, y, x, character);
            break;
    }
}

void Display::NCursesWindow::display()
{
    wrefresh(this->window);
}

void Display::NCursesWindow::close()
{
    this->clear();
    if (this->window != nullptr) {
        delwin(this->window);
        this->window = nullptr;
    }
    endwin();
}

void Display::NCursesWindow::draw()
{
}

void Display::NCursesWindow::setTitle(std::string const &title)
{
    std::cout << "test title:" << title << std::endl;
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
