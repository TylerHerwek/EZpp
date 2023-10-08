LIB_OUT := ../lib/libEZ++_Ext.a
PCH_INC := -include ../src/SDL/SDL.hpp

INC := -L"../lib" -I"../inc" 
LIB := -lEZ++

COMP := g++ -c $(PCH_INC) $(INC)

all:
	$(MAKE) build/Main.o 
	$(MAKE) build/Events.o 
	ar rcs $(LIB_OUT) build/*.o

build/Main.o: Main/Main.cpp
	$(COMP) $< $(LIB) -o $@
build/Events.o: Events/Events.cpp
	$(COMP) $< $(LIB) -o $@

clear:
	rm build/*
	rm $(LIB_OUT)
