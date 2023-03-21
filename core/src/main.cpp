/*
** EPITECH PROJECT, 2023
** main
** File description:
** main
*/

#include <iostream>
#include <string>
#include <memory>
#include "../include/IWindow.hpp"
#include "../../graphics/include/IDisplayModule.hpp"
#include "../include/ISprite.hpp"
#include "../include/ITexture.hpp"
#include "../../games/include/IGameModule.hpp"
#include "DynamicLibraryHandler.hpp"

int main(int argc, char* argv[]) {
    if (argc != 3) {
        std::cerr << "Usage: " << argv[0] << " <path_to_graphics_library> <path_to_game_library>" << std::endl;
        return 84;
    }

    std::string graphicsLibraryPath = argv[1];
    std::string gameLibraryPath = argv[2];

    DynamicLibraryHandler gameLibraryHandler;

    if (!gameLibraryHandler.loadLibrary(gameLibraryPath)) {
        return 84;
    }

    // use the function create on the game library to create a new game
    typedef IGameModule* (*CreateGameModuleFunction)();
    CreateGameModuleFunction createGameModule = reinterpret_cast<CreateGameModuleFunction>(gameLibraryHandler.getSymbol("create"));

    if (!createGameModule) {
        return 84;
    }

    // Créer une instance de IGameModule
    IGameModule *gameModule = createGameModule();
    gameModule->init();

    DynamicLibraryHandler graphicsLibraryHandler;
    if (!graphicsLibraryHandler.loadLibrary(graphicsLibraryPath)) {
            return 84;
    }
    
    typedef IDisplayModule* (*CreateDisplayModuleFunction)();
    CreateDisplayModuleFunction createDisplayModule = reinterpret_cast<CreateDisplayModuleFunction>(graphicsLibraryHandler.getSymbol("create"));

    if (!createDisplayModule) {
        return 84;
    }

    // Créer une instance de IDisplayModule
    IDisplayModule *displayModule = createDisplayModule();
    displayModule->create();

    return 0;
}
