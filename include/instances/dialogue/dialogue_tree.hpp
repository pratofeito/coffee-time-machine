#ifndef DIALOGUE_TREE_H
#define DIALOGUE_TREE_H

#include <iostream>
#include <string>

class Node
{
public:
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

class Dialogue_Tree
{
public:
    Dialogue_Tree();
    ~Dialogue_Tree();
    Node *CreateNode(std::string data);
    Node *InsertNode(Node *root, std::string data);
    void Limpa();

protected:
    Node *raiz;
};

#endif