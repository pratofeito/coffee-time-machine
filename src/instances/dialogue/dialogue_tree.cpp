#include "instances/dialogue/dialogue_tree.hpp"
#include <queue>

dialogueTree::dialogueTree()
{
    raiz = NULL;
}

dialogueTree::~dialogueTree()
{
    // Limpa()
}

TipoNo *dialogueTree::CreateNode(std::string data)
{
    TipoNo *newNode = new TipoNo();
    if (!newNode)
    {
        std::cout << "Memory error\n";
    }
    newNode->item = data;
    newNode->esq = newNode->dir = NULL;
    return newNode;
}

TipoNo *dialogueTree::InsertNode(TipoNo *root, std::string data)
{
    if (root == NULL)
    {
        root = CreateNode(data);
        return root;
    }

    std::queue<TipoNo *> q;
    q.push(root);

    while (!q.empty())
    {
        TipoNo *temp = q.front();
        q.pop();

        if (temp->esq != NULL)
            q.push(temp->esq);
        else
        {
            temp->esq = CreateNode(data);
            return root;
        }

        if (temp->dir != NULL)
            q.push(temp->dir);
        else
        {
            temp->dir = CreateNode(data);
            return root;
        }
    }
}