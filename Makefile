##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## arcade
##

all: core games graphics

core:
	$(MAKE) -C core

games:
	$(MAKE) -C games

graphics:
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

.PHONY: all core games graphics clean fclean re
