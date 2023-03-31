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
#include "../../graphics/include/ISprite.hpp"
#include "../../graphics/include/ITexture.hpp"
#include "../../games/include/IGameModule.hpp"
#include "../../graphics/ncurses/include/NCursesWindow.hpp"
#include "DynamicLibraryHandler.hpp"

int main(int argc, char **argv)
{
    if (argc != 3) {
        std::cerr << "Usage: " << argv[0] << " <path_to_graphics_library> <path_to_games_library>" << std::endl;
        return 84;
    }
    std::string graphicsLibraryPath = argv[1];
    std::string gamesLibraryPath = argv[2];

    DynamicLibraryHandler graphicsLibraryHandler;
    if (!graphicsLibraryHandler.loadLibrary(graphicsLibraryPath))
        return 84;

    typedef std::unique_ptr<Display::IWindow> (*CreateDisplayModuleFunction)();
    CreateDisplayModuleFunction createDisplayModule = reinterpret_cast<CreateDisplayModuleFunction>(graphicsLibraryHandler.getSymbol("createWindow"));

    if (!createDisplayModule)
        return 84;

    std::unique_ptr<Display::IWindow> displayModule = createDisplayModule();

    DynamicLibraryHandler gameLibraryHandler;
    if (!gameLibraryHandler.loadLibrary(gamesLibraryPath))
        return 84;

    typedef std::unique_ptr<IGameModule> (*CreataGameModuleFunction)();
    CreataGameModuleFunction createGameModule = reinterpret_cast<CreataGameModuleFunction>(gameLibraryHandler.getSymbol("createGame"));

    if (!createGameModule)
        return 84;

    std::unique_ptr<IGameModule> gameModule = createGameModule();
    gameModule->init(displayModule);
    return 0;
}
