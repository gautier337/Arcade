/*
** EPITECH PROJECT, 2023
** vector
** File description:
** IVector2f
*/

#pragma once
#include <memory>

namespace Display {
    class IVector2f {
        public:
            virtual ~IVector2f() = default;
            virtual void create(float x, float y) = 0;
            virtual float getX() = 0;
            virtual void setX(float x) = 0;
            virtual float getY() = 0;
            virtual void setY(float y) = 0;
    };
    extern "C" std::unique_ptr<IVector2f> createVector2f();
};
