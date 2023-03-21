/*
** EPITECH PROJECT, 2023
** snake
** File description:
** Snake
*/

#ifndef SNAKE_HPP_
#define SNAKE_HPP_

#pragma once

#include "../../include/IGameModule.hpp"

class Snake : public IGameModule
{
    public:
        Snake();
        ~Snake();
    
        void init() override;
        void updateGame() override;
        void stop() override;
};

#endif /* !SNAKE_HPP_ */
