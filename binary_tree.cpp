/*
 * SET07109 Coursework 2: Implementing a binary search tree (Part B)
 * -----------------------------------------------------------------
 * implementation functions for reading and writing to files 
 * - using binary trees
 * author: Vinh Phat Tu (40507973)
 * last date of modification: April 2021
 */
#include "Identifier.hpp"
#include "binary_tree.hpp"
#include "formatting.hpp"

#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

/* 
 * Function: read_CFile
 * --------------------
 * reads .c files line by line:
 * - using stringstream split into tokens:
 *  - look for variables and functions 
 *  - add them to tree or increase references
 * 
 * parameter: CFile_name - name of the .c file to be read
 *  
 * returns: unique_ptr<Node> - smart pointer to top node of tree
 * - a binary tree containing all identifiers
 */ 
unique_ptr<Node> read_CFile(const string &CFile_name) 
{
    //Top node of the binary tree
    unique_ptr<Node> tree;

    //General string vectors for keeping track of identifiers
    vector<string> identifier_names;
    vector<string> all_identifier_names;
    vector<string> function_strings;

    //Arrays for checking C related keywords
    const string primitives[] = {"char*", "short*", "int*", "long*",  "float*", "double*",
                            "char", "short", "int", "long", "float", "double", "void"};
    const string conditions[3] = {"if","for","while"};
    int condition_quantities[3] = {0};

    //Line counter
    int line_number = 0;

    //Variable to store the current function name
    string function_name;

    //Temporary variables for reading in strings and looping through tokens
    string line;
    string token;

    //Reading in .c file
    ifstream input_CFile(CFile_name);
    while(getline(input_CFile, line))
    {
        line_number++;

        stringstream stream(line);
        while(stream >> token)
        {             
            /*
             * Look for references
             * -------------------
             * Loop through all local identifiers
             * - If name is equal to token -> create a temporary node with name
             */
            for (auto identifier : identifier_names)
            {   
                vector<string> temp;
                if (identifier.find("(") != string::npos)
                {
                    temp = string_split(identifier, ' ');
                } 
                else 
                {
                    temp.push_back(identifier);
                }
                if (token == temp[0])
                {   
                    auto temp = make_shared<Identifier>("", identifier, 0);
                    insert(tree,temp);
                }
            }

            /*
             * Look for declarations
             * ---------------------
             * Token pattern of declarations:
             * - type, name... -> Variable
             * or 
             * - type, name, (... -> Function
             * 
             * ex. 
             * "int a = 1;" -> type = int, name = a
             */
            for (auto primitive : primitives)
            {
                if (token == primitive)
                {
                    string type = primitive;
                    stream >> token;

                    /*
                     * If the next token is the same as the previous one
                     * ex. "long long"
                     * - assign it to type
                     * - go to next token
                     */ 
                    if (token == type)
                    {
                        type += " " + type;
                        stream >> token;
                    }

                    string name = token;

                    stream >> token;   

                    /*
                     * If the token is "(" -> Function
                     *  - Add function name to function_string
                     *  - Add new node in tree
                     *  - Assign name of function to function_name
                     *  - Copy all variable names in identifier_names to all_identifier_names
                     *  - Clear identifier_names
                     *  - Add all function names to identifier_names
                     * ----------------------------------------------------------------------
                     * Else -> Variable
                     *  - Look for [] (array declaration)
                     *   - If true, add [] to type
                     *  - Add variable name to identifier_names 
                     *  - Add new node in tree
                     */ 
                    if (token == "(")   //Function
                    {
                        auto func = make_shared<Identifier>(type, name, line_number);
                        insert(tree, func);
                        function_name = name;
                        function_strings.push_back(name);

                        for (auto identifier_name : identifier_names)
                        {
                            if (identifier_name.find("(") != string::npos)
                            {
                                all_identifier_names.push_back(identifier_name);
                            }
                        }

                        identifier_names.clear();

                        for (auto function_string : function_strings)
                        {
                            identifier_names.push_back(function_string);
                        }

                        break;
                    } 
                    else  //Variable
                    {
                        if (token == "[]")
                        {
                            type += " []";
                        }
                        string var_name = name + " (" + function_name + ")";
                        auto var = make_shared<Identifier>(type, var_name, line_number);
                        insert(tree, var);
                        identifier_names.push_back(var_name);
                        break;
                    }
                }
            }

            /*
             * Look for if,for and while
             * -------------------------
             * Loop through array of keywords,
             * - If keyword is found, 
             *  - Increment at current index in quantities array
             */
            for (int i = 0; i < 3; i++)
            {
                if (conditions[i] == token)
                {
                    condition_quantities[i]++;
                }
            }
        } 
    }

    return tree;
}

/*
 * Function: insert
 * ----------------
 * inserts Identifier into binary tree
 * or adds reference if it already exists
 * 
 * parameters: 
 * - node: smart pointer to tree node
 * - identifier: identifier to be added/updated
 * 
 * returns: void
 * - new node is created
 * - or a reference is added
 * 
 */
void insert(unique_ptr<Node> &node, const shared_ptr<Identifier> &identifier)
{
    if (node == nullptr)
    {
        node = make_unique<Node>(identifier);
    } 
    else
    {
        if (identifier->get_name() < node->identifier->get_name())
        {
            insert(node->left_node, identifier);
        } 
        else if (identifier->get_name() > node->identifier->get_name())
        {
            insert(node->right_node, identifier);
        } 
        else 
        {
            node->identifier->add_reference();    
        }
    }
}

/*
 * Function: print_inorder
 * -----------------------
 * prints all the nodes in alphabetical order
 * using recursion
 * 
 * parameter: tree - top node of binary tree
 * 
 * returns: void
 * - prints all the nodes to console
*/
void print_inorder(const unique_ptr<Node> &tree)
{
    if (tree != nullptr)
    {
        //Prints all in alphabetical order
        print_inorder(tree->left_node);
        cout << tree->identifier->get_name() << ", line ";
        cout << tree->identifier->get_line_number() << ", ";
        if (tree->identifier->get_name().find("(") != string::npos)
        {
            cout << "variable, ";
        } 
        else 
        {
            cout << "function, ";
        }
        cout << tree->identifier->get_type() << ", referenced ";
        cout << tree->identifier->get_references() << endl; 
        print_inorder(tree->right_node); 
    }
}

/*
 * Function: write_inorder
 * -----------------------
 * writes all the nodes in alphabetical order
 * to .txt file
 * using recursion
 * 
 * parameters:
 * - tree - top node of binary tree
 * - file - .txt file
 * 
 * returns: void
 * - writes all the nodes to .txt file
*/
void write_inorder(const unique_ptr<Node> &tree, ofstream &file)
{
    if (tree != nullptr)
    {
        //Print the most left nodes
        write_inorder(tree->left_node, file);

        file << tree->identifier->get_name() << ", line ";
        file << tree->identifier->get_line_number() << ", ";
        if (tree->identifier->get_name().find("(") != string::npos)
        {
            file << "variable, ";
        } 
        else 
        {
            file << "function, ";
        }
        file << tree->identifier->get_type() << ", referenced ";
        file << tree->identifier->get_references() << endl; 

        //Print the most right nodes
        write_inorder(tree->right_node, file); 
    }    
}