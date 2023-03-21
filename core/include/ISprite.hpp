/*
** EPITECH PROJECT, 2023
** ISprite
** File description:
** ISprite
*/

#pragma once

#include "../../graphics/include/IDisplayModule.hpp"
class ITexture;

class ISprite : public IDisplayModule
{
    public:
        virtual ~ISprite() = default;
        virtual void create(ITexture* texture, int posX, int posY, int orientation) = 0;
        virtual void update(int posX, int posY, int orientation) = 0;
        virtual void destroy() = 0;
};
