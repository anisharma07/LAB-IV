// NOT WORKING FOR INSERT AT FIRST...problem: Unable to update the Head NODE.
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

// Me
anode *insertIntoSorted(anode *head, int data)
{
    anode *ptr = head;
    anode *q = (anode *)malloc(sizeof(anode));
    q->data = data;
    if (head == NULL || data < head->data)
    {
        q->next = ptr;
        ptr = q;
    }
    else
    {
        while (ptr->next != NULL && ptr->next->data < data)
        {
            ptr = ptr->next;
        }
        q->next = ptr->next;
        ptr->next = q;
    }
    return ptr;
}

// Neso
anode *insertInSorted(anode *head, int data)
{
    anode *ptr;
    anode *q = (anode *)malloc(sizeof(anode));
    q->data = data;
    q->next = NULL;

    int key = data;
    if (head == NULL || key < head->data)
    {
        q->next = head;
        head = q;
    }

    else
    {
        ptr = head;
        while (ptr->next != NULL && ptr->next->data < key)
            ptr = ptr->next;
        q->next = ptr->next;
        ptr->next = q;
    }
    return head;
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

    fourth->data = 40;
    fourth->next = NULL;

    cout << "Before Insertion: " << endl;
    linked_list_traversal(head);

    insertInSorted(head, 4);
    insertInSorted(head, 14);
    insertInSorted(head, 41);

    cout << "After insertion" << endl;
    linked_list_traversal(head);
    return 0;
}