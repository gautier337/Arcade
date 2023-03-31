/*
** EPITECH PROJECT, 2023
** menu
** File description:
** Menu
*/

#include "../include/Menu.hpp"
#include <iostream>

Menu::Menu() : _selectedOption(0) {
    std::cout << "Menu created" << std::endl;
    _gamePaths = {
        "./game1.so",
        "./game2.so",
        "./game3.so",
        "./game3.so",
        "./game3.so",
    };
}

Menu::~Menu() {
    std::cout << "Menu destroyed" << std::endl;
}

void Menu::init(std::vector<std::unique_ptr<Display::IWindow>> &windows) {
    if (windows.empty()) {
        std::cout << "No window available" << std::endl;
        return;
    }
    _window = std::move(windows[0]);
    _window->create("Menu", 60, 800, 400);
    updateGame();
}

void Menu::updateGame() {
    while (true) {
        _window->clear();
        drawOptions();
        _window->display();

        Display::KeyType key = _window->getEvent();
        if (key == Display::KeyType::X)
            break;
        updateSelection(key);
    }
    stop();
}

void Menu::stop() {
    _window->close();
    std::cout << "Menu stopped" << std::endl;
}

void Menu::drawOptions() {
    for (size_t i = 0; i < _gamePaths.size(); ++i) {
        std::string option = _gamePaths[i];
        if (i == _selectedOption)
            option = "> " + option;
        else
            option = "  " + option;

        for (size_t j = 0; j < option.length(); ++j)
            _window->drawCharacter(j, i, option[j]);
    }
}

void Menu::moveSelectionUp() {
    if (_selectedOption > 0)
        --_selectedOption;
}

void Menu::moveSelectionDown() {
    if (_selectedOption < _gamePaths.size() - 1)
        ++_selectedOption;
}

void Menu::updateSelection(Display::KeyType key) {
    if (key == Display::KeyType::Z)
        moveSelectionUp();
    else if (key == Display::KeyType::S)
        moveSelectionDown();
    else if (key == Display::KeyType::W)
        std::cout << "Selected game: " << _gamePaths[_selectedOption] << std::endl;
}

extern "C" std::unique_ptr<IGameModule> createGame() {
    return std::make_unique<Menu>();
}
