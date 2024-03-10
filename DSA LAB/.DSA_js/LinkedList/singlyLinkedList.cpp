// Explaining traversal, insertion and deletion in linked LIST
#include <iostream>
#include <stdlib.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
};

void linked_list_traversal(struct Node *ptr)
{
    cout << "\nElements: ";
    while (ptr != NULL)
    {
        cout << ptr->data << " ";
        ptr = ptr->next;
    }
}

struct Node *insertAtFirst(struct Node *head, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->next = head;
    ptr->data = data;
    return ptr;
}

struct Node *insertAfterNode(struct Node *node, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    ptr->next = node->next;
    node->next = ptr;
    return ptr;
}

struct Node *insertInBetween(struct Node *ptr, int index, int data)
{
    int i = 1;

    while (i <= index)
    {
        if (i == index)
        {
            struct Node *q = (struct Node *)malloc(sizeof(struct Node));
            q->data = data;
            q->next = ptr->next;
            ptr->next = q;
            return q;
        }
        ptr = ptr->next;
        i++;
    }
    return NULL;
}

struct Node *insertAtEnd(struct Node *ptr, int data)
{
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    struct Node *q = (struct Node *)malloc(sizeof(struct Node));
    q->data = data;
    q->next = NULL;
    ptr->next = q;
    return q;
}

struct Node *deleteNodeAtBeginnning(struct Node *head)
{
    struct Node *ptr = head;
    head = head->next;
    delete ptr;
    return head;
}

void deleteAtEnd(struct Node *ptr)
{
    while (ptr->next->next != NULL)
    {
        ptr = ptr->next;
    }
    delete ptr->next->next;
    ptr->next = NULL;
}

void deleteInBetween(struct Node *ptr, int index)
{
    int i = 1;
    struct Node *q = ptr;

    while (i <= index)
    {
        if (i == index)
        {
            q->next = ptr->next;
            delete ptr;
        }
        q = ptr;
        ptr = ptr->next;
        i++;
    }
}

void deleteTheValue(struct Node *head, int value)
{
    struct Node *ptr = head;
    if (ptr->data == value)
    {
        head = ptr->next;
        delete ptr;
        return;
    }
    while (ptr->next != NULL)
    {
        if (ptr->next->data == value)
        {
            ptr->next = ptr->next->next;
        }
        ptr = ptr->next;
    }
    cout << head->data << value << endl;
}

int main()
{
    struct Node *head = (struct Node *)malloc(sizeof(struct Node));
    struct Node *second = (struct Node *)malloc(sizeof(struct Node));
    struct Node *third = (struct Node *)malloc(sizeof(struct Node));
    struct Node *fourth = (struct Node *)malloc(sizeof(struct Node));

    head->data = 7;
    head->next = second;

    second->data = 11;
    second->next = third;

    third->data = 66;
    third->next = fourth;

    fourth->data = 41;
    fourth->next = NULL;

    linked_list_traversal(head);
    int choice;
    int d;
    do
    {
        cout << endl;
        cout << "What Action do you want to take?" << endl;
        cout << "1. Insert at first\t\t";
        cout << "2. Insert in between" << endl;
        cout << "3. Insert at last\t\t";
        cout << "4. Insert after node" << endl;
        cout << "5. Display list\t\t";
        cout << "6. Delete at fisrt." << endl;
        cout << "7. Delete at last.\t\t";
        cout << "8. Delete at index." << endl;
        cout << "9. Delete the value.\t\t";
        cout << "10. Exit" << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:

            cout << "Insert at Beginning, Enter Data: ";
            cin >> d;
            head = insertAtFirst(head, d);
            cout << "Data inserted!";
            break;
        case 2:

            int index;
            cout << "Enter the data: ";
            cin >> d;
            cout << "Enter the index: ";
            cin >> index;
            insertInBetween(head, index, d);
            cout << "Data inserted!";
            break;
        case 3:

            cout << "Enter the data: ";
            cin >> d;
            insertAtEnd(head, d);
            cout << "Data inserted!";
            break;
        case 4:
            int node_num;
            cout << "Enter the data: ";
            cin >> d;
            cout << "Enter the node: ";
            cin >> node_num;
            switch (node_num)
            {
            case 1:
                insertAfterNode(head, d);
                break;
            case 2:
                insertAfterNode(second, d);
                break;
            case 3:
                insertAfterNode(third, d);
                break;
            case 4:
                insertAfterNode(fourth, d);
                break;
            default:
                cout << "Try Again! Enter a value between 1 to 4";
            }
            cout << "Data Inserted!";
            break;
        case 5:
            linked_list_traversal(head);
            break;
        case 6:
            head = deleteNodeAtBeginnning(head);
            cout << "Element deleted!\n";
            break;
        case 7:
            deleteAtEnd(head);
            cout << "Element deleted!\n";
            break;
        case 8:
            cout << "Enter the index to delete..." << endl;
            cin >> index;
            deleteInBetween(head, index);
            break;
        case 9:
            deleteTheValue(head, 50);
            cout << "Element deleted!\n";
            break;
        case 10:
            cout << "Exiting program!";
            break;

        default:
            cout << "Enter a valid choice";
        }
    } while (choice != 10);
    return 0;
}

// Linked Lists Insertion:
// Case 1: Insert at the beginning;
// Case 2: Insert in Between;
// Case 3: Insert at the end;
// Case 4: Insert after a Node;