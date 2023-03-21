##
## EPITECH PROJECT, 2023
## makefile graphics
## File description:
## Makefile
##

CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17 -fno-gnu-unique -fPIC
LDFLAGS = -lncurses

GRAPHICS = ncurses
GRAPHIC_SRC = $(shell find ./ncurses -type f -name "*.cpp")
GRAPHIC_OBJ = $(GRAPHIC_SRC:.cpp=.o)
GRAPHIC_TARGET = $(addprefix ../lib/arcade_, $(addsuffix .so, $(GRAPHICS)))

all: $(GRAPHIC_TARGET)

../lib/arcade_%.so: $(GRAPHIC_OBJ)
	$(CXX) -shared $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -Iinclude -c $< -o $@

clean:
	rm -f $(GRAPHIC_OBJ)

fclean: clean
	rm -f $(GRAPHIC_TARGET)

re: fclean all

.PHONY: all clean fclean re
