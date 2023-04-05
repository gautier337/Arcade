/*
** EPITECH PROJECT, 2023
** Sdl2 window
** File description:
** sdl2Window
*/

#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <stdexcept>
#include "../../include/IEvent.hpp"
#include "../../include/IWindow.hpp"

namespace Display {
    class SDL2Window : public IWindow {
        public:
            SDL2Window();
            ~SDL2Window() override;
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
            SDL_Window *window;
            SDL_Renderer *renderer;
            std::string title;
            int width;
            int height;
            int framerateLimit;
    };
}
