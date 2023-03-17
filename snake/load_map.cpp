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
    for (size_t i = 0; i != map.size(); i++) 
        for (size_t j = 0; j != map[i].length(); j++)
            if (map[i][j] == 'S')
                return std::make_pair(i + 1, j + 1);
    return std::make_pair(-1, -1);
}

void display_map(const std::vector<std::string> &map)
{
    int max_y, max_x = 0;
    getmaxyx(stdscr, max_y, max_x);
    int row_offset = (max_y - map.size()) / 2;
    int col_offset = (max_x - map[0].length()) / 2;
    int color_pair_number = 0;
    char display_char = ' ';

    for (size_t i = 0; i < map.size(); i++) {
        for (size_t j = 0; j < map[i].length(); j++) {
            switch (map[i][j]) {
                case '#':
                    color_pair_number = 1;
                    break;
                case 'S':
                    color_pair_number = 2;
                    break;
                case 'G':
                    color_pair_number = 3;
                    break;
                case ' ':
                    color_pair_number = 4;
                    display_char = ' ';
                    break;
                default:
                    continue;
            }
            attron(COLOR_PAIR(color_pair_number));
            mvprintw(i + row_offset, j + col_offset, "%c", display_char);
            attroff(COLOR_PAIR(color_pair_number));
        }
    }
    refresh();
}

void init_game(const std::vector<std::string> &map)
{
    int input = 0;

    initscr();
    raw();
    keypad(stdscr, TRUE);
    noecho();
    if (has_colors()) {
        start_color();
        init_pair(1, COLOR_BLUE, COLOR_BLUE);
        init_pair(2, COLOR_GREEN, COLOR_GREEN);
        init_pair(3, COLOR_RED, COLOR_RED);
        init_pair(4, COLOR_YELLOW, COLOR_YELLOW);
    }
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
