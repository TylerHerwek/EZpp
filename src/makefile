CXX := g++

LIB := -lSDL2 -lSDL2main -lSDL2_image -lSDL2_ttf
DIR := $(wildcard */)
INC := $(addprefix -I, $(DIR))

PCH := SDL/SDL.hpp.gch
LIB_OUT := ../lib/libEZ++.a

COMP := g++ -c -include SDL/SDL.hpp $(INC)

.PHONY: all rebuild_all

all:
	$(MAKE) build/Button.o
	$(MAKE) build/Color.o
	$(MAKE) build/ColorRect.o
	$(MAKE) build/Point.o
	$(MAKE) build/Rect.o
	$(MAKE) build/Sprite.o
	$(MAKE) build/TextField.o
	$(MAKE) build/Window.o
	$(MAKE) build/SDL.o
	ar rcs $(LIB_OUT) build/*.o

build/Button.o: Button/Button.cpp
	$(COMP) $< $(LIB) -o $@
build/Color.o: Color/Color.cpp
	$(COMP) $< $(LIB) -o $@
build/ColorRect.o: ColorRect/ColorRect.cpp
	$(COMP) $< $(LIB) -o $@
build/Point.o: Point/Point.cpp
	$(COMP) $< $(LIB) -o $@
build/Rect.o: Rect/Rect.cpp
	$(COMP) $< $(LIB) -o $@
build/Sprite.o: Sprite/Sprite.cpp
	$(COMP) $< $(LIB) -o $@
build/TextField.o: TextField/TextField.cpp
	$(COMP) $< $(LIB) -o $@
build/Window.o: Window/Window.cpp
	$(COMP) $< $(LIB) -o $@
build/SDL.o: SDL/SDL.hpp
	g++ -c $(INC) $< $(LIB) -o $@


pch: $(PCH)
$(PCH): SDL/SDL.hpp
	@echo "Don't worry about the warning:"
	@echo ""
	g++ -x c++-header $< -o $@ 

clear:
	rm -f build/*
	rm -f SDL/*.gch
	rm -f $(LIB_OUT)
