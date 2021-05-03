# SET07109 Coursework 2: Makefile		
# -------------------------------------- 
# makefile for building program  	
# ONLY FOR THE MSVC Compiler!
# author: Vinh Phat Tu 					
# last date of modification: April 2021 	
# -------------------------------------- 

# Builds Part A
part_a:
	cl /EHsc /c part_a.cpp symbol_table.cpp Identifier.cpp 
	lib symbol_table.obj Identifier.obj

	cl /EHsc /c formatting.cpp
	lib formatting.obj

	link part_a.obj symbol_table.lib formatting.lib 

# Builds Part B
part_b: 
	cl /EHsc /c part_b.cpp binary_tree.cpp Identifier.cpp
	lib binary_tree.obj Identifier.obj

	cl /EHsc /c formatting.cpp
	lib formatting.obj

	link part_b.obj binary_tree.lib formatting.lib

# Builds Part A & B 
part_ab:
	cl /EHsc /c part_a.cpp symbol_table.cpp Identifier.cpp 
	lib symbol_table.obj Identifier.obj

	cl /EHsc /c part_b.cpp binary_tree.cpp 
	lib binary_tree.obj Identifier.obj

	cl /EHsc /c formatting.cpp
	lib formatting.obj

	link part_a.obj symbol_table.lib formatting.lib 
	link part_b.obj binary_tree.lib formatting.lib

# Builds Part A & B cleanly (keeping only the executables)
part_ab_clean:
	cl /EHsc /c part_a.cpp symbol_table.cpp Identifier.cpp 
	lib symbol_table.obj Identifier.obj

	cl /EHsc /c part_b.cpp binary_tree.cpp 
	lib binary_tree.obj Identifier.obj

	cl /EHsc /c formatting.cpp
	lib formatting.obj

	link part_a.obj symbol_table.lib formatting.lib 
	link part_b.obj binary_tree.lib formatting.lib

	del *.obj
	del *.lib

# Cleaning 
clean:
	del *.obj
	del *.exe
	del *.asm
	del *.lib