/*
** EPITECH PROJECT, 2023
** NCursesClock
** File description:
** NCursesClock
*/

#pragma once

#include "../../include/IClock.hpp"
#include <ncurses.h>
#include <time.h>
#include <memory>

namespace Display {
    class NCursesClock : public Display::IClock {
        public:
            NCursesClock();
            ~NCursesClock() override;
            int getElapsedTime() override;
            void restart() override;

        private:
            clock_t _start_timer;
    };
}
