/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** IDisplay interface
*/

#pragma once

#include "../lib/lib.hpp"

class IDisplayModule {
  public:
    virtual ~IDisplayModule() = default;
    virtual void create() = 0;
    virtual void update() = 0;
    virtual void destroy() = 0;
};
