/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** IDisplay Module interface
*/

#include "My.hpp"

#pragma once

class IDisplayModule {
    public :
        IDisplayModule ();
        virtual ~ IDisplayModule ();

        virtual void init () = 0;
        virtual void stop () = 0;
        virtual const std::string & getName () const = 0;
    protected :
        std::string _name;
};
