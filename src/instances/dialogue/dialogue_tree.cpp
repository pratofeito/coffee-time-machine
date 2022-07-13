#include "instances/dialogue/dialogue_tree.hpp"
#include <queue>

DialogueTree::DialogueTree()
{
    raiz = NULL;
}

DialogueTree::~DialogueTree()
{
    // Limpa()
}

Node *DialogueTree::CreateNode(std::string dialogue)
{
    Node *newNode = new Node();

    if (!newNode)
    {
        std::cout << "Memory error\n";
    }
    newNode->data = dialogue;
    newNode->left = newNode->right = NULL;
    return newNode;
}

Node *DialogueTree::InsertNode(Node *root, std::string data)
{
    std::queue<Node *> q;
    q.push(root);

    if (root == NULL)
    {
        root = CreateNode(data);
        return root;
    }

    while (!q.empty())
    {
        Node *leaf = q.front();
        q.pop();

        if (leaf->left != NULL)
            q.push(leaf->left);
        else
        {
            leaf->left = CreateNode(data);
            return root;
        }

        if (leaf->right != NULL)
            q.push(leaf->right);

        else
        {
            leaf->right = CreateNode(data);
            return root;
        }
    }
    return root;
}