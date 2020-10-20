#	This is Makefile									
#	Always use a CAPITAL M								
#	It technically doesn't matter but it looks nice and 
#	you won't accidentally make two makefiles

#	Do not worry about the slashes on these comments 	
#	that's just how to do a multi line comment in a 	
#	makefile

#	This is like a variable name in C++ code			
#	We can use this so here so vscode can autocomplete 	
#	and we can change the executable name				
#	point_ref_exe_name = point_ref_example. This 		
#	variable shows we will compile using g++ and using	
#	C++ 11
POINT_REF_EXE_NAME = point_ref_exe
MEM_ALLOC = mem_alloc_exe
SIMPLE_CLASS_EXE_NAME = simple_class_exe
COMPILE = g++ -std=c++11

#	These two lines make an executable file with the 	
#	same name as the point_ref_exe_name variable. 		
#	Makefiles work in such a way that they will only 	
#	recompile if there dependencies (the files after the
#	colon) are changed. If point_ref_example.cpp is		
#	changed then the executable will recompile. I don't	
#	think they actually teach you this in class			
#	To compile this write "make point_ref"
$(POINT_REF_EXE_NAME): point_ref.cpp
	$(COMPILE) point_ref.cpp -o $(POINT_REF_EXE_NAME)
$(MEM_ALLOC): mem_alloc.cpp
	$(COMPILE) mem_alloc.cpp -o $(MEM_ALLOC)
$(SIMPLE_CLASS_EXE_NAME): classes_example.cpp
	$(COMPILE) classes_example.cpp -o $(SIMPLE_CLASS_EXE_NAME)

#	Clean gets rid of all executables and any .o files.
#	This will make the computer recompile everything
clean:
	rm -f $(POINT_REF_EXE_NAME) $(MEM_ALLOC) $(SIMPLE_CLASS_EXE_NAME) *.o