/*
 * SET07109 Coursework 2: Implementing a binary search tree (Part B)
 * -----------------------------------------------------------------
 * struct declaration for Node 
 * author: Vinh Phat Tu (40507973)
 * last date of modification: April 2021
 */
#pragma once

#include "Identifier.hpp"
#include <memory>

/*
 * Struct: Node
 * ------------
 * stores a node in a binary tree:
 * - identifier: smart pointer to an Identifier object
 * - left_node: smart pointer to the left node
 * - right_node: smart pointer to the right node
 */
struct Node
{
    /*
     * Method: Node - Constructor
     * ----------------------------
     * constructor for Node struct
     * - assigns Identifier pointer
     * 
     * parameter: identifier - smart pointer to an Identifier
     */   
    Node(std::shared_ptr<Identifier> identifier)
    {
        this->identifier = identifier;
    } 

    std::shared_ptr<Identifier> identifier;
    std::unique_ptr<Node> left_node;
    std::unique_ptr<Node> right_node;
};