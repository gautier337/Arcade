#include <ncurses.h>
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <ncurses.h>
#include <stdexcept>

std::vector<std::string> load_2d_arr_from_file(const std::string &filepath)
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

void create (std::string const &title, int framerateLimit, int width, int height)
{
    std::cout << "NCursesWindow create called " << title << framerateLimit << width << height << std::endl;
    int winWidth, winHeight = 0;
    initscr();
    getmaxyx(stdscr, winHeight, winWidth);
    noecho();
    keypad(stdscr, TRUE);
    std::vector<std::string> map = load_2d_arr_from_file("map/map");
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

int main()
{
    create("test", 0, 0, 0);
    return 0;
}
