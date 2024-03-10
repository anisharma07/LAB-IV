// Verified
#include <iostream>
using namespace std;

typedef struct Node
{
    int data;
    Node *next;
} anode;

void linked_list_traversal(anode *head)
{
    cout << "Elements: ";
    while (head->next != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << head->data << endl;
}

Node *rev(Node *a)
{
    if (a == nullptr || a->next == nullptr)
    {
        return a;
    }
    Node *chut = rev(a->next);
    a->next->next = a;
    a->next = nullptr;
    return chut;
}

int main()
{
    anode *head = (anode *)malloc(sizeof(anode));
    anode *second = (anode *)malloc(sizeof(anode));
    anode *third = (anode *)malloc(sizeof(anode));
    anode *fourth = (anode *)malloc(sizeof(anode));

    head->data = 5;
    head->next = second;

    second->data = 10;
    second->next = third;

    third->data = 12;
    third->next = fourth;

    fourth->data = 4;
    fourth->next = NULL;
    linked_list_traversal(head);
    Node *k = rev(head);
    linked_list_traversal(k);
    return 0;
}
