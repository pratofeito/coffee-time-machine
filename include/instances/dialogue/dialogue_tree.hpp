#ifndef DIALOGUETREE_HPP
#define DIALOGUETREE_HPP

#include <iostream>
#include <string>

class TipoNo
{
public:
    TipoNo()
    {
        item = "";
        esq = NULL;
        dir = NULL;
    }

public:
    std::string item;
    TipoNo *esq;
    TipoNo *dir;

    friend class dialogueTree;
};

class dialogueTree
{
public:
    dialogueTree();
    ~dialogueTree();
    TipoNo *CreateNode(std::string data);
    TipoNo *InsertNode(TipoNo *root, std::string data);
    void Limpa();

protected:
    TipoNo *raiz;
};

#endif