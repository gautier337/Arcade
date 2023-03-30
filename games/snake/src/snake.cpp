/*
** EPITECH PROJECT, 2023
** Snake
** File description:
** Snake
*/

#include "../include/Snake.hpp"
#include <unistd.h>
#include <chrono>
#include <thread>
#include <utility>
#include <memory>
#include <deque>
#include <random>

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

std::vector<std::string> Snake::load_map()
{
    std::vector<std::string> array = {
        "######################################",
        "#                                    #",
        "#           G                        #",
        "#                    G               #",
        "#     G                              #",
        "#                                    #",
        "#                       G            #",
        "#           G                        #",
        "#                                    #",
        "#     G             G                #",
        "#           S                        #",
        "#                    G               #",
        "#                                    #",
        "#       G             G              #",
        "#                                    #",
        "######################################"};

    return array;
}

bool Snake::check_wall_collision(const std::vector<std::string> &map, size_t row, size_t col)
{
    if (row >= map.size() || col >= map[row].length())
        return true;

    return map[row][col] == '#';
}

bool Snake::check_self_collision(int row, int col)
{
    for (const auto &part : _snake_body)
        if (part.first == row && part.second == col)
            return true;

    return false;
}

void Snake::init(std::unique_ptr<Display::IWindow> &window)
{
    _window = std::move(window);
    _window->create("test", 60, 800, 400);
    _snake_body.push_back(find_snake_position(load_map()));
    updateGame();
    return;
}

bool Snake::moveSnake(std::string direction)
{
    int row_offset = 0;
    int col_offset = 0;

    if (direction == "UP")
        row_offset = -1;
    else if (direction == "DOWN")
        row_offset = 1;
    else if (direction == "LEFT")
        col_offset = -1;
    else if (direction == "RIGHT")
        col_offset = 1;

    int new_row = _snake_body.front().first + row_offset;
    int new_col = _snake_body.front().second + col_offset;

    if (check_wall_collision(_map, new_row, new_col) || check_self_collision(new_row, new_col))
        return true;

    bool ate_apple = _map[new_row][new_col] == 'G';

    _map[_snake_body.back().first][_snake_body.back().second] = ' ';
    _snake_body.push_front(std::make_pair(new_row, new_col));
    _map[new_row][new_col] = 'S';

    if (!ate_apple)
        _snake_body.pop_back();
    else
        place_apple();

    return false;
}

void Snake::place_apple()
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> row_dist(1, _map.size() - 2);
    std::uniform_int_distribution<> col_dist(1, _map[0].length() - 2);
    int row = 0, col = 0;
    bool placed = false;

    while (!placed) {
        row = row_dist(gen);
        col = col_dist(gen);
        if (_map[row][col] == ' ') {
            _map[row][col] = 'G';
            placed = true;
        }
    }
}

void Snake::updateGame()
{
    _map = load_map();
    bool collision = false;
    std::chrono::milliseconds delay(100);

    while (!collision) {
        auto start = std::chrono::steady_clock::now();
        _window->clear();

        for (const auto &part : _snake_body)
            _map[part.first][part.second] = 'S';

        Display::KeyType key = _window->getEvent();
        if (key == Display::KeyType::X)
            break;
        if (key == Display::KeyType::Z)
            _current_direction = "UP";
        if (key == Display::KeyType::S)
            _current_direction = "DOWN";
        if (key == Display::KeyType::Q)
            _current_direction = "LEFT";
        if (key == Display::KeyType::D)
            _current_direction = "RIGHT";
        collision = moveSnake(_current_direction);
        for (size_t i = 0; i != _map.size(); i++)
            for (size_t j = 0; j != _map[i].length(); j++)
                _window->drawCharacter(j, i, _map[i][j]);
        _window->display();
        auto end = std::chrono::steady_clock::now();
        auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
        if (elapsed < delay)
            std::this_thread::sleep_for(delay - elapsed);
    }
    stop();
}

void Snake::stop()
{
    _window->close();
    std::cout << "Snake game stopped" << std::endl;
}

extern "C" std::unique_ptr<IGameModule> createGame() {
    return std::make_unique<Snake>();
}
