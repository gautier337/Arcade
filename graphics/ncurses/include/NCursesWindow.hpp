/*
** EPITECH PROJECT, 2023
** NcursesDisplay
** File description:
** NcursesDisplay
*/

#pragma once

#include <ncurses.h>
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <stdexcept>
#include "../../include/ISprite.hpp"
#include "../../include/IEvent.hpp"
#include "../../include/IWindow.hpp"

namespace Display {
    class NCursesWindow : public IWindow {
        public:
            NCursesWindow();
            ~NCursesWindow() override;
            void create(
                std::string const &title,
                int framerateLimit,
                int width,
                int height
            ) override;
            Display::KeyType getEvent() override;
            std::string getTitle() override;
            void setTitle(std::string const &title) override;
            bool isOpen() override;
            void clear() override;
            void draw() override;
            void display() override;
            void close() override;
            void drawCharacter(int x, int y, char character);
        private:
            WINDOW *window;
            std::string _title;
            int width;
            int height;
            int framerateLimit;
    };
}
