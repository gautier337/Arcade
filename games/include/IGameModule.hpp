/*
** EPITECH PROJECT, 2023
** IGameModule
** File description:
** IGameModule
*/

#ifndef IGAMEMODULE_HPP_
#define IGAMEMODULE_HPP_

#pragma once

class IGameModule {
    public:
        virtual ~IGameModule() = default;

        virtual void init() = 0;
        virtual void updateGame() = 0;
        virtual void stop() = 0;
};

#endif /* !IGAMEMODULE_HPP_ */
