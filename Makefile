##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## arcade
##

NAME =	arcade

SRC =	src/main.cpp				\

LIB = -Wall -fPIC -shared

LIB_NAME = lib_arcade_ncurses.so

OBJ	=	$(SRC:.cpp=.o)

LIB_SRC = src/main.cpp

LIB_OBJ = $(LIB_SRC:.cpp=.o)

all: $(NAME) $(LIB_NAME)

$(NAME) : $(OBJ)
	g++ -o $(NAME) $(OBJ) -ldl -lncurses

$(LIB_NAME) : $(LIB_OBJ)
	g++ $(LIB) -o $(LIB_NAME) $(LIB_OBJ)

%.o: %.cpp
	g++ $(LIB) -c $< -o $@

clean:
	rm -f $(OBJ)
	rm -f $(LIB_OBJ)
	rm -f *.o
	rm -f *~

fclean: clean
	rm -f $(NAME)
	rm -f $(LIB_NAME)

re: fclean all

.PHONY:	all clean fclean re
