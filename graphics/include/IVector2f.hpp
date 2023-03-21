/*
** EPITECH PROJECT, 2023
** vector
** File description:
** IVector2f
*/

#ifndef IVECTOR2F_HPP_
#define IVECTOR2F_HPP_

class IVector2f {
    public:
        virtual ~IVector2f() = default;
        virtual int getX() = 0;
        virtual void setX(int x) = 0;
        virtual int getY() = 0;
        virtual void setY(int y) = 0;
        virtual void set(int x, int y) = 0;
};

#endif /* !IVECTOR2F_HPP_ */
