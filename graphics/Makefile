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
LDFLAGS_SDL2 = -lSDL2 -lSDL2_image -lSDL2_ttf -lSDL2_mixer

GRAPHICS = ncurses sfml sdl2
GRAPHIC_SRC_NC = $(shell find ./ncurses -type f -name "*.cpp")
GRAPHIC_SRC_SDL2 = $(shell find ./sdl2 -type f -name "*.cpp")
GRAPHIC_SRC_SF = $(shell find ./sfml -type f -name "*.cpp")
GRAPHIC_OBJ_NC = $(GRAPHIC_SRC_NC:.cpp=.o)
GRAPHIC_OBJ_SF = $(GRAPHIC_SRC_SF:.cpp=.o)
GRAPHIC_OBJ_SDL2 = $(GRAPHIC_SRC_SDL2:.cpp=.o)
GRAPHIC_TARGET = $(addprefix ../lib/arcade_, $(addsuffix .so, $(GRAPHICS)))

all: $(GRAPHIC_TARGET)

../lib/arcade_ncurses.so: $(GRAPHIC_OBJ_NC)
	$(CXX) -shared $(CXXFLAGS) -o $@ $^ $(LDFLAGS_NC)

../lib/arcade_sfml.so: $(GRAPHIC_OBJ_SF)
	$(CXX) -shared $(CXXFLAGS) -o $@ $^ $(LDFLAGS_SF)

../lib/arcade_sdl2.so: $(GRAPHIC_OBJ_SF)
	$(CXX) -shared $(CXXFLAGS) -o $@ $^ $(LDFLAGS_SDL2)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -Iinclude -c $< -o $@

clean:
	rm -f $(GRAPHIC_OBJ_NC) $(GRAPHIC_OBJ_SF)

fclean: clean
	rm -f $(GRAPHIC_TARGET)

re: fclean all

.PHONY: all clean fclean re
