/*
 * SET07109 Coursework 2: Implementing a compiler symbol table (Part A) / Implementing a binary search tree (Part B)
 * -----------------------------------------------------------------------------------------------------------------
 * implementation functions for formatting.hpp
 * author: Vinh Phat Tu (40507973)
 * last date of modification: April 2021
 */
#include "formatting.hpp"

#include <sstream>  

using namespace std;

/*
 * Function: line_split
 * --------------------
 * splits a string into tokens using a single delimiter
 * 
 * parameters:
 * - str: string to be split
 * - chr: delimiter
 * 
 * returns: vector<string> 
 * - vector of tokens
 */
vector<string> string_split(const string &str, const char chr)
{
    vector<string> tokens;
    stringstream line_stream(str);
    string temp;
        
    while(getline(line_stream,temp, chr))
    {
        tokens.push_back(temp);            
    }   
    return tokens;
}