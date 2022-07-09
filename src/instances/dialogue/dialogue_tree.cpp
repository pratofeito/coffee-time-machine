#include "instances/dialogue/dialogue_tree.hpp"
#include <queue>

Dialogue_Tree::Dialogue_Tree()
{
    raiz = NULL;
}

Dialogue_Tree::~Dialogue_Tree()
{
    // Limpa()
}

Node *Dialogue_Tree::CreateNode(std::string data)
{
    Node *newNode = new Node();

    if (!newNode)
    {
        std::cout << "Memory error\n";
    }
    newNode->item = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

Node *Dialogue_Tree::InsertNode(Node *root, std::string data)
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