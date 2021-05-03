/*
 * SET07109 Coursework 2: Implementing a compiler symbol table (Part A)
 * --------------------------------------------------------------------
 * struct declaration for CFile 
 * author: Vinh Phat Tu (40507973)
 * last date of modification: April 2021
 */
#pragma once

#include "Identifier.hpp"

#include <memory>
#include <vector>

/*
 * Struct: CFile
 * -------------
 * stores information of a .c file
 * - vector of Functions
 * - number of if statements
 * - number of for loops
 * - number of while loops
 */
struct CFile
{
    /*
     * Method: CFile - Constructor
     * ---------------------------
     * constructor for Node struct
     * - assigns all information of .c file
     * 
     * parameters
     * - identifiers - vector of Identifiers
     * - if_qty = number of if statements
     * - for_qty = number of for loops
     * - while_qty = number of while loops
     */     
    CFile(const std::vector<std::shared_ptr<Identifier>> &identifiers, const int if_qty, const int for_qty, const int while_qty)
    {
        this->identifiers = identifiers;
        this->if_qty = if_qty;
        this->for_qty = for_qty;
        this->while_qty = while_qty;
    }

    std::vector<std::shared_ptr<Identifier>> identifiers;

    int if_qty;
    int for_qty;
    int while_qty;
};