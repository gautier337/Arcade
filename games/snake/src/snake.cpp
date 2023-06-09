/*
** EPITECH PROJECT, 2023
** Snake
** File description:
** Snake
*/

#include "../include/snake.hpp"
#include <unistd.h>
#include <chrono>
#include <thread>
#include <utility>
#include <memory>
#include <deque>
#include <random>

Snake::Snake()
{
}

Snake::~Snake()
{
}

std::pair<int, int> Snake::find_snake_position(const std::vector<std::string> &map)
{
    if (map.empty())
        return std::make_pair(-1, -1);
    for (size_t i = 0; i != map.size(); i++) 
        for (size_t j = 0; j != map[i].length(); j++)
            if (map[i][j] == 'P')
                return std::make_pair(i, j);
    return std::make_pair(-1, -1);
}

std::vector<std::string> Snake::load_map()
{
    std::vector<std::string> array = {
        "######################################",
        "#                                    #",
        "#                                    #",
        "#                                    #",
        "#                                    #",
        "#                                    #",
        "#                                    #",
        "#                                    #",
        "#                                    #",
        "#                                    #",
        "#           P                        #",
        "#                                    #",
        "#                                    #",
        "#                     G              #",
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

void Snake::set_value_game()
{
    _map = load_map();
    std::pair<int, int> snake_head = find_snake_position(_map);
    _snake_body.clear();
    _snake_body.push_front(snake_head);
    _snake_body.push_front(std::make_pair(snake_head.first, snake_head.second + 1));
    _snake_body.push_front(std::make_pair(snake_head.first, snake_head.second + 2));
    _snake_body.push_front(std::make_pair(snake_head.first, snake_head.second + 3));
    _score = 0;
}

void Snake::init(std::vector<std::unique_ptr<Display::IWindow>> &windows)
{
    if (windows.empty()) {
        std::cout << "No window available" << std::endl;
        return;
    }
    _windows = std::move(windows);
    _window = _windows[0].get();
    _window->create("Snake", 60, 1920, 1080);
    set_value_game();
    updateGame();
    return;
}

bool Snake::moveSnake(std::string direction)
{
    size_t row_offset = 0;
    size_t col_offset = 0;
    size_t new_row = 0;
    size_t new_col = 0;

    if (direction == "UP")
        row_offset = -1;
    else if (direction == "DOWN")
        row_offset = 1;
    else if (direction == "LEFT")
        col_offset = -1;
    else if (direction == "RIGHT")
        col_offset = 1;

    new_row = _snake_body.front().first + row_offset;
    new_col = _snake_body.front().second + col_offset;

    if (check_wall_collision(_map, new_row, new_col) || check_self_collision(new_row, new_col))
        return true;

    bool ate_apple = _map[new_row][new_col] == 'G';

    _map[_snake_body.back().first][_snake_body.back().second] = ' ';
    _snake_body.push_front(std::make_pair(new_row, new_col));
    _map[new_row][new_col] = 'P';

    if (!ate_apple)
        _snake_body.pop_back();
    else {
        place_apple();
        _score++;
    }
    return false;
}

void Snake::drawScore()
{
    std::string scoreText = "Score: " + std::to_string(_score);
    int startX = scoreText.length() - 1;

    for (size_t i = 0; i != scoreText.length(); i++)
        _window->drawCharacter(startX + i, 0, scoreText[i]);
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
            _map[part.first][part.second] = 'P';

        Display::KeyType key = _window->getEvent();
        if (key == Display::KeyType::X) {
            _window->close();
            break;
        }
        if (key == Display::KeyType::Z)
            _current_direction = "UP";
        if (key == Display::KeyType::S)
            _current_direction = "DOWN";
        if (key == Display::KeyType::Q)
            _current_direction = "LEFT";
        if (key == Display::KeyType::D)
            _current_direction = "RIGHT";
        if (key == Display::KeyType::R)
            set_value_game();
        if (key == Display::KeyType::P)
            change_windows();
        if (key == Display::KeyType::L)
            exit(0);
        collision = moveSnake(_current_direction);
        for (size_t i = 0; i != _map.size(); i++)
            for (size_t j = 0; j != _map[i].length(); j++)
                _window->drawCharacter(j, i + 2, _map[i][j]);
        drawScore();
        _window->display();
        auto end = std::chrono::steady_clock::now();
        auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
        if (elapsed < delay)
            std::this_thread::sleep_for(delay - elapsed);
    }
    stop();
}

void Snake::change_windows()
{
    _window_index++;
    if (_window_index >= static_cast<int>(_windows.size()))
        _window_index = 0;
    _window->close();
    _window = _windows[_window_index].get();
    _window->create("Snake", 60, 1920, 1080);
}

void Snake::stop()
{
    _window->close();
}

extern "C" std::unique_ptr<IGameModule> createGame() {
    return std::make_unique<Snake>();
}
