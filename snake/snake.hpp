/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** Snake class
*/

#pragma once

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <ncurses.h>
#include <algorithm>
#include <stdexcept>

std::pair<int, int> find_snake_position(const std::vector<std::string> &map);
std::vector<std::string> load_2d_arr_from_file(const std::string &filepath);
void display_map(const std::vector<std::string> &map);
void init_game(const std::vector<std::string> &original_map);

class Snake {
public:
    Snake(const std::vector<std::string> &map) {
        position = find_snake_position(map);
        prev_position = position;
        if (position == std::make_pair(-1, -1)) {
            throw std::runtime_error("Snake not found in map");
        }
        direction = std::make_pair(0, 1);
    }

    void move(const std::vector<std::string> &map) {
        prev_position = position;
        int new_x = position.first + direction.first;
        int new_y = position.second + direction.second;

        if (map[new_x][new_y] != '#') {
            position.first = new_x;
            position.second = new_y;
        }
    }

    void set_direction(int new_direction) {
        switch (new_direction) {
            case KEY_UP:
                direction = std::make_pair(-1, 0);
                break;
            case KEY_DOWN:
                direction = std::make_pair(1, 0);
                break;
            case KEY_LEFT:
                direction = std::make_pair(0, -1);
                break;
            case KEY_RIGHT:
                direction = std::make_pair(0, 1);
                break;
            default:
                break;
        }
    }

    void update_map(std::vector<std::string> &map) {
        map[prev_position.first][prev_position.second] = ' ';
        map[position.first][position.second] = 'S';
        prev_position = position;
    }

private:
    std::pair<int, int> prev_position;
    std::pair<int, int> position;
    std::pair<int, int> direction;
};