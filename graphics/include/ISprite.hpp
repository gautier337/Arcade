/*
** EPITECH PROJECT, 2023
** ISprite
** File description:
** ISprite
*/

#pragma once

#include "ITexture.hpp"
#include "IIntRect.hpp"
#include "IVector2f.hpp"
#include <memory>

namespace Display {
    class ISprite {
        public:
            virtual ~ISprite() = default;
            virtual void create(
                std::unique_ptr<ITexture> &texture,
                std::unique_ptr<IIntRect> &rect,
                std::unique_ptr<IVector2f> &position
            ) = 0;
            virtual std::unique_ptr<Display::IIntRect> getRect() = 0;
            virtual void setRect(std::unique_ptr<Display::IIntRect> &rect) = 0;
            virtual std::unique_ptr<Display::IVector2f> getPosition() = 0;
            virtual void setPosition(std::unique_ptr<Display::IVector2f> &position) = 0;
            virtual std::unique_ptr<Display::ITexture> getTexture() = 0;
            virtual void setTexture(std::unique_ptr<Display::ITexture> &texture) = 0;
            virtual void move(std::unique_ptr<Display::IVector2f> &offset) = 0;
    };
    extern "C" std::unique_ptr<ISprite> createSprite();
};
