NAME := ../Library/libEZ++Ext.a

all:
	$(MAKE) build/Main.o 
	$(MAKE) build/Events.o 
	ar rcs $(NAME) build/*.o

build/Main.o: Main/Main.cpp
	g++ -c $< -o $@
build/Events.o: Events/Events.cpp
	g++ -c $< -o $@

clear:
	rm -f build/*
	rm -f $(NAME)
