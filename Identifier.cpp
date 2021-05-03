/*
 * SET07109 Coursework 2: Implementing a compiler symbol table (Part A) / Implementing a binary search tree (Part B)
 * -----------------------------------------------------------------------------------------------------------------
 * implementation functions for Identifier class
 * author: Vinh Phat Tu (40507973)
 * last date of modification: April 2021
 */
#include "Identifier.hpp"

using namespace std;

/*
 * Method: Identifier - Constructor
 * ----------------------------------
 * constructor for Identifier class:
 * - assigns all variables 
 *  
 * parameters: 
 * - type: return type
 * - name: name of function
 * - line_number: line number of declaration
 */
Identifier::Identifier(const string &type, const string &name, int line_number)
{
    this->type = type;
    this->name = name;
    this->line_number = line_number;
}

/*
 * Method: get_name - Getter
 * ------------------------- 
 * returns name of Identifier
 *  
 * parameters: none
 * 
 * returns: string - containing name of Identifier
 */
string Identifier::get_name() const
{
    return name;
}

/*
 * Method: get_line_number - Getter
 * --------------------------------
 * returns line number of declaration
 * 
 * parameters: none
 * 
 * returns: int - line number of declaration
 */
int Identifier::get_line_number() const
{
    return line_number;
}

/*
 * Method: get_references - Getter
 * -------------------------------
 * returns number of references
 *
 * parameters: none
 * 
 * returns: int - number of times referenced
 */
int Identifier::get_references() const
{
    return references;
}

/*
 * Method: get_type - Getter
 * -------------------------
 * returns type of Identifier
 * 
 * parameters: none
 * 
 * returns: string - primitive type or return type
 */
string Identifier::get_type() const
{
    return type;
}

/*
 * Method: add_reference
 * ---------------------
 * increments reference count by 1
 * 
 * parameters: none
 * 
 * returns: void
 */
void Identifier::add_reference()
{
    references++;
}