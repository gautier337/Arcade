/*
** EPITECH PROJECT, 2023
** snake
** File description:
** Snake
*/

#pragma once

#include "../../include/IGameModule.hpp"
#include "../../../graphics/include/IWindow.hpp"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <deque>

class Snake : public IGameModule {
    public:
        Snake();
        ~Snake();
        void init(std::vector<std::unique_ptr<Display::IWindow>> &windows) override;
        void updateGame() override;
        void stop() override;
    private:
        std::unique_ptr<Display::IWindow> _window;
        std::vector<std::unique_ptr<Display::IWindow>> _windows;
        std::vector<std::string> load_map();
        std::pair<int, int> find_snake_position(const std::vector<std::string> &map);
        std::vector<std::string> _map;
        bool moveSnake(std::string direction);
        bool check_wall_collision(const std::vector<std::string> &map, size_t row, size_t col);
        std::string _current_direction = "RIGHT";
        std::deque<std::pair<int, int>> _snake_body;
        bool check_self_collision(int row, int col);
        void place_apple();
        int _score;
        void drawScore();
        void change_windows();
};
