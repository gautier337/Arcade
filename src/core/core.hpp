/*
** EPITECH PROJECT, 2023
** core
** File description:
** core
*/

#pragma once

#include "lib.hpp"

namespace Arcade {
    class Core {
        public:
            Core(const std::string &startingGraphicLib);
            ~Core();
            void run();
        private:
            void loadLibraries();
            void loadGame(const std::string &gameName);
            void loadGraphicalLib(const std::string &graphicalLibName);
            void switchToNextGame();
            void switchToNextGraphicalLib();
            void restartGame();
            void gobackToMenu();
        private:
            // std::vector<std::unique_ptr< interface en commun de jeu (IGAME) >> _games;
    };
};
