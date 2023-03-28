/*
** EPITECH PROJECT, 2023
** NCursesWindow
** File description:
** NCursesWindow
*/

#include "../include/NCursesWindow.hpp"

// Display::NCursesWindow::NCursesWindow()
// {
//     std::cout << "NCursesWindow constructor called" << std::endl;
// }

// Display::NCursesWindow::~NCursesWindow()
// {
//     std::cout << "NCursesWindow destructor called" << std::endl;
// }

std::vector<std::string> Display::NCursesWindow::load_2d_arr_from_file(const std::string &filepath)
{
    std::ifstream file(filepath);
    if (!file)
        return {};
    std::vector<std::string> array = {};
    std::string line = "";

    while (std::getline(file, line))
        array.push_back(line);
    return array;
}

void Display::NCursesWindow::create(std::string const &title, int framerateLimit, int width, int height)
{
    std::cout << "NCursesWindow create called " << title << framerateLimit << width << height << std::endl;
    int winWidth, winHeight = 0;
    initscr();
    getmaxyx(stdscr, winHeight, winWidth);
    noecho();
    keypad(stdscr, TRUE);
    std::vector<std::string> map = load_2d_arr_from_file("../../../map/map");
    if (map.empty()) {
        endwin();
        throw std::runtime_error("Erreur lors du chargement de la map");
    }
    int startX = (winWidth - map[0].size()) / 2;
    int startY = (winHeight - map.size()) / 2;
    while (1) {
        erase();
        for (size_t i = 0; i < map.size(); ++i)
            mvprintw(startY + i, startX, "%s", map[i].c_str());
        refresh();
        int ch = getch();
        if (ch == 'q' || ch == 'Q') {
            break;
        }
    }
    endwin();
}

int main()
{
    Display::NCursesWindow window;
    window.create("test", 60, 800, 400);
    return 0;
}

// void Display::NCursesWindow::clear()
// {
//     ::clear(); // Utiliser l'opérateur de résolution de portée pour éviter la confusion avec la fonction membre clear()
// }

// extern "C"
// {
//     Display::NCursesWindow *create() {
//         return new Display::NCursesWindow();
//     };
// }

// extern "C"
// {
//     void destroy(Display::NCursesWindow *NCursesWindow) {
//         delete NCursesWindow;
//     };
// }
