/*
 * SET07109 Coursework 2: Implementing a compiler symbol table (Part A) / Implementing a binary search tree (Part B)
 * -----------------------------------------------------------------------------------------------------------------
 * class declaration for Identifier
 * author: Vinh Phat Tu (40507973)
 * last date of modification: April 2021
 */
#pragma once

#include <string>

/*
 * Class: Identifier
 * -----------------
 * stores an identifier:
 * - name: name of the identifier
 * - type: return type or primitive type
 * - line_number: line number of declaration
 * - references: times referenced in file
 */
class Identifier
{
    public:
        //Constructors
        Identifier() = default;
        Identifier(const std::string &type, const std::string &name, int line_number);

        //Getters
        std::string get_name() const;
        int get_line_number() const;
        int get_references() const;
        std::string get_type() const;
        
        void add_reference();

    protected:
        std::string name;
        std::string type;
        int line_number;
        int references = 0;
};