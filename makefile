NAME := Library/libEZ++.a

all:
	@echo "Compiling sourcecode into the libary..."
	cd Functionality && $(MAKE)
	@echo "First library done!"
	@echo ""
	cd Graphics && $(MAKE)
	@echo "Second library done!"
	@echo ""
	cd Extentions && $(MAKE)
	@echo "Third library done!"
	@echo ""
	ar -x Library/libEZ++Ext.a 
	ar -x Library/libEZ++Func.a 
	ar -x Library/libEZ++Graph.a 
	ar rcs $(NAME) *.o
	rm *.o

help:
	@echo "make: builds the libary from the source directory"
	@echo "make clear: clears libary files"

clear:
	cd Functionality && $(MAKE) clear
	cd Graphics && $(MAKE) clear
	cd Extentions && $(MAKE) clear
	rm -f $(NAME)
	@echo "cleared librarys"
