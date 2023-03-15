##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## arcade
##

NAME =	arcade

SRC =	src/main.cpp				\

OBJ	=	$(SRC:.cpp=.o)

all: $(NAME)

$(NAME) : $(OBJ)
	g++ -o $(NAME) $(OBJ) -Wall -Wextra -Werror -std=c++2a -pthread

clean:
	rm -f $(OBJ)
	rm -f *.o
	rm -f *~

f:
	make fclean
	make -j

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY:	all clean fclean re