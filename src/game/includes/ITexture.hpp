/*
** EPITECH PROJECT, 2023
** interface texture
** File description:
** ITexture
*/

#pragma once

class ITexture {
    public:
        virtual ~ITexture() = default;
        virtual ITexture &getTexture() = 0;
        virtual void setTexture() = 0;

    protected:
    private:
};
