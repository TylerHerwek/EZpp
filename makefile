all:
	@echo "Compiling sourcecode into the libary..."
	cd src && $(MAKE)
	@echo "First library done! Located here: /lib/libNodes.a."
	@echo ""
	cd ext && $(MAKE)
	@echo "Second library done! Located here: /lib/libNodes_Extentions.a"
	@echo ""

help:
	@echo "make: builds the libary from the source directory"
	@echo "make clear: clears libary files"

clear:
	cd src && $(MAKE) clear
	cd ext && $(MAKE) clear
	@echo "cleared librarys"
