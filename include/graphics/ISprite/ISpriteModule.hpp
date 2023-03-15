/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** ISprite interface
*/

#pragma once

#include "../IDisplayModule.hpp"
#include "../ITexture/ITexture.hpp"

class ISprite : public IDisplayModule {
  public:
    virtual ~ISprite() = default;
    virtual void create(ITexture texture, int posX, int posY, int orientation) = 0;
    virtual void update(int posX, int posY, int orientation) = 0;
    virtual void destroy() = 0;
};
