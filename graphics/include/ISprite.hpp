/*
** EPITECH PROJECT, 2023
** ISprite
** File description:
** ISprite
*/

#pragma once

#include "IDisplayModule.hpp"
#include "ITexture.hpp"
#include "IIntRect.hpp"
#include "IVector2f.hpp"

class ISprite
{
    public:
        virtual ~ISprite() = default;
        virtual void createSprite(
            ITexture *texture,
            IIntRect const &rect,
            IVector2f const &position
        ) = 0;
        virtual void getRect() = 0;
        virtual void setRect(IIntRect const &rect) = 0;
        virtual void getPosition() = 0;
        virtual void setPosition(IVector2f const &position) = 0;
        virtual void getTexture() = 0;
        virtual void setTexture(ITexture *texture) = 0;
        virtual void move(IVector2f const &offset) = 0;
};
