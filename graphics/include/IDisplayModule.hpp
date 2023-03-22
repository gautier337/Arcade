/*
** EPITECH PROJECT, 2023
** IDisplayModule
** File description:
** IDisplayModule
*/

#pragma once

#include "ISprite.hpp"

class IDisplayModule {
    public:
        virtual ~IDisplayModule() = default;
        virtual void create() = 0;
        virtual void update() = 0;
        virtual void destroy() = 0;
        virtual void clear() = 0;
        virtual void draw(Display::ISprite* sprite) = 0;
};
