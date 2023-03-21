##
## EPITECH PROJECT, 2023
## Makefile core
## File description:
## Makefile
##

CXX = g++
CXXFLAGS = -Wall -Wextra -Werror -std=c++17 -fno-gnu-unique -fPIC
LDFLAGS = -ldl

SRC = $(wildcard src/*.cpp)
OBJ = $(SRC:.cpp=.o)
TARGET = ../arcade

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(TARGET)

re: fclean all

.PHONY: all clean fclean re
