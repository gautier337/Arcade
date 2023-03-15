/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** ITexture interface
*/

#pragma once

#include "../IDisplayModule.hpp"

class ITexture : public IDisplayModule {
  public:
    virtual ~ITexture() = default;
    virtual void create(std::string const &path) = 0;
    virtual void update(std::string const &path) = 0;
    virtual void destroy() = 0;
};