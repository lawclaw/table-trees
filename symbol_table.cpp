/*
 * SET07109 Coursework 2: Implementing a compiler symbol table (Part A)
 * --------------------------------------------------------------------
 * implementation functions for reading and writing to files
 * and printing to console
 * author: Vinh Phat Tu (40507973)
 * last date of modification: April 2021
 */
#include "symbol_table.hpp"
#include "formatting.hpp"
#include "Identifier.hpp"

#include <iostream> 
#include <sstream>
#include <fstream>

using namespace std;

/* 
 * Function: read_CFile
 * --------------------
 * reads .c file line by line:
 * - using stringstream split into tokens:
 *  - look for variables and functions 
 *  - add them to list or increase references
 * 
 * parameter: CFile_name - name of the .c file to be read
 *  
 * returns: unique_ptr<CFile> - smart pointer to CFile struct
 * - vector of Identifiers
 * - number of if statements, for & while loops
 */ 
unique_ptr<CFile> read_CFile(const string &CFile_name) 
{
    //General vectors for storing Identifiers
    vector<shared_ptr<Identifier>> local_identifiers;
    vector<shared_ptr<Identifier>> functions;
    vector<shared_ptr<Identifier>> all_identifiers;

    //Arrays for checking C related keywords
    const string primitives[] = {"char*", "short*", "int*", "long*",  "float*", "double*",
                            "char", "short", "int", "long", "float", "double", "void"};
    const string conditions[3] = {"if","for","while"};
    int condition_quantities[3] = {0};

    //Line counter
    int line_number = 0;

    //Variable to store the current function name
    string function_name;

    //Temporary variables for reading strings and looping through tokens
    string line;
    string token;

    //Reading in .c file
    ifstream input_CFile(CFile_name);
    while(getline(input_CFile, line))
    {
        line_number++;

        //Split line into tokens
        stringstream stream(line);
        while(stream >> token)
        {             
            /*
             * Look for references
             * -------------------
             * Loop through all local identifiers
             * - If name is equal to token -> add reference to identifier
             */
            for (auto identifier : local_identifiers)
            {
                vector<string> temp;
                if (identifier->get_name().find("(") != string::npos)
                {
                    temp = string_split(identifier->get_name(), ' ');
                } 
                else 
                {
                    temp.push_back(identifier->get_name());
                }
                if (token == temp[0])
                {
                    identifier->add_reference();
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
                     *  - Add function to functions (vector)
                     *  - Assign name of function to function_name
                     *  - Copy all variables in local_identifiers to all_identifiers
                     *  - Clear local_identifiers
                     *  - Add all functions to local_identifiers 
                     * -------------------------------------------------------------
                     * Else -> Variable
                     *  - Look for [] (array declaration)
                     *   - If true, add [] to type
                     *  - Add variable to local identifier vector
                     */
                    if (token == "(")  //Function
                    {
                        auto func = make_shared<Identifier>(type, name, line_number);
                        function_name = name;
                        functions.push_back(func);
                        for (auto identifier : local_identifiers)
                        {
                            if (identifier->get_name().find("(") != string::npos)
                            {
                                all_identifiers.push_back(identifier);
                            }
                        }
                        local_identifiers.clear();
                        for (auto function : functions)
                        {
                            local_identifiers.push_back(function);
                        }
                        break;
                    } 
                    else   //Variable
                    {
                        if (token == "[]")
                        {
                            type += " []";
                        }

                        //Add function name at the end of variable name
                        string var_name = name + " (" + function_name + ")";        
                        auto var = make_shared<Identifier>(type, var_name, line_number);
                        local_identifiers.push_back(var);
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

    //Retrieve the last set of identifiers/functions
    for (auto local_identifier : local_identifiers)
    {
        all_identifiers.push_back(local_identifier);
    } 

    //Create CFile struct and return smart pointer
    auto file_struct_ptr = make_unique<CFile>(all_identifiers, condition_quantities[0], condition_quantities[1], condition_quantities[2]);

    return file_struct_ptr;
}      

/*
 * Function: write_symbol_table
 * ----------------------------
 * (creates &) writes to TEXT_FILE_NAME.txt
 * 
 * parameter: file_struct_ptr - smart pointer to a CFile struct
 * 
 * returns: void
 * - TEXT_FILE_NAME.txt created in current directory containing symbol table
 */
void write_symbol_table(const unique_ptr<CFile> &file_struct_ptr, ofstream &output_file)
{
    for (auto identifier : file_struct_ptr->identifiers)
    {
        output_file << identifier->get_name() << ", line " << identifier->get_line_number();
        if (identifier->get_name().find("(") == string::npos)
        {
            output_file << ", function, ";           
        } 
        else  
        {
            output_file << ", variable, ";
        }
        output_file << identifier->get_type();
        output_file << ", referenced " << identifier->get_references() << endl; 
    }
}

/*
 * Function: print_output
 * ----------------------
 * prints quantities from CFile struct to console:
 *  - Variables
 *  - Functions
 *  - If statements
 *  - For loops
 *  - While loops
 * 
 * parameter: file - smart pointer to a CFile struct 
 * 
 * returns: void 
 * - prints to console
 */
void print_output(const unique_ptr<CFile> &file_struct_ptr)
{  
    int var_qty = 0;
    int func_qty;
    for (auto identifier : file_struct_ptr->identifiers)
    {
        if (identifier->get_name().find("(") != string::npos)
        {
            var_qty++;
        }
    }
    func_qty = file_struct_ptr->identifiers.size() - var_qty;

    cout << "Variables: " << var_qty << endl;
    cout << "Functions: " << func_qty << endl;
    cout << "If statements: " << file_struct_ptr->if_qty << endl;
    cout << "For loops: " << file_struct_ptr->for_qty << endl;
    cout << "While loops: " << file_struct_ptr->while_qty << endl;
}