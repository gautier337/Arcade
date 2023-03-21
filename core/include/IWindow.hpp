/*
** EPITECH PROJECT, 2023
** IWindow
** File description:
** IWindow
*/

#pragma once

#include "../../graphics/include/IDisplayModule.hpp"
#include <string>

class IWindow : public IDisplayModule {
    public:
        virtual ~IWindow() = default;
        virtual void create(const std::string& title, int framerateLimit, int width, int height) = 0;
        virtual int getFramerateLimit() = 0;
        virtual void setFramerateLimit(int framerateLimit) = 0;
        virtual void getSize(int& width, int& height) = 0;
        virtual void setSize(int width, int height) = 0;
        virtual void getPosition(int& posX, int& posY) = 0;
        virtual void setPosition(int posX, int posY) = 0;
        virtual void clear() = 0;
        virtual void draw() = 0;
        virtual void destroy() = 0;
};
