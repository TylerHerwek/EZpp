LIB := ../Library/libEZ++Func.a
NAME := Functionality
BUILD := ../build/
OUT := $(BUILD)$(NAME)

OBJ := $(OUT)Point.o $(OUT)Rect.o $(OUT)Window.o $(OUT)SDL.o

all: $(OBJ)
	ar rcs $(LIB) $(OBJ) 
clear:
	rm -f $(OBJ)
	rm -f $(LIB)

$(OUT)Point.o: Point/Point.cpp
	g++ -c $< -o $@
$(OUT)Rect.o: Rect/Rect.cpp
	g++ -c $< -o $@
$(OUT)Window.o: Window/Window.cpp
	g++ -c $< -o $@
$(OUT)SDL.o: SDL/SDL.hpp
	g++ -c $< -o $@


