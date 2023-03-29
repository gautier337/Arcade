/*
** EPITECH PROJECT, 2023
** Snake
** File description:
** Snake
*/

#include <iostream>
#include "../include/Snake.hpp"
#include <unistd.h>

Snake::Snake()
{
    std::cout << "Snake constructor called" << std::endl;
}

Snake::~Snake()
{
    std::cout << "Snake game destroyed" << std::endl;
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

std::vector<std::string> Snake::load_2d_arr_from_file(const std::string &filepath)
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

void Snake::init(std::unique_ptr<Display::IWindow> &window)
{
    _window = std::move(window);
    _window->create("test", 60, 800, 400);
    updateGame();
    return;
}

void Snake::moveSnake(std::string direction)
{
    std::pair<int, int> snake_pos = find_snake_position(_map);

    int new_row = snake_pos.first;
    int new_col = snake_pos.second;

    if (direction == "UP") {
        new_row -= 1;
    } else if (direction == "DOWN") {
        new_row += 1;
    } else if (direction == "LEFT") {
        new_col -= 1;
    } else if (direction == "RIGHT") {
        new_col += 1;
    }

    _map[new_row][new_col] = 'S';
    _map[snake_pos.first][snake_pos.second] = ' ';
}

void Snake::updateGame()
{
    _map = load_2d_arr_from_file("map/map");
    std::pair<int, int> snake_pos = find_snake_position(_map);
    if (check_errors(_map, snake_pos) == 84)
        return;
    while (1) {
        _window->clear();
        Display::KeyType key = _window->getEvent();
        if (key == Display::KeyType::X)
            break;
        if (key == Display::KeyType::Z) {
            moveSnake("UP");
        }
        if (key == Display::KeyType::S) {
            moveSnake("DOWN");
        }
        if (key == Display::KeyType::Q) {
            moveSnake("LEFT");
        }
        if (key == Display::KeyType::D) {
            moveSnake("RIGHT");
        }
        for (size_t i = 0; i != _map.size(); i++)
            for (size_t j = 0; j != _map[i].length(); j++)
                _window->drawCharacter(j, i, _map[i][j]);
        _window->display();
    }
    stop();
}

void Snake::stop()
{
    std::cout << "Snake game stopped" << std::endl;
}

extern "C" std::unique_ptr<IGameModule> createGame() {
    return std::make_unique<Snake>();
}
