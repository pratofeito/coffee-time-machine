/**
 * @file dialogue_tree.hpp
 * @author brisabn
 * @brief definições da classe dialogue_tree  e de node
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
 * @brief Cria uma classe Node
 * 
 */

class Node
{
public:

    /**
     * @brief Constrói um objeto do tipo Node
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
 * @brief Cria uma classe DialogueTreee
 * 
 */

class DialogueTree
{
public:
    /**
     * @brief Constrói um objeto do tipo DialogueTree
     * 
     */
    DialogueTree();

    /**
     * @brief Destrói o objeto DialogueTree
     * 
     */
    ~DialogueTree();

    /**
     * @brief Constrói um objeto Node
     * 
     * @param data 
     * @return Node* 
     */
    Node *CreateNode(std::string data);

    /**
     * @brief insere um Node na fila
     * 
     * @param root Parametro do tipo Node ponteiro passado pelo metodo insertNode 
     * @param data Parametro do tipo String  passado pelo metodo insertNode
     * @return Node* 
     */
    Node *InsertNode(Node *root, std::string data);

protected:
    Node *raiz;
};

#endif