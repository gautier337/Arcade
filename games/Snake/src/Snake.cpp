/*
** EPITECH PROJECT, 2023
** Snake
** File description:
** Snake
*/

#include <iostream>
#include "../include/snake.hpp"

Snake::Snake()
{
    std::cout << "Snake constructor called" << std::endl;
}

Snake::~Snake()
{
    std::cout << "Snake game destroyed" << std::endl;
}

void Snake::init()
{
    std::cout << "Snake game initialized" << std::endl;
    // Initialize game state, load resources, etc.
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
