/*
** EPITECH PROJECT, 2023
** NCursesClock
** File description:
** NCursesClock
*/

#include "../include/NCursesClock.hpp"

Display::NCursesClock::NCursesClock()
{
    _start_timer = clock();
}

Display::NCursesClock::~NCursesClock()
{
}

int Display::NCursesClock::getElapsedTime()
{
    return (clock() - _start_timer) / 100;
}

void Display::NCursesClock::restart()
{
    _start_timer = clock();
}

extern "C" std::unique_ptr<Display::IClock> createClock()
{
    return std::make_unique<Display::NCursesClock>();
}
