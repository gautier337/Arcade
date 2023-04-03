/*
** EPITECH PROJECT, 2023
** SFMLClock
** File description:
** SFMLClock
*/

#include "../include/SFMLClock.hpp"

Display::SFMLClock::SFMLClock()
{
}

Display::SFMLClock::~SFMLClock()
{
}

int Display::SFMLClock::getElapsedTime()
{
    sf::Time elapsed_time = _clock.getElapsedTime();
    return elapsed_time.asMilliseconds() * 100;
}

void Display::SFMLClock::restart()
{
    _clock.restart();
}

extern "C" std::unique_ptr<Display::IClock> createClock()
{
    return std::make_unique<Display::SFMLClock>();
}
