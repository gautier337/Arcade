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
    DynamicLibraryHandler sdl2_library_dynamic = load_dynamic_library("lib/arcade_sdl2.so");
    DynamicLibraryHandler sfml_library_dynamic = load_dynamic_library("lib/arcade_sfml.so");

    std::unique_ptr<Display::IWindow> argv_one_display_module = create_display_module(argv_one_library_dynamic);
    std::unique_ptr<Display::IWindow> ncurses_display_module = create_display_module(ncurses_library_dynamic);
    std::unique_ptr<Display::IWindow> sdl2_display_module = create_display_module(sdl2_library_dynamic);
    std::unique_ptr<Display::IWindow> sfml_display_module = create_display_module(sfml_library_dynamic);

    std::vector<std::string> games = {"lib/arcade_snake.so", "lib/arcade_nibbler.so"};
    std::vector<std::unique_ptr<Display::IWindow>> display_module_vector_menu;

    display_module_vector_menu.push_back(std::move(argv_one_display_module));
    display_module_vector_menu.push_back(std::move(ncurses_display_module));
    display_module_vector_menu.push_back(std::move(sfml_display_module));
    display_module_vector_menu.push_back(std::move(sdl2_display_module));


    typedef std::unique_ptr<Display::IClock> (*CreateClockModuleFunction)();
    CreateClockModuleFunction createClockModule =
        reinterpret_cast<CreateClockModuleFunction>(argv_one_library_dynamic.getSymbol("createClock"));

    if (!createClockModule)
        return 84;

    std::unique_ptr<Display::IClock> clockModule = createClockModule();

    int idx_menu_graph = 0;
    bool isRunning = true;
    int startX = 0;
    size_t gameIndex = 0;

    display_module_vector_menu[idx_menu_graph]->create("Menu", 60, 1920, 1080);
    while (isRunning) {
        if (clockModule != nullptr && clockModule->getElapsedTime() > 1000) {
            display_module_vector_menu[idx_menu_graph]->clear();
            for (size_t i = 0; i < games.size(); ++i) {
                startX = 5;
                for (size_t j = 0; j < games[i].length(); ++j)
                    display_module_vector_menu[idx_menu_graph]->drawCharacter(startX + j, i, games[i][j]);
                if (i == gameIndex) {
                    display_module_vector_menu[idx_menu_graph]->drawCharacter(startX - 2, i, '-');
                    display_module_vector_menu[idx_menu_graph]->drawCharacter(startX - 2, i, '>');
                }
            }
            display_module_vector_menu[idx_menu_graph]->display();
            clockModule->restart();
        }

        Display::KeyType event = display_module_vector_menu[idx_menu_graph]->getEvent();

        if (event == Display::KeyType::Z) {
            if (gameIndex > 0) {
                --gameIndex;
            }
        } else if (event == Display::KeyType::S) {
            if (gameIndex < games.size() - 1) {
                ++gameIndex;
            }
        } else if (event == Display::KeyType::P) {
            if (idx_menu_graph + 1 >= static_cast<int>(display_module_vector_menu.size())) {
                display_module_vector_menu[idx_menu_graph]->close();
                idx_menu_graph = 0;
            } else {
                display_module_vector_menu[idx_menu_graph]->close();
                idx_menu_graph++;
            }
            display_module_vector_menu[idx_menu_graph]->create("Menu", 60, 1920, 1080);
        } else if (event == Display::KeyType::E) {
            DynamicLibraryHandler gameLibraryHandler;

            if (!gameLibraryHandler.loadLibrary(games[gameIndex]))
                return 84;

            typedef std::unique_ptr<IGameModule> (*CreateGameModuleFunction)();
            CreateGameModuleFunction createGameModule = reinterpret_cast<CreateGameModuleFunction>(gameLibraryHandler.getSymbol("createGame"));

            if (!createGameModule)
                return 84;

            auto gameModule = createGameModule();
            auto argv_one_display_module_game = create_display_module(argv_one_library_dynamic);
            auto ncurses_display_module_game = create_display_module(ncurses_library_dynamic);
            auto sdl2_display_module_game = create_display_module(sdl2_library_dynamic);
            auto sfml_display_module_game = create_display_module(sfml_library_dynamic);

            std::vector<std::unique_ptr<Display::IWindow>> new_display_module_vector;
            new_display_module_vector.push_back(std::move(argv_one_display_module_game));
            new_display_module_vector.push_back(std::move(ncurses_display_module_game));
            new_display_module_vector.push_back(std::move(sfml_display_module_game));
            new_display_module_vector.push_back(std::move(sdl2_display_module_game));

            display_module_vector_menu[idx_menu_graph]->clear();
            display_module_vector_menu[idx_menu_graph]->close();

            gameModule->init(new_display_module_vector);
            display_module_vector_menu[idx_menu_graph]->create("Menu", 60, 1920, 1080);
        } else if (event == Display::KeyType::X) {
            isRunning = false;
        }
    }
    return 0;
}
