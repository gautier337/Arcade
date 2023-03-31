/*
** EPITECH PROJECT, 2023
** snake
** File description:
** Snake
*/

#pragma once

#include "../../include/IGameModule.hpp"
#include "../../../graphics/include/IWindow.hpp"
#include <vector>
#include <string>

class Menu : public IGameModule {
    public:
        Menu();
        ~Menu();
        void init(std::vector<std::unique_ptr<Display::IWindow>> &windows) override;
        void updateGame() override;
        void stop() override;

    private:
        void drawOptions();
        void moveSelectionUp();
        void moveSelectionDown();
        void updateSelection(Display::KeyType key);

        std::unique_ptr<Display::IWindow> _window;
        std::vector<std::string> _gamePaths;
        size_t _selectedOption;
};
