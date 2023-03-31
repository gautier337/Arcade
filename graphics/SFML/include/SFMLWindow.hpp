/*
** EPITECH PROJECT, 2023
** SFML Display
** File description:
** SFMLWindow
*/

#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include "../../include/ISprite.hpp"
#include "../../include/IEvent.hpp"
#include "../../include/IWindow.hpp"

namespace Display {
    class SFMLWindow : public IWindow {
        public:
            SFMLWindow();
            ~SFMLWindow() override;
            void create(std::string const &title, int framerateLimit, int width, int height) override;
            Display::KeyType getEvent() override;
            std::string getTitle() override;
            void setTitle(std::string const &title) override;
            bool isOpen() override;
            void clear() override;
            void draw() override;
            void display() override;
            void close() override;
        private:
            sf::RenderWindow *window;
            std::string title;
            int width;
            int height;
            int framerateLimit;
            void drawCharacter(int x, int y, char character);
    };
}