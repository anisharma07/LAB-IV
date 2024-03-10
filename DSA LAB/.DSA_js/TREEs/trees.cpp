// Tree:
//         4
//        / \
//       1   6
//      / \
//     5   2

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
void preorder_traversal(Node *root)
{

    if (root != NULL)
    {
        cout << root->data << " ";
        preorder_traversal(root->left);
        preorder_traversal(root->right); // 26
    }
}
void postorder_traversal(Node *root)
{

    if (root != NULL)
    {
        postorder_traversal(root->left);
        postorder_traversal(root->right);
        cout << root->data << " ";
    }
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
int main()
{
    Node *p = createNode(4);
    Node *p1 = createNode(1);
    Node *p2 = createNode(6);
    Node *p3 = createNode(5);
    Node *p4 = createNode(2);

    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;
    cout << "Pre: ";
    preorder_traversal(p);
    cout << endl;
    cout << "Post: ";
    postorder_traversal(p);
    cout << "\nInOrder: ";
    inorder_traversal(p);
    return 0;
}