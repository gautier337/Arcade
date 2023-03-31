/*
** EPITECH PROJECT, 2023
** IGameModule
** File description:
** IGameModule
*/

#pragma once

#include "../../graphics/include/IWindow.hpp"
#include <vector>

class IGameModule {
    public:
        virtual ~IGameModule() = default;
        virtual void init(std::vector<std::unique_ptr<Display::IWindow>> &windows) = 0;
        virtual void updateGame() = 0;
        virtual void stop() = 0;
};
