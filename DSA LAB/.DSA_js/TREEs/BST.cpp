// Binary Search Tree:
// Properties:
// 1. All nodes of the left subtree are lesser.
// 2. ALl nodes of the right subtree are greater.
// 3. Left & right subtrees are also BST.
// 4. There are no duplicate nodes.
// 5. Inorder traversal of a BST gives an Ascending array.
// - useful to check whether a tree is BST or not.

// Problem-1: Search(val)
#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node *left;
    Node *right;
    // Node(int val) : data(val), left(nullptr), right(nullptr) {}
};
Node *createNode(int data)
{
    Node *newNode = new Node;
    newNode->data = data;
    newNode->left = nullptr;
    newNode->right = nullptr;
    return newNode;
}
void inorder_traversal(Node *root)
{
    if (root != NULL)
    {
        inorder_traversal(root->left);
        cout << root->data << " ";
        inorder_traversal(root->right);
    }
}
int isBST(struct Node *root)
{
    if (root != NULL)
    {
        if (!isBST(root->left))
        {
            return 0;
        }
    }
    else
    {
        return 1;
    }
}
int main()
{
    Node *p = createNode(5);
    Node *p1 = createNode(3);
    Node *p2 = createNode(6);
    Node *p3 = createNode(1);
    Node *p4 = createNode(4);

    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;

    cout << "\nInOrder: ";
    inorder_traversal(p);
    return 0;
}