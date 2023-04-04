/*
** EPITECH PROJECT, 2023
** Nibbler
** File description:
** Nibbler
*/

#include "../include/Nibbler.hpp"
#include <unistd.h>
#include <chrono>
#include <thread>
#include <utility>
#include <memory>
#include <deque>
#include <random>

Nibbler::Nibbler()
{
}

Nibbler::~Nibbler()
{
}

std::pair<int, int> Nibbler::find_Nibbler_position(const std::vector<std::string> &map)
{
    if (map.empty())
        return std::make_pair(-1, -1);
    for (size_t i = 0; i != map.size(); i++) 
        for (size_t j = 0; j != map[i].length(); j++)
            if (map[i][j] == 'P')
                return std::make_pair(i, j);
    return std::make_pair(-1, -1);
}

std::vector<std::string> Nibbler::load_map()
{
    std::vector<std::string> array = {
        "#############################################",
        "#     G                               G     #",             
        "#   #####      #    #####     #     #####   #",
        "#     G        #      G       #       G     #",
        "#   #####      #    #####     #     #####   #",
        "# G # G                               G # G #",
        "#   #    ####       #####      #####    #   #",
        "#        #          #   #          #        #",
        "#        #     #    #####     #    #        #",
        "#           G  #      G       #  G          #",
        "#        #     #    #####     #    #        #",
        "#        #          #   #          #        #",
        "#   #    ####       #####      #####    #   #",
        "# G #                                   # G #",
        "#   #####  G   #    #####     #  G  #####   #",
        "#     G        #      G       #       G     #",
        "#   #####      #    #####     #     #####   #",
        "#                P                          #",
        "#############################################"};

    return array;
}

bool Nibbler::bounce_when_touch_wall(const std::vector<std::string> &map, size_t row, size_t col)
{
    // top right corner
    if (map[row - 1][col] == '#' && map[row][col + 1] == '#' && _current_direction == "UP") {
        _current_direction = "LEFT";
        return false;
    }
    // specific
    if (map[row - 1][col] == '#' && map[row][col + 1] == '#' && _current_direction == "RIGHT") {
        _current_direction = "DOWN";
        return false;
    }
    // specific
    if (map[row + 1][col] == '#' && map[row][col + 1] == '#' && _current_direction == "RIGHT") {
        _current_direction = "UP";
        return false;
    }
    // specific
    if (map[row + 1][col] == '#' && map[row][col + 1] == '#' && _current_direction == "DOWN") {
        _current_direction = "LEFT";
        return false;
    }
    // specific
    if (map[row - 1][col] == '#' && map[row][col - 1] == '#' && _current_direction == "UP") {
        _current_direction = "RIGHT";
        return false;
    }
    // specific
    if (map[row][col - 1] == '#' && map[row + 1][col] == '#' && _current_direction == "LEFT") {
        _current_direction = "UP";
        return false;
    }
    //check tunnel horizontal
    if (map[row - 1][col] == '#' && map[row + 1][col] == '#') {
        return false;
    }
    // check tunnel vertical
    if (map[row][col - 1] == '#' && map[row][col + 1] == '#') {
        return false;
    }
    //right wall
    if (map[row][col + 1] == '#' && _current_direction == "RIGHT") {
        _current_direction = "UP";
        return false;
    }
    //bottom wall
    if (map[row + 1][col] == '#' && _current_direction == "DOWN") {
        _current_direction = "RIGHT";
        return false;
    }
    //left wall
    if (map[row][col - 1] == '#' && _current_direction == "LEFT") {
        _current_direction = "DOWN";
        return false;
    }
    //top wall
    if (map[row - 1][col] == '#' && _current_direction == "UP") {
        _current_direction = "LEFT";
        return false;
    }
    return false;
}

bool Nibbler::check_self_collision(int row, int col)
{
    for (const auto &part : _Nibbler_body)
        if (part.first == row && part.second == col)
            return true;
    return false;
}

void Nibbler::set_value_game()
{
    std::pair<int, int> Nibbler_head = find_Nibbler_position(load_map());
    _Nibbler_body.clear();
    _Nibbler_body.push_front(Nibbler_head);
    _Nibbler_body.push_front(std::make_pair(Nibbler_head.first, Nibbler_head.second + 1));
    _Nibbler_body.push_front(std::make_pair(Nibbler_head.first, Nibbler_head.second + 2));
    _Nibbler_body.push_front(std::make_pair(Nibbler_head.first, Nibbler_head.second + 3));
    _score = 0;
    _map = load_map();
}

void Nibbler::init(std::vector<std::unique_ptr<Display::IWindow>> &windows)
{
    if (windows.empty()) {
        std::cout << "No window available" << std::endl;
        return;
    }
    _windows = std::move(windows);
    _window = _windows[0].get();
    _window->create("Nibbler", 60, 1920, 1080);
    set_value_game();
    updateGame();
    return;
}

bool Nibbler::moveNibbler(std::string direction)
{
    int row_offset = 0;
    int col_offset = 0;
    int new_row = 0;
    int new_col = 0;

    if (direction == "UP")
        row_offset = -1;
    else if (direction == "DOWN")
        row_offset = 1;
    else if (direction == "LEFT")
        col_offset = -1;
    else if (direction == "RIGHT")
        col_offset = 1;

    new_row = _Nibbler_body.front().first + row_offset;
    new_col = _Nibbler_body.front().second + col_offset;

    if (bounce_when_touch_wall(_map, new_row, new_col) || check_self_collision(new_row, new_col))
        return true;

    bool ate_apple = _map[new_row][new_col] == 'G';

    _map[_Nibbler_body.back().first][_Nibbler_body.back().second] = ' ';
    _Nibbler_body.push_front(std::make_pair(new_row, new_col));
    _map[new_row][new_col] = 'P';

    if (!ate_apple)
        _Nibbler_body.pop_back();
    else {
        _score++;
    }
    return false;
}

void Nibbler::drawScore()
{
    std::string scoreText = "Score: " + std::to_string(_score);
    int startX = scoreText.length() - 1;

    for (size_t i = 0; i != scoreText.length(); i++)
        _window->drawCharacter(startX + i, 0, scoreText[i]);
}

void Nibbler::updateGame()
{
    _map = load_map();
    bool collision = false;
    std::chrono::milliseconds delay(100);

    while (!collision) {
        auto start = std::chrono::steady_clock::now();
        _window->clear();

        for (const auto &part : _Nibbler_body)
            _map[part.first][part.second] = 'P';

        Display::KeyType key = _window->getEvent();
        if (key == Display::KeyType::X || _score == 19)
            break;
        if (key == Display::KeyType::Z)
            _current_direction = "UP";
        if (key == Display::KeyType::S)
            _current_direction = "DOWN";
        if (key == Display::KeyType::Q)
            _current_direction = "LEFT";
        if (key == Display::KeyType::D)
            _current_direction = "RIGHT";
        if (key == Display::KeyType::P)
            change_windows();
        if (key == Display::KeyType::R)
            set_value_game();
        collision = moveNibbler(_current_direction);
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

void Nibbler::change_windows()
{
    _window_index++;
    if (_window_index >= static_cast<int>(_windows.size()))
        _window_index = 0;
    _window->close();
    _window = _windows[_window_index].get();
    _window->create("Snake", 60, 1920, 1080);
}

void Nibbler::stop()
{
    _window->close();
}

extern "C" std::unique_ptr<IGameModule> createGame() {
    return std::make_unique<Nibbler>();
}
