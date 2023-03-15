/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** IGame interface
*/

#pragma once

class IGameModule {
  public:
    virtual ~IGameModule() = default;
    virtual void init() = 0;
    virtual void updateGame() = 0;
    virtual void stop() = 0;
};
