#include <iostream>
#include <string>
#include <memory>
#include <vector>
#include <filesystem>
#include "../../graphics/include/IWindow.hpp"
#include "../../graphics/include/ISprite.hpp"
#include "../../graphics/include/ITexture.hpp"
#include "../../games/include/IGameModule.hpp"
#include "../../graphics/ncurses/include/NCursesWindow.hpp"
#include "DynamicLibraryHandler.hpp"

int main(int argc, char **argv)
{
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <path_to_graphics_library>" << std::endl;
        return 84;
    }
    std::string graphicsLibraryPath = argv[1];

    DynamicLibraryHandler graphicsLibraryHandler;
    if (!graphicsLibraryHandler.loadLibrary(graphicsLibraryPath))
        return 84;

    typedef std::unique_ptr<Display::IWindow> (*CreateDisplayModuleFunction)();
    CreateDisplayModuleFunction createDisplayModule = reinterpret_cast<CreateDisplayModuleFunction>(graphicsLibraryHandler.getSymbol("createWindow"));

    if (!createDisplayModule)
        return 84;

    std::unique_ptr<Display::IWindow> displayModule = createDisplayModule();

    std::vector<std::unique_ptr<Display::IWindow>> displayModules;
    displayModules.push_back(std::move(displayModule));

    std::vector<std::string> games = {
            "lib/arcade_snake.so",
            "lib/arcade_nibler.so"
        };

    bool isRunning = true;
    int startX = 0;
    size_t gameIndex = 0;

    displayModules[0]->create("Menu", 60, 800, 400);
    while (isRunning) {
        displayModules[0]->clear();

        for (size_t i = 0; i < games.size(); ++i) {
            startX = games[i].length() - 1;
            for (size_t j = 0; j < games[i].length(); ++j)
                displayModules[0]->drawCharacter(startX + j, i, games[i][j]);
        }

        displayModules[0]->display();
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
            std::unique_ptr<Display::IWindow> new_display_module = createDisplayModule();

            std::vector<std::unique_ptr<Display::IWindow>> new_display_module_vector;
            new_display_module_vector.push_back(std::move(new_display_module));

            displayModules[0]->close();
            gameModule->init(new_display_module_vector);
        } else if (event == Display::KeyType::X) {
            isRunning = false;
        }
    }
    std::cout << "Bye bye !" << std::endl;
    displayModules[0]->close();
    return 0;
}
