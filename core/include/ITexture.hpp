/*
** EPITECH PROJECT, 2023
** ITexture
** File description:
** ITexture
*/

#pragma once

#include "../../graphics/include/IDisplayModule.hpp"
#include <string>

class ITexture : public IDisplayModule
{
    public:
        virtual ~ITexture() = default;
        virtual void create(const std::string& path) = 0;
        virtual void update(const std::string& path) = 0;
        virtual void destroy() = 0;
};
