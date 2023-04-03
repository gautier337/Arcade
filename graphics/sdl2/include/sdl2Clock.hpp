/*
** EPITECH PROJECT, 2023
** Sdl2 clock
** File description:
** sdl2Clock
*/

#pragma once

#include "../../include/IClock.hpp"
#include <SDL2/SDL.h>
#include <memory>

namespace Display {
    class SDL2Clock : public Display::IClock {
        public:
            SDL2Clock();
            ~SDL2Clock() override;
            int getElapsedTime() override;
            void restart() override;

        private:
            Uint32 _start_timer;
    };
}
