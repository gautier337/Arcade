/*
** EPITECH PROJECT, 2023
** IGameModule
** File description:
** IGameModule
*/

#pragma once

class IGameModule {
    public:
        virtual ~IGameModule() = default;

        virtual void init() = 0;
        virtual void updateGame() = 0;
        virtual void stop() = 0;
};
