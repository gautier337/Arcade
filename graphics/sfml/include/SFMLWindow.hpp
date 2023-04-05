/*
** EPITECH PROJECT, 2023
** SFML Display
** File description:
** SFMLWindow
*/

#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include "../../include/IEvent.hpp"
#include "../../include/IWindow.hpp"

namespace Display {
    class SFMLWindow : public IWindow {
        public:
            SFMLWindow();
            ~SFMLWindow();

            void create(std::string const &title, int framerateLimit, int width, int height) override;
            Display::KeyType getEvent() override;
            std::string getTitle() override;
            void setTitle(std::string const &title) override;
            bool isOpen() override;
            void clear() override;
            void draw() override;
            void display() override;
            void close() override;
            void drawCharacter(int x, int y, char character) override;

        private:
            sf::RenderWindow _window;
            sf::Font _font;
            std::map<char, sf::Color> _colorMap;
            std::string _title;
            void setupColorMap();
    };
};
