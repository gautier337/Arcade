/*
** EPITECH PROJECT, 2023
** SFML Window
** File description:
** SFMLWindow
*/

#include "../include/SFMLWindow.hpp"

Display::SFMLWindow::SFMLWindow()
{
    std::cout << "SFML Window created" << std::endl;    
}

Display::SFMLWindow::~SFMLWindow()
{
    std::cout << "SFML Window destroyed" << std::endl;
}

void Display::SFMLWindow::create(std::string const &title, int framerateLimit, int width, int height)
{
    this->title = title;
    this->framerateLimit = framerateLimit;
    this->width = width;
    this->height = height;
    this->window = new sf::RenderWindow(sf::VideoMode(width, height), title);
    this->window->setFramerateLimit(framerateLimit);
}

Display::KeyType Display::SFMLWindow::getEvent()
{
    sf::Event event;
    while (this->window->pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            this->window->close();
            return Display::KeyType::X;
        }
        if (event.type == sf::Event::KeyPressed) {
            if (event.key.code == sf::Keyboard::Z)
                return Display::KeyType::Z;
            if (event.key.code == sf::Keyboard::S)
                return Display::KeyType::S;
            if (event.key.code == sf::Keyboard::Q)
                return Display::KeyType::Q;
            if (event.key.code == sf::Keyboard::D)
                return Display::KeyType::D;
            if (event.key.code == sf::Keyboard::X)
                return Display::KeyType::X;
        }
    }
    return Display::KeyType::Unknown;
}

std::string Display::SFMLWindow::getTitle()
{
    return this->title;
}

void Display::SFMLWindow::setTitle(std::string const &title)
{
    this->title = title;
    this->window->setTitle(title);
}

bool Display::SFMLWindow::isOpen()
{
    return this->window->isOpen();
}

void Display::SFMLWindow::clear()
{
    this->window->clear();
}

void Display::SFMLWindow::draw()
{
    // this->window->draw();
    std::cout << "SFML Window draw" << std::endl;
}

void Display::SFMLWindow::display()
{
    this->window->display();
}

void Display::SFMLWindow::close()
{
    this->window->close();
}

void Display::SFMLWindow::drawCharacter(int x, int y, char character)
{
    sf::Font font;
    sf::Text text;
    if (!font.loadFromFile("assets/arial.ttf"))
        std::cout << "Error loading font" << std::endl;
    text.setFont(font);
    text.setCharacterSize(24);
    text.setFillColor(sf::Color::White);
    text.setPosition(x, y);
    text.setString(character);
    this->window->draw(text);
}
