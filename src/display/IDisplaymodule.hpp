/*
** EPITECH PROJECT, 2023
** IDisplaymodule
** File description:
** IDisplaymodule
*/

#ifndef IDISPLAYMODULE_HPP_
#define IDISPLAYMODULE_HPP_

class IDisplaymodule {
    public:
        virtual ~IDisplaymodule() = default;
        virtual void openWindow() = 0;
        virtual void closeWindow() = 0;
        virtual void clearWindow() = 0;
        virtual void displayWindow() = 0;
        virtual void drawSprite() = 0;
        virtual void drawText() = 0;
        virtual void drawRectangle() = 0;
        virtual void drawCircle() = 0;
        virtual void drawLine() = 0;
        virtual void drawPoint() = 0;
        virtual void drawPolygon() = 0;

    protected:
    private:
};

#endif /* !IDISPLAYMODULE_HPP_ */
