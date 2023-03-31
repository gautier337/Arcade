##
## EPITECH PROJECT, 2023
## makefile graphics
## File description:
## Makefile
##

CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17 -fno-gnu-unique -fPIC
LDFLAGS_NC = -lncurses
LDFLAGS_SF = -lsfml-graphics -lsfml-window -lsfml-system

GRAPHICS = ncurses SFML
GRAPHIC_SRC_NC = $(shell find ./ncurses -type f -name "*.cpp")
GRAPHIC_SRC_SF = $(shell find ./SFML -type f -name "*.cpp")
GRAPHIC_OBJ_NC = $(GRAPHIC_SRC_NC:.cpp=.o)
GRAPHIC_OBJ_SF = $(GRAPHIC_SRC_SF:.cpp=.o)
GRAPHIC_TARGET = $(addprefix ../lib/arcade_, $(addsuffix .so, $(GRAPHICS)))

all: $(GRAPHIC_TARGET)

../lib/arcade_ncurses.so: $(GRAPHIC_OBJ_NC)
	$(CXX) -shared $(CXXFLAGS) -o $@ $^ $(LDFLAGS_NC)

../lib/arcade_SFML.so: $(GRAPHIC_OBJ_SF)
	$(CXX) -shared $(CXXFLAGS) -o $@ $^ $(LDFLAGS_SF)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -Iinclude -c $< -o $@

clean:
	rm -f $(GRAPHIC_OBJ_NC) $(GRAPHIC_OBJ_SF)

fclean: clean
	rm -f $(GRAPHIC_TARGET)

re: fclean all

.PHONY: all clean fclean re
