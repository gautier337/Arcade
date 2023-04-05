/*
** EPITECH PROJECT, 2023
** SFML Window
** File description:
** SFMLWindow
*/

#include "../include/SFMLWindow.hpp"

Display::SFMLWindow::SFMLWindow()
{
    setupColorMap();
}

Display::SFMLWindow::~SFMLWindow()
{
}

void Display::SFMLWindow::setupColorMap()
{
    sf::Color whiteColor = sf::Color::White;
    for (char letter = '0'; letter <= '9'; ++letter) {
        _colorMap[letter] = whiteColor;
    }

    for (char letter = 'A'; letter <= 'Z'; ++letter) {
        _colorMap[letter] = whiteColor;
    }

    for (char letter = 'a'; letter <= 'z'; ++letter) {
        _colorMap[letter] = whiteColor;
    }
    _colorMap['P'] = sf::Color::Red;
    _colorMap['G'] = sf::Color::Green;
    _colorMap['#'] = sf::Color::Blue;
    _colorMap['.'] = sf::Color::White;
    _colorMap[':'] = sf::Color::White;
    _colorMap['-'] = sf::Color::White;
    _colorMap['>'] = sf::Color::White;
}

void Display::SFMLWindow::create(std::string const &title, int framerateLimit, int width, int height)
{
    _title = title;
    _window.create(sf::VideoMode(width, height), title);
    _window.setFramerateLimit(framerateLimit);
    if (!_font.loadFromFile("font/arial.ttf"))
        std::cout << "Error loading font" << std::endl;
}

Display::KeyType Display::SFMLWindow::getEvent()
{
    sf::Event event;
    while (isOpen() && _window.pollEvent(event)) {
        if (event.type == sf::Event::KeyPressed) {
            switch (event.key.code) {
            case sf::Keyboard::X:
                return Display::KeyType::X;
            case sf::Keyboard::A:
                return Display::KeyType::A;
            case sf::Keyboard::B:
                return Display::KeyType::B;
            case sf::Keyboard::C:
                return Display::KeyType::C;
            case sf::Keyboard::D:
                return Display::KeyType::D;
            case sf::Keyboard::E:
                return Display::KeyType::E;
            case sf::Keyboard::F:
                return Display::KeyType::F;
            case sf::Keyboard::G:
                return Display::KeyType::G;
            case sf::Keyboard::H:
                return Display::KeyType::H;
            case sf::Keyboard::I:
                return Display::KeyType::I;
            case sf::Keyboard::J:
                return Display::KeyType::J;
            case sf::Keyboard::K:
                return Display::KeyType::K;
            case sf::Keyboard::L:
                return Display::KeyType::L;
            case sf::Keyboard::M:
                return Display::KeyType::M;
            case sf::Keyboard::N:
                return Display::KeyType::N;
            case sf::Keyboard::O:
                return Display::KeyType::O;
            case sf::Keyboard::P:
                return Display::KeyType::P;
            case sf::Keyboard::Q:
                return Display::KeyType::Q;
            case sf::Keyboard::R:
                return Display::KeyType::R;
            case sf::Keyboard::S:
                return Display::KeyType::S;
            case sf::Keyboard::T:
                return Display::KeyType::T;
            case sf::Keyboard::U:
                return Display::KeyType::U;
            case sf::Keyboard::V:
                return Display::KeyType::V;
            case sf::Keyboard::W:
                return Display::KeyType::W;
            case sf::Keyboard::Y:
                return Display::KeyType::Y;
            case sf::Keyboard::Z:
                return Display::KeyType::Z;
            case sf::Keyboard::BackSpace:
                return Display::KeyType::Backspace;
            default:
                break;
            }
        }
    }
    return Display::KeyType::Unknown;
}

std::string Display::SFMLWindow::getTitle()
{
    return _title;
}

void Display::SFMLWindow::setTitle(std::string const &title)
{
    _title = title;
    _window.setTitle(_title);
}

bool Display::SFMLWindow::isOpen()
{
    return _window.isOpen();
}

void Display::SFMLWindow::clear()
{
    _window.clear();
}

void Display::SFMLWindow::draw()
{
}

void Display::SFMLWindow::display()
{
    _window.display();
}

void Display::SFMLWindow::close()
{
    if (_window.isOpen()) {
        _window.clear();
        _window.display();
    }
    _window.close();
}

void Display::SFMLWindow::drawCharacter(int x, int y, char character)
{
    float size = 18;
    if (character != '#' && character != 'P' && character != 'G') {
        sf::Text text;
        text.setFont(_font);
        text.setCharacterSize(size);
        text.setFillColor(_colorMap[character]);
        text.setPosition(x * size, y * size);
        text.setString(character);
        _window.draw(text);
    }
    else {
        sf::RectangleShape shape(sf::Vector2f(size, size));
        shape.setFillColor(_colorMap[character]);
        shape.setPosition(x * size, y * size);
        _window.draw(shape);
    }
}

extern "C" std::unique_ptr<Display::IWindow> createWindow()
{
    return std::make_unique<Display::SFMLWindow>();
}
