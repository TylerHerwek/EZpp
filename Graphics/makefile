NAME := ../Library/libEZ++Graph.a

all:
	$(MAKE) build/Button.o
	$(MAKE) build/Color.o
	$(MAKE) build/ColorRect.o
	$(MAKE) build/Sprite.o
	$(MAKE) build/TextField.o
	ar rcs $(NAME) build/*.o

build/Button.o: Button/Button.cpp
	g++ -c $< -o $@
build/Color.o: Color/Color.cpp
	g++ -c $< -o $@
build/ColorRect.o: ColorRect/ColorRect.cpp
	g++ -c $< -o $@
build/Sprite.o: Sprite/Sprite.cpp
	g++ -c $< -o $@
build/TextField.o: TextField/TextField.cpp
	g++ -c $< -o $@

clear:
	rm -f build/*.o
	rm -f $(NAME)
