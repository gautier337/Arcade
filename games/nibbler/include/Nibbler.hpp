/*
** EPITECH PROJECT, 2023
** Nibbler
** File description:
** Nibbler
*/

#pragma once

#include "../../include/IGameModule.hpp"
#include "../../../graphics/include/IWindow.hpp"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <deque>

class Nibbler : public IGameModule {
    public:
        Nibbler();
        ~Nibbler();
        void init(std::vector<std::unique_ptr<Display::IWindow>> &windows) override;
        void updateGame() override;
        void stop() override;
    private:
        Display::IWindow *_window;
        std::vector<std::unique_ptr<Display::IWindow>> _windows;
        std::vector<std::string> load_map();
        std::pair<int, int> find_Nibbler_position(const std::vector<std::string> &map);
        std::vector<std::string> _map;
        bool moveNibbler(std::string direction);
        bool bounce_when_touch_wall(const std::vector<std::string> &map, size_t row, size_t col);
        std::string _current_direction = "RIGHT";
        std::deque<std::pair<int, int>> _Nibbler_body;
        bool check_self_collision(int row, int col);
        int _score;
        void drawScore();
        void change_windows();
        int _window_index = 0;
        void set_value_game();
};
