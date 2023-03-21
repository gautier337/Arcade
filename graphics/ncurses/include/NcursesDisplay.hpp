/*
** EPITECH PROJECT, 2023
** NcursesDisplay
** File description:
** NcursesDisplay
*/

#ifndef NCURSESDISPLAY_HPP_
#define NCURSESDISPLAY_HPP_

#pragma once

#include <ncurses.h>
#include <string>
#include "../include/IDisplayModule.hpp"

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

#endif /* !NCURSESDISPLAY_HPP_ */
