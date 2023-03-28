/*
** EPITECH PROJECT, 2023
** NCursesWindow
** File description:
** NCursesWindow
*/

#include "../include/NCursesWindow.hpp"

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
    getmaxyx(stdscr, winHeight, winWidth);
    initscr();
    noecho();
    raw();
    keypad(stdscr, TRUE);
    nodelay(stdscr, TRUE);
    // std::vector<std::string> map = load_2d_arr_from_file("map/map");
    int startX = (winWidth - map[0].size()) / 2;
    int startY = (winHeight - map.size()) / 2;
    while (1) {
        clear();
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
