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

class Snake : public IGameModule {
    public:
        Snake();
        ~Snake();
        void init(std::unique_ptr<Display::IWindow> &window) override;
        void updateGame() override;
        void stop() override;
    private:
        std::unique_ptr<Display::IWindow> _window;
        std::vector<std::string> load_2d_arr_from_file(const std::string &filepath);
        std::pair<int, int> find_snake_position(const std::vector<std::string> &map);
        int check_errors(const std::vector<std::string> &map, const std::pair<int, int> &snake_pos);
        std::vector<std::string> _map;
        void moveSnake(std::string direction);
};
