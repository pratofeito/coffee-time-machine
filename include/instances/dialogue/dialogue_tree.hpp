/**
 * @file dialogue_tree.hpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-07-13
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef DIALOGUE_TREE_H
#define DIALOGUE_TREE_H

#include <iostream>
#include <string>

/**
 * @brief 
 * 
 */

class Node
{
public:

    /**
     * @brief Construct a new Node object
     * 
     */
    Node()
    {
        data = "";
        left = NULL;
        right = NULL;
    }

public:
    std::string data;
    Node *left;
    Node *right;

    friend class Dialogue_Tree;
};


/**
 * @brief 
 * 
 */

class DialogueTree
{
public:
    /**
     * @brief Construct a new Dialogue Tree object
     * 
     */
    DialogueTree();

    /**
     * @brief Destroy the Dialogue Tree object
     * 
     */
    ~DialogueTree();

    /**
     * @brief Create a Node object
     * 
     * @param data 
     * @return Node* 
     */
    Node *CreateNode(std::string data);

    /**
     * @brief 
     * 
     * @param root 
     * @param data 
     * @return Node* 
     */
    Node *InsertNode(Node *root, std::string data);

protected:
    Node *raiz;
};

#endif