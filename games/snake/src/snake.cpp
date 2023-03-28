/*
** EPITECH PROJECT, 2023
** Snake
** File description:
** Snake
*/

#include <iostream>
#include "../include/Snake.hpp"

Snake::Snake()
{
    std::cout << "Snake constructor called" << std::endl;
}

Snake::~Snake()
{
    std::cout << "Snake game destroyed" << std::endl;
}

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

std::pair<int, int> Snake::find_snake_position(const std::vector<std::string> &map)
{
    if (map.empty())
        return std::make_pair(-1, -1);
    for (size_t i = 0; i != map.size(); i++) 
        for (size_t j = 0; j != map[i].length(); j++)
            if (map[i][j] == 'S')
                return std::make_pair(i, j);
    return std::make_pair(-1, -1);
}

int Snake::check_errors(const std::vector<std::string> &map, const std::pair<int, int> &snake_pos)
{
    if (map.empty())
        return 84;
    if (snake_pos.first == -1 || snake_pos.second == -1)
        return 84;
    return 0;
}

void Snake::init()
{
    return;
}

void Snake::updateGame()
{
    // Update game logic, handle input, etc.
}

void Snake::stop() {
    // Cleanup, release resources, etc.
}

extern "C" IGameModule *create()
{
    return new Snake();
}

extern "C" void destroy(IGameModule *game) {
    delete game;
}
