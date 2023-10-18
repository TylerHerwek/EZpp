LIB := ../Library/libEZ++Ext.a
NAME := Extentions
BUILD := ../build/
OUT := $(BUILD)$(NAME)

OBJ := $(OUT)Main.o $(OUT)Events.o 

all: $(OBJ)
	ar rcs $(LIB) $(OBJ)
clear:
	rm -f $(OBJ)
	rm -f $(LIB)

$(OUT)Main.o: Main/Main.cpp
	g++ -c $< -o $@
$(OUT)Events.o: Events/Events.cpp
	g++ -c $< -o $@


