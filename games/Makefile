##
## EPITECH PROJECT, 2023
## makefile GAMEs
## File description:
## Makefile
##

CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17 -fno-gnu-unique -fPIC

GAMES = snake menu nibbler
GAME_SRC_SNAKE = $(shell find ./snake -type f -name "*.cpp")
GAME_SRC_MENU = $(shell find ./menu -type f -name "*.cpp")
GAME_SRC_NIBBLER = $(shell find ./nibbler -type f -name "*.cpp")
GAME_OBJ_SNAKE = $(GAME_SRC_SNAKE:.cpp=.o)
GAME_OBJ_MENU = $(GAME_SRC_MENU:.cpp=.o)
GAME_OBJ_NIBBLER = $(GAME_SRC_NIBBLER:.cpp=.o)
GAME_TARGET = $(addprefix ../lib/arcade_, $(addsuffix .so, $(GAMES)))

all: $(GAME_TARGET)

../lib/arcade_snake.so: $(GAME_OBJ_SNAKE)
	$(CXX) -shared $(CXXFLAGS) -o $@ $^

../lib/arcade_menu.so: $(GAME_OBJ_MENU)
	$(CXX) -shared $(CXXFLAGS) -o $@ $^

../lib/arcade_nibbler.so: $(GAME_OBJ_NIBBLER)
	$(CXX) -shared $(CXXFLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -Iinclude -c $< -o $@

clean:
	rm -f $(GAME_OBJ_SNAKE) $(GAME_OBJ_MENU) $(GAME_OBJ_NIBBLER)

fclean: clean
	rm -f $(GAME_TARGET)

re: fclean all

.PHONY: all clean fclean re
