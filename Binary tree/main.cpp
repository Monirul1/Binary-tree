#include <iostream>
#include <queue>
using namespace std;

struct Node
{
    int data;
    struct Node *left, *right;
};

void printLevelOrder(Node *root);

Node* newNode(int data);

int main()
{
    Node *root = newNode(3);
    root->left = newNode(9);
    root->right = newNode(20);
    root->left->left = newNode(15);
    root->left->right = newNode(7);
    
    cout << "Level Order traversal of binary tree is: " << endl;
    printLevelOrder(root);
    return 0;
}

Node* newNode(int data)
{
    Node *temp = new Node;
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

void printLevelOrder(Node *root)
{
    if (root == NULL)
        return;
    
    queue<Node* > q;
    
    q.push(root);
    
    while (!q.empty())
    {
        
        Node *node = q.front();
        cout << node->data << " " << endl;
        q.pop();
        
        if (node->left != NULL)
            q.push(node->left);
        
        if (node->right != NULL)
            q.push(node->right);
    }

}

