/*
** EPITECH PROJECT, 2023
** IClock
** File description:
** IClock
*/

namespace Display {
    class IClock {
        public:
            virtual ~IClock() = default;
            virtual int getElapsedTime() = 0;
            virtual void restart() = 0;
    };
};
