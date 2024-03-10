// verified
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

anode *insertInBetween(anode *head, int data, int index)
{
    // index will be 1,2,3 for four elements list
    int i = 1;
    anode *ptr = head;
    anode *q = (anode *)malloc(sizeof(anode));
    q->data = data;
    while (i <= index)
    {
        if (i == index)
        {
            q->next = ptr->next;
            ptr->next = q;
            return q;
        }
        ptr = ptr->next;
        i++;
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
    int index = 0;
    cout << "Enter the index: ";
    cin >> index;
    insertInBetween(head, 69, index);
    cout << "After insertion" << endl;

    linked_list_traversal(head);
    return 0;
}