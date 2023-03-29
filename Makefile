##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## arcade
##

all: core games graphics

core:
	mkdir -p lib
	$(MAKE) -C core

games:
	mkdir -p lib
	$(MAKE) -C games

graphics:
	mkdir -p lib
	$(MAKE) -C graphics

clean:
	$(MAKE) clean -C core
	$(MAKE) clean -C games
	$(MAKE) clean -C graphics

fclean:
	$(MAKE) fclean -C core
	$(MAKE) fclean -C games
	$(MAKE) fclean -C graphics
	rm -f arcade
	rm -f lib/*.so

re: fclean all

launch:
	make && ./arcade lib/arcade_ncurses.so lib/arcade_snake.so

.PHONY: all core games graphics clean fclean re
