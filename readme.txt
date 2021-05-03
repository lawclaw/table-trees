████████╗ █████╗ ██████╗ ██╗     ███████╗      ████████╗██████╗ ███████╗███████╗███████╗
╚══██╔══╝██╔══██╗██╔══██╗██║     ██╔════╝      ╚══██╔══╝██╔══██╗██╔════╝██╔════╝██╔════╝
   ██║   ███████║██████╔╝██║     █████╗  █████╗   ██║   ██████╔╝█████╗  █████╗  ███████╗
   ██║   ██╔══██║██╔══██╗██║     ██╔══╝  ╚════╝   ██║   ██╔══██╗██╔══╝  ██╔══╝  ╚════██║
   ██║   ██║  ██║██████╔╝███████╗███████╗         ██║   ██║  ██║███████╗███████╗███████║
   ╚═╝   ╚═╝  ╚═╝╚═════╝ ╚══════╝╚══════╝         ╚═╝   ╚═╝  ╚═╝╚══════╝╚══════╝╚══════╝                                                                                           

     ccee88oo                                           
  C8O8O8Q8PoOb o8oo                                  
 dOB69QO8PdUOpugoO9bD
CgggbU8OU qOp qOdoUOdcb
    6OuU  /p u gcoUodpP   
      \\\//  /douUP
        \\\////
         |||||                  
         |||\\       
........//||||\.... ┬──────┬ヽ(ಠ-ಠ) ﾉ...................................................................................

README
‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾

    table-trees is a command line program that analyzes .c files, and prints output to a specified .txt file and to the console.
    The program was part of a coursework split into two parts: Part A and Part B
        Part A: Compiler symbol table
        Part B: Binary search tree

FILE STRUCTURE
‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾
    Part A                                          Part B            
    __________________________________              _________________________________
    ├───part_a.exe                   |              ├───part_b.exe                  |
    |   ├───part_a.obj               |              |   ├───part_b.obj              |  
    |   │   └───part_a.cpp           |              |   │   └───part_b.cpp          |
    |   |                            |              |   │                           |
    |   ├───CFile.hpp                |              |   ├───Node.hpp                |
    |   |                            |              |   |                           |
    |   ├───Identifier.hpp           |              |   ├───Identifier.hpp          |
    |   |                            |              |   |                           |
    |   ├───symbol_table.hpp         |              |   ├───binary_tree.hpp         | 
    |   ├───symbol_table.lib         |              |   ├───binary_tree.lib         |
    |   |   ├───symbol_table.obj     |              |   │   ├───binary_tree.obj     |
    |   |   |   └───symbol_table.cpp |              |   |   |   └───binary_tree.cpp |
    |   |   └───Identifier.obj       |              |   |   └───Identifier.obj      |
    |   |       └───Identifier.cpp   |              |   |       └───Identifier.cpp  |
    |   |                            |              |   |                           |
    |   ├───formatting.hpp           |              |   ├───formatting.hpp          |
    |   └───formatting.lib           |              |   └───formatting.lib          |
    |       └───formatting.obj       |              |       └───formatting.obj      |
    |           └───formatting.cpp   |              |           └───formatting.cpp  |
    ‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾              ‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾
    
BUILDING
‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾
    table-trees can be built in multiple ways depending on what is required: 
    NOTE: Makefile included in this project uses the MSVC compiler!

    Part A:

        nmake part_a
    
    Part B:

        nmake part_b
    
    Part A and Part B:

        nmake part_ab 

        - or - 
        
        nmake part_ab_clean (generates executables and cleans up everything else)

USAGE INSTRUCTIONS
‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾
    table-trees can be run in two modes: 
    - Part A - "table": creates a symbol table and writes to a .txt file
    - Part B - "trees": creates a symbol table and prints to console
    
    Part A: 

        part_a "name_of_CFile.c" 
    
    Part B: 

        part_b "name_of_CFile.c"

CLEANING
‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾
    WARNING: This will remove all files in the current directory with the extension: .obj, .asm, .exe, .lib

    after building the application, files can be cleaned by:

        nmake clean

END OF FILE
‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾
    author: Vinh Phat Tu
    date: April 2021
