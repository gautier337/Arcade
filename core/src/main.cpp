/*
** EPITECH PROJECT, 2023
** main arcade
** File description:
** main
*/

#include <iostream>
#include <string>
#include <memory>
#include <vector>
#include <filesystem>
#include "../../graphics/include/IWindow.hpp"
#include "../../graphics/include/IClock.hpp"
#include "../../graphics/include/ISprite.hpp"
#include "../../graphics/include/ITexture.hpp"
#include "../../games/include/IGameModule.hpp"
#include "../../graphics/ncurses/include/NCursesWindow.hpp"
#include "DynamicLibraryHandler.hpp"

DynamicLibraryHandler load_dynamic_library(const std::string& graphicsLibraryPath)
{
    DynamicLibraryHandler graphicsLibraryHandler;
    if (!graphicsLibraryHandler.loadLibrary(graphicsLibraryPath))
        exit(84);
    return graphicsLibraryHandler;
}

std::unique_ptr<Display::IWindow> create_display_module(DynamicLibraryHandler& graphicsLibraryHandler)
{
    typedef std::unique_ptr<Display::IWindow> (*CreateDisplayModuleFunction)();
    CreateDisplayModuleFunction display_module =
        reinterpret_cast<CreateDisplayModuleFunction>(graphicsLibraryHandler.getSymbol("createWindow"));
    if (!display_module)
        exit(84);
    return display_module();
}

int main(int argc, char **argv)
{
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <path_to_graphics_library>" << std::endl;
        return 84;
    }
    std::string graphicsLibraryPath = argv[1];

    DynamicLibraryHandler argv_one_library_dynamic = load_dynamic_library(graphicsLibraryPath);
    DynamicLibraryHandler ncurses_library_dynamic = load_dynamic_library("lib/arcade_ncurses.so");

    std::unique_ptr<Display::IWindow> argv_one_display_module = create_display_module(argv_one_library_dynamic);
    std::unique_ptr<Display::IWindow> ncurses_display_module = create_display_module(ncurses_library_dynamic);

    std::vector<std::unique_ptr<Display::IWindow>> displayModules;
    displayModules.push_back(std::move(argv_one_display_module));
    displayModules.push_back(std::move(ncurses_display_module));

    std::vector<std::string> games = {"lib/arcade_snake.so", "lib/arcade_nibbler.so"};

    typedef std::unique_ptr<Display::IClock> (*CreateClockModuleFunction)();
    CreateClockModuleFunction createClockModule = reinterpret_cast<CreateClockModuleFunction>(argv_one_library_dynamic.getSymbol("createClock"));

    if (!createClockModule)
        return 84;

    std::unique_ptr<Display::IClock> clockModule = createClockModule();

    bool isRunning = true;
    int startX = 0;
    size_t gameIndex = 0;

    displayModules[0]->create("Menu", 60, 1920, 1080);
    while (isRunning) {
        if (clockModule != nullptr && clockModule->getElapsedTime() > 1000) {
            displayModules[0]->clear();
            for (size_t i = 0; i < games.size(); ++i) {
                startX = 5;
                for (size_t j = 0; j < games[i].length(); ++j)
                    displayModules[0]->drawCharacter(startX + j, i, games[i][j]);
                if (i == gameIndex) {
                    displayModules[0]->drawCharacter(startX - 2, i, '-');
                    displayModules[0]->drawCharacter(startX - 2, i, '>');
                }
            }
            displayModules[0]->display();
            clockModule->restart();
        }

        Display::KeyType event = displayModules[0]->getEvent();

        if (event == Display::KeyType::Z) {
            if (gameIndex > 0) {
                --gameIndex;
            }
        } else if (event == Display::KeyType::S) {
            if (gameIndex < games.size() - 1) {
                ++gameIndex;
            }
        } else if (event == Display::KeyType::E) {
            DynamicLibraryHandler gameLibraryHandler;

            if (!gameLibraryHandler.loadLibrary(games[gameIndex]))
                return 84;

            typedef std::unique_ptr<IGameModule> (*CreateGameModuleFunction)();
            CreateGameModuleFunction createGameModule = reinterpret_cast<CreateGameModuleFunction>(gameLibraryHandler.getSymbol("createGame"));

            if (!createGameModule)
                return 84;

            std::unique_ptr<IGameModule> gameModule = createGameModule();
            std::unique_ptr<Display::IWindow> new_display_module = create_display_module(argv_one_library_dynamic);

            std::vector<std::unique_ptr<Display::IWindow>> new_display_module_vector;
            new_display_module_vector.push_back(std::move(new_display_module));

            displayModules[0]->clear();
            displayModules[0]->close();
            gameModule->init(new_display_module_vector);
            displayModules[0]->create("Menu", 60, 1920, 1080);
        } else if (event == Display::KeyType::X) {
            isRunning = false;
        }
    }
    return 0;
}
