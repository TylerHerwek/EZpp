NAME := ../Library/libEZ++Func.a

all:
	$(MAKE) build/Point.o
	$(MAKE) build/Rect.o
	$(MAKE) build/Window.o
	$(MAKE) build/SDL.o
	ar rcs $(NAME) build/*.o


COMP := g++ -c

build/Point.o: Point/Point.cpp
	$(COMP) $< -o $@
build/Rect.o: Rect/Rect.cpp
	$(COMP) $< -o $@
build/Window.o: Window/Window.cpp
	$(COMP) $< -o $@
build/SDL.o: SDL/SDL.hpp
	g++ -c $(INC) $< $(LIB) -o $@
