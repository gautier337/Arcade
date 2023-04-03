/*
** EPITECH PROJECT, 2023
** SFMLClock
** File description:
** SFMLClock
*/

#pragma once

#include "../../include/IClock.hpp"
#include <SFML/System.hpp>
#include <memory>

namespace Display {
    class SFMLClock : public Display::IClock {
        public:
            SFMLClock();
            ~SFMLClock() override;
            int getElapsedTime() override;
            void restart() override;

        private:
            sf::Clock _clock;
    };
}
