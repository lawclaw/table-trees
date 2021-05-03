/*
 * SET07109 Coursework 2: Implementing a compiler symbol table (Part A)
 * --------------------------------------------------------------------
 * a program that reads a .c file and creates a symbol table which is,
 * - printed to console,
 * - and to a .txt file
 * author: Vinh Phat Tu (40507973)
 * last date of modification: April 2021
 */
#include "symbol_table.hpp"

#include <iostream> 
#include <fstream>

using namespace std;

#define TEXT_FILE_NAME "identifiers.txt"

/*
 * Main function: main
 * -------------------
 * collects the first command line argument,
 * creates symbol table,
 * prints to console,
 * and writes to a .txt file
 * 
 * parameters: 
 * - argc: number of command line arguments 
 * - argv: command line arguments
 * 
 * returns: int
 * - 0 = error-free execution
 */
int main(int argc, char **argv)
{   
    //Read in .c file and create struct
    string CFile_name = argv[1];  
    unique_ptr<CFile> file_struct_ptr = read_CFile(CFile_name);
    
    //Prints symbol table to console
    cout << endl;
    cout << "Symbol table of: " << CFile_name << endl;
    cout << "------------------------" << endl;
    print_output(file_struct_ptr);
    cout << "------------------------" << endl;

    //Write table to .txt file
    ofstream file(TEXT_FILE_NAME);
    write_symbol_table(file_struct_ptr, file);
    file.close();

    return 0;
}