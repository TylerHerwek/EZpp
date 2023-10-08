NAME := ../Library/libEZ++Func.a

all:
	$(MAKE) build/Point.o
	$(MAKE) build/Rect.o
	$(MAKE) build/Window.o
	$(MAKE) build/SDL.o
	ar rcs $(NAME) build/*.o

build/Point.o: Point/Point.cpp
	g++ -c $< -o $@
build/Rect.o: Rect/Rect.cpp
	g++ -c $< -o $@
build/Window.o: Window/Window.cpp
	g++ -c $< -o $@
build/SDL.o: SDL/SDL.hpp
	g++ -c $< -o $@

clear:
	rm -f build/*.o
	rm -f $(NAME)
