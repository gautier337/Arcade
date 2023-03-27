/*
** EPITECH PROJECT, 2023
** NcursesDisplay
** File description:
** NcursesDisplay
*/

#pragma once

#include <ncurses.h>
#include <string>
#include "../../include/IDisplayModule.hpp"
#include "../../include/ISprite.hpp"

namespace Display {
class NcursesDisplay : public IDisplayModule
{
    public:
        NcursesDisplay();
        virtual ~NcursesDisplay();

        void create() override;
        void update() override;
        void destroy() override;
        void clear() override;
        void draw(ISprite *sprite) override;

    private:
        WINDOW *mainwin;
    };
}