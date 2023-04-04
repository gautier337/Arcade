/*
** EPITECH PROJECT, 2023
** Sdl2 clock
** File description:
** sdl2Clock
*/

#include "../include/sdl2Clock.hpp"

Display::SDL2Clock::SDL2Clock()
{
    _start_timer = SDL_GetTicks();
}

Display::SDL2Clock::~SDL2Clock()
{
}

int Display::SDL2Clock::getElapsedTime()
{
    return (SDL_GetTicks() - _start_timer) * 1000;
}

void Display::SDL2Clock::restart()
{
    _start_timer = SDL_GetTicks();
}

extern "C" std::unique_ptr<Display::IClock> createClock()
{
    return std::make_unique<Display::SDL2Clock>();
}
