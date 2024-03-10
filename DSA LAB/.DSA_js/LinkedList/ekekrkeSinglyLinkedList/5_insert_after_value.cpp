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

anode *insertAfterValue(anode *head, int value, int data)
{
    anode *ptr = head;

    anode *q = (anode *)malloc(sizeof(anode));
    q->data = data;

    while (ptr->next != NULL)
    {
        if (ptr->data == value)
        {
            q->next = ptr->next;
            ptr->next = q;
            return q;
        }
        ptr = ptr->next;
    }
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
    cout << "Before Insertion: " << endl;
    linked_list_traversal(head);

    insertAfterValue(head, 10, 50);
    cout << "After insertion" << endl;

    linked_list_traversal(head);
    return 0;
}