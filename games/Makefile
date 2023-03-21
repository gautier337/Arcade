##
## EPITECH PROJECT, 2023
## makefile games
## File description:
## Makefile
##

CXX = g++
CXXFLAGS = -Wall -Wextra -Werror -std=c++17 -fno-gnu-unique -fPIC
LDFLAGS =

GAMES = snake
GAME_SRC = $(addprefix $(GAMES)/src/, $(addsuffix .cpp, $(GAMES)))
GAME_OBJ = $(GAME_SRC:.cpp=.o)
GAME_TARGET = $(addprefix ../lib/arcade_, $(addsuffix .so, $(GAMES)))

all: $(GAME_TARGET)

../lib/arcade_%.so: $(GAME_OBJ)
	$(CXX) -shared $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

$(GAME_OBJ): %.o: %.cpp
	$(CXX) $(CXXFLAGS) -Igames/$(GAMES)/include -c $< -o $@

clean:
	rm -f $(GAME_OBJ)

fclean: clean
	rm -f $(GAME_TARGET)

re: fclean all

.PHONY: all clean fclean re
