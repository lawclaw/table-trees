/*
 * SET07109 Coursework 2: Implementing a binary search tree (Part B)
 * -----------------------------------------------------------------
 * a program that reads a .c file and creates a binary tree 
 * and produces a symbol table which is,
 * - printed to console,
 * - and to a .txt file
 * author: Vinh Phat Tu (40507973)
 * last date of modification: April 2021
 */
#include "binary_tree.hpp"

#include <iostream>
#include <fstream>

using namespace std;

#define TEXT_FILE_NAME "identifiers_tree.txt"

/*
 * Main function: main
 * -------------------
 * collects the first command line argument
 * creates a binary tree,
 * creates symbol table,
 * prints to console,
 * and writes to .txt file
 * 
 * parameters: 
 * - argc: number of command line arguments 
 * - argv: command line arguments
 * 
 * returns: int
 * - 0 = error-free execution
 */
int main(int argc, char** argv)
{
    //Reads in .c file and creates tree
    string CFile_name = argv[1];  
    unique_ptr<Node> tree = read_CFile(CFile_name);

    //Prints symbol table to console
    cout << endl;
    cout << "Symbol table (using binary tree) of: " << CFile_name <<  endl;
    cout << "-------------------------------------------------------------------" << endl; 
    print_inorder(tree); 
    cout << "-------------------------------------------------------------------" << endl; 

    //Writes symbol to .txt file
    ofstream file(TEXT_FILE_NAME);
    write_inorder(tree, file);
    file.close();

    return 0;
}