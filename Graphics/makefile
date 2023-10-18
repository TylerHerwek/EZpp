LIB := ../Library/libEZ++Graph.a
NAME := Graphics
BUILD := ../build/
OUT := $(BUILD)$(NAME)

OBJ := $(OUT)Button.o $(OUT)Color.o $(OUT)ColorRect.o $(OUT)Sprite.o $(OUT)TextField.o

all: $(OBJ)
	ar rcs $(LIB) $(OBJ)
clear:
	rm -f $(LIB)
	rm -f $(OBJ)

$(OUT)Button.o: Button/Button.cpp
	g++ -c $< -o $@
$(OUT)Color.o: Color/Color.cpp
	g++ -c $< -o $@
$(OUT)ColorRect.o: ColorRect/ColorRect.cpp
	g++ -c $< -o $@
$(OUT)Sprite.o: Sprite/Sprite.cpp
	g++ -c $< -o $@
$(OUT)TextField.o: TextField/TextField.cpp
	g++ -c $< -o $@


