/*
** EPITECH PROJECT, 2023
** main
** File description:
** main
*/

#include <iostream>
#include <string>
#include <memory>
#include "../../graphics/include/IWindow.hpp"
#include "../../graphics/include/IDisplayModule.hpp"
#include "../../graphics/include/ISprite.hpp"
#include "../../graphics/include/ITexture.hpp"
#include "../../games/include/IGameModule.hpp"
#include "DynamicLibraryHandler.hpp"

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <path_to_graphics_library>" << std::endl;
        return 84;
    }

    std::string graphicsLibraryPath = argv[1];

    DynamicLibraryHandler graphicsLibraryHandler;
    if (!graphicsLibraryHandler.loadLibrary(graphicsLibraryPath))
        return 84;

    typedef IDisplayModule* (*CreateDisplayModuleFunction)();
    CreateDisplayModuleFunction createDisplayModule = reinterpret_cast<CreateDisplayModuleFunction>(graphicsLibraryHandler.getSymbol("create"));

    if (!createDisplayModule)
        return 84;

    IDisplayModule *displayModule = createDisplayModule();
    displayModule->create();

    // Boucle principale
    bool running = true;
    while (running) {

        displayModule->clear();
        // Ici, vous ajouterez plus tard les appels pour mettre à jour et dessiner le module de jeu.
        displayModule->draw(nullptr);
        displayModule->update();
    }

    // Nettoyer
    displayModule->destroy();
    delete displayModule;

    return 0;
}
