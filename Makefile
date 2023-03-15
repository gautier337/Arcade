##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## arcade
##

NAME =	arcade

NAME_SHARED_LIB_TEST = libsharedtest.so

SRC =	src/main.cpp				\

SRC_SHARED_LIB_TEST =	test.cpp

OBJ =	$(SRC:.cpp=.o)

OBJ_SHARED_LIB_TEST =	$(SRC_SHARED_LIB_TEST:.cpp=.o)

FLAGS_SHARED_LIB = -Wall -fPIC -shared

all: $(NAME)

sharedtest: $(NAME_SHARED_LIB_TEST)

$(NAME): $(OBJ)
	g++ -o $(NAME) $(OBJ) -ldl

$(NAME_SHARED_LIB_TEST): $(OBJ_SHARED_LIB_TEST)
	g++ $(FLAGS_SHARED_LIB) -o $(NAME_SHARED_LIB_TEST) $(OBJ_SHARED_LIB_TEST)

clean:
	rm -f $(OBJ)
	rm -f $(LIB_OBJ)
	rm -f *.o
	rm -f *~
	rm -f *.so

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY:	all clean fclean re
