/*
 * SET07109 Coursework 2: Implementing a compiler symbol table (Part A)
 * --------------------------------------------------------------------
 * header file for symbol_table.cpp
 * author: Vinh Phat Tu (40507973)
 * last date of modification: April 2021
 */
#pragma once

#include "CFile.hpp"

//Implementation in symbol_table.cpp
std::unique_ptr<CFile> read_CFile(const std::string &);

void write_symbol_table(const std::unique_ptr<CFile> &, std::ofstream &);

void print_output(const std::unique_ptr<CFile> &); 