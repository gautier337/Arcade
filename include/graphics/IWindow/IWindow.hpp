/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** IWindow interface
*/

#pragma once

#include "../IDisplayModule.hpp"

class IWindow : public IDisplayModule {
    public:
        virtual ~IWindow() = default;
        virtual void create(std::string const &title, int framerateLimit, int width, int height) = 0;
        virtual void getFramerateLimit() = 0;
        virtual void setFramerateLimit(int framerateLimit) = 0;
        virtual void getSize() = 0;
        virtual void setSize(int width, int height) = 0;
        virtual void getPosition() = 0;
        virtual void setPosition(int posX, int posY) = 0;
        virtual void clear() = 0;
        virtual void draw() = 0;
        virtual void destroy() = 0;
};
