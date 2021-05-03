/*
 * SET07109 Coursework 2: Implementing a binary search tree (Part B)
 * -----------------------------------------------------------------
 * header file for binary_tree.cpp
 * author: Vinh Phat Tu (40507973)
 * last date of modification: April 2021
 */
#pragma once

#include "Node.hpp"
#include "Identifier.hpp"

//Implementation can be found in binary_tree.hpp
std::unique_ptr<Node> read_CFile(const std::string &);

void print_inorder(const std::unique_ptr<Node> &);

void write_inorder(const std::unique_ptr<Node> &, std::ofstream &);

void insert(std::unique_ptr<Node> &, const std::shared_ptr<Identifier> &);