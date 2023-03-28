/*
** EPITECH PROJECT, 2023
** NcursesDisplay
** File description:
** NcursesDisplay
*/

#pragma once

#include <ncurses.h>
#include <string>
#include "../../include/ISprite.hpp"
#include "../../include/IEvent.hpp"
#include "../../include/IWindow.hpp"

namespace Display {
    class NCursesWindow : public IWindow {
        public:
            ~NCursesWindow() override;
            void create(
                std::string const &title,
                int framerateLimit,
                int width,
                int height
            ) override;
            std::unique_ptr<Display::IEvent> getEvent() override;
            std::string getTitle() override;
            void setTitle(std::string const &title) override;
            bool isOpen() override;
            void clear() override;
            void draw() override;
            void display() override;
            void close() override;
    };
}
