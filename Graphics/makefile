CXX := g++

PCH := SDL/SDL.hpp.gch
NAME := ../lib/libEZ++.a
INC := -I../Include/

COMP := g++ -c -include SDL/SDL.hpp $(INC)
SDL_LOC := /usr/lib/x86_64-linux-gnu

.PHONY: all rebuild_all

all:
	$(MAKE) build/Button.o
	$(MAKE) build/Color.o
	$(MAKE) build/ColorRect.o
	$(MAKE) build/Sprite.o
	$(MAKE) build/TextField.o
	$(MAKE) build/SDL.o
	ar rcs $(NAME) build/*.o

build/Button.o: Button/Button.cpp
	$(COMP) $< -o $@
build/Color.o: Color/Color.cpp
	$(COMP) $< -o $@
build/ColorRect.o: ColorRect/ColorRect.cpp
	$(COMP) $< -o $@
build/Sprite.o: Sprite/Sprite.cpp
	$(COMP) $< -o $@
build/TextField.o: TextField/TextField.cpp
	$(COMP) $< -o $@

	

pch: $(PCH)
$(PCH): SDL/SDL.hpp
	@echo "Don't worry about the warning:"
	@echo ""
	g++ -x c++-header $< -o $@ 

clear:
	rm -f build/*.o
	rm -f build/SDL/*
	rm -f SDL/*.gch
	rm -f $(NAME)
