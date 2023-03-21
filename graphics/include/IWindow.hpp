/*
** EPITECH PROJECT, 2023
** IWindow
** File description:
** IWindow
*/

#pragma once

#include "IEvent.hpp"
#include <string>

class IWindow {
    public:
        virtual ~IWindow() = default;
        virtual void create(
            std::string const &title,
            int framerateLimit,
            int width,
            int height
        ) = 0;

        virtual std::string getTitle() = 0;
        virtual void setTitle(std::string const &title) = 0;
        virtual bool isOpen() = 0;
        virtual void clear() = 0;
        virtual void draw() = 0;
        virtual void display() = 0;
        virtual void close() = 0;
};
