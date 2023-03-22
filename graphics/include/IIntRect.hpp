/*
** EPITECH PROJECT, 2023
** IIntRect.hpp
** File description:
** IIntRect
*/

#pragma once

#include "IIntRect.hpp"

namespace Display {
    class IIntRect {
        public:
            virtual ~IIntRect() = default;
            virtual void create(int left, int top, int width, int height) = 0;
            virtual int getLeft() = 0;
            virtual void setLeft(int left) = 0;
            virtual int getTop() = 0;
            virtual void setTop(int top) = 0;
            virtual int getWidth() = 0;
            virtual void setWidth(int width) = 0;
            virtual int getHeight() = 0;
            virtual void setHeight(int height) = 0;
    };
    // extern "C" std::unique_ptr<IIntRect> createIntRect();
};
