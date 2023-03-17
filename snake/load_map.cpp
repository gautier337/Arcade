#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <ncurses.h>

std::vector<std::string> load_2d_arr_from_file(const std::string &filepath)
{
    std::ifstream file(filepath);
    if (!file)
        return {};
    std::vector<std::string> array;
    std::string line = "";

    while (std::getline(file, line))
        array.push_back(line);
    return array;
}

std::pair<int, int> find_snake_position(const std::vector<std::string> &map)
{
    if (map.empty())
        return std::make_pair(-1, -1);
    for (size_t i = 0; i != map.size(); i++) {
        for (size_t j = 0; j != map[i].length(); j++) {
            if (map[i][j] == 'S') {
                return std::make_pair(i + 1, j + 1);
            }
        }
    }
    return std::make_pair(-1, -1);
}

void display_map(const std::vector<std::string>& map) {
    int max_y, max_x;
    getmaxyx(stdscr, max_y, max_x);
    int row_offset = (max_y - map.size()) / 2;
    int col_offset = (max_x - map[0].length()) / 2;

    for (size_t i = 0; i < map.size(); i++)
        for (size_t j = 0; j < map[i].length(); j++)
            mvprintw(i + row_offset, j + col_offset, "%c", map[i][j]);
    refresh();
}

void init_game(const std::vector<std::string> &map) {
    int input = 0;

    initscr();
    raw();
    keypad(stdscr, TRUE);
    noecho();
    while (1) {
        display_map(map);
        input = getch();
        if (input == 'q')
            break;
    }
    endwin();
}

int main(int argc, char **argv)
{
    if (argc != 2)
        return 84;
    std::vector<std::string> map = load_2d_arr_from_file(argv[1]);

    init_game(map);
    return 0;
}
