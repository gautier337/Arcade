/*
** EPITECH PROJECT, 2023
** Sdl2 Window
** File description:
** sdl2Window
*/

#include "../include/sdl2Window.hpp"

void Display::SDL2Window::create(std::string const &title, int framerateLimit, int width, int height)
{
    if (SDL_Init(SDL_INIT_VIDEO) != 0)
        throw std::runtime_error("Failed to initialize SDL2");

    this->window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN);
    if (this->window == nullptr)
        throw std::runtime_error("Failed to create window");

    if (TTF_Init() != 0)
        throw std::runtime_error("Failed to initialize SDL_ttf");

    this->renderer = SDL_CreateRenderer(this->window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (this->renderer == nullptr)
        throw std::runtime_error("Failed to create renderer");

    this->title = title;
    this->width = width;
    this->height = height;
    this->framerateLimit = framerateLimit;
}

void Display::SDL2Window::clear()
{
    SDL_RenderClear(this->renderer);
}

Display::KeyType Display::SDL2Window::getEvent()
{
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        switch (event.type) {
        case SDL_QUIT:
            this->close();
            return Display::KeyType::X;
        case SDL_KEYDOWN:
            switch (event.key.keysym.sym) {
                case SDLK_z:
                    return Display::KeyType::Z;
                case SDLK_s:
                    return Display::KeyType::S;
                case SDLK_q:
                    return Display::KeyType::Q;
                case SDLK_d:
                    return Display::KeyType::D;
                case SDLK_e:
                    return Display::KeyType::E;
                case SDLK_x:
                    this->close();
                    return Display::KeyType::X;
            }
            break;
        }
    }
    return Display::KeyType::Unknown;
}

bool Display::SDL2Window::isOpen()
{
    return this->window != nullptr;
}

void Display::SDL2Window::drawCharacter(int x, int y, char character)
{
    SDL_Rect rect;
    rect.x = x * 15;
    rect.y = y * 15;
    rect.w = 15;
    rect.h = 15;

    SDL_SetRenderDrawColor(this->renderer, 0, 0, 0, 255);
    switch (character) {
        case 'P':
            SDL_SetRenderDrawColor(this->renderer, 255, 0, 0, 255);
            break;
        case '#':
            SDL_SetRenderDrawColor(this->renderer, 0, 0, 255, 255);
            break;
        case 'G':
            SDL_SetRenderDrawColor(this->renderer, 0, 255, 0, 255);
            break;
        default:
                // Render text for other characters
                SDL_Surface *textSurface;
                SDL_Texture *textTexture;
                SDL_Color textColor = {255, 255, 255, 255}; // White color for text
                TTF_Font *font = TTF_OpenFont("font/arial.ttf", 15); // Replace "path/to/font.ttf" with the path to your font file

                if (font == nullptr) {
                    throw std::runtime_error("Failed to load font");
                }

                std::string characterString(1, character);
                textSurface = TTF_RenderText_Solid(font, characterString.c_str(), textColor);
                textTexture = SDL_CreateTextureFromSurface(this->renderer, textSurface);

                SDL_RenderCopy(this->renderer, textTexture, nullptr, &rect);

                // Clean up
                SDL_DestroyTexture(textTexture);
                SDL_FreeSurface(textSurface);
                TTF_CloseFont(font);
                return;
    }
    SDL_RenderFillRect(this->renderer, &rect);
}

void Display::SDL2Window::display()
{
    SDL_RenderPresent(this->renderer);
}

void Display::SDL2Window::close()
{
    this->clear();
    if (this->renderer != nullptr) {
        SDL_DestroyRenderer(this->renderer);
        this->renderer = nullptr;
    }
    if (this->window != nullptr) {
        SDL_DestroyWindow(this->window);
        this->window = nullptr;
    }
    TTF_Quit();
    SDL_Quit();
}

void Display::SDL2Window::draw()
{
}

void Display::SDL2Window::setTitle(std::string const &title)
{
    SDL_SetWindowTitle(this->window, title.c_str());
}

std::string Display::SDL2Window::getTitle()
{
    return SDL_GetWindowTitle(this->window);

}

Display::SDL2Window::SDL2Window() : window(nullptr), renderer(nullptr)
{
}

Display::SDL2Window::~SDL2Window()
{
}

extern "C" std::unique_ptr<Display::SDL2Window> createWindow()
{
    return std::make_unique<Display::SDL2Window>();
}
