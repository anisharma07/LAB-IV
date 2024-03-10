// 09-02  -2024
// Experiment 4
// Write a menu driven program to implement following operations on the singly linked list. Please make sure that all the functions are working for all the possible test cases.
// (a) Insert a node at the front of the linked list.
// (b) Insert a node at the end of the linked list.
// (c) Insert a node at the given position in the link list.
// (d) Delete first node of the linked list.
// (e) Delete last node of the list.
// (f) Delete a node from specified position.
// (g) Display the elements of the link list.

#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
};

struct Node *head = (struct Node *)malloc(sizeof(struct Node));
struct Node *second = (struct Node *)malloc(sizeof(struct Node));
struct Node *third = (struct Node *)malloc(sizeof(struct Node));
struct Node *fourth = (struct Node *)malloc(sizeof(struct Node));

void linked_list_traversal(struct Node *ptr)
{
    cout << "\nElements: ";
    while (ptr != NULL)
    {
        cout << ptr->data << " ";
        ptr = ptr->next;
    }
}

struct Node *insertAtFront(struct Node *head, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->next = head;
    ptr->data = data;
    return ptr;
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

struct Node *insertAtPosition(struct Node *head, int index, int data)
{
    struct Node *ptr = head;
    if (head == NULL)
    {
        cout << "List is empty!! Try using Insert at front or Insert at back. ";
        return NULL;
    }
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

struct Node *deleteFirstNode(struct Node *head)
{
    if (head == NULL)
    {
        cout << "List is Empty" << endl;
        return nullptr;
    }
    struct Node *ptr = head;
    head = head->next;
    delete ptr;
    cout << "Element deleted!\n";
    return head;
}

void deleteAtLast()
{
    if (head == nullptr)
    {
        cout << "List is empty\n";
        return;
    }
    if (head->next == nullptr)
    {
        delete head;
        head = nullptr;
        return;
    }
    Node *temp = head;
    while (temp->next->next != nullptr)
    {
        temp = temp->next;
    }
    delete temp->next;
    temp->next = nullptr;
}

void deleteAtPosition(int position)
{
    if (head == nullptr)
    {
        cout << "List is empty\n";
        return;
    }
    if (position == 1)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
        return;
    }
    Node *temp = head;
    for (int i = 1; i < position - 1 && temp != nullptr; i++)
    {
        temp = temp->next;
    }
    if (temp == nullptr || temp->next == nullptr)
    {
        cout << "Invalid position\n";
        return;
    }
    Node *nodeToDelete = temp->next;
    temp->next = temp->next->next;
    delete nodeToDelete;
}

int main()
{
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
    cout << endl;
    cout << "What Action do you want to take?" << endl;
    cout << "1. Insert at front\t\t";
    cout << "2. Insert at End" << endl;
    cout << "3. Insert at position\t\t";
    cout << "4. Delete First Node" << endl;
    cout << "5. Delete at last.\t\t";
    cout << "6. Delete at position." << endl;
    cout << "7. Display list\t\t\t";
    cout << "8. Exit" << endl;
    do
    {
        cout << "\nEnter your choice: " << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Insert at Beginning, Enter Data: ";
            cin >> d;
            head = insertAtFront(head, d);
            cout << "Data inserted!";
            break;
        case 2:

            cout << "Enter the data: ";
            cin >> d;
            insertAtEnd(head, d);
            cout << "Data inserted!";
            break;

        case 3:
            int index;
            cout << "Enter the data: ";
            cin >> d;
            cout << "Enter position: ";
            cin >> index;
            insertAtPosition(head, index, d);
            cout << "Data inserted!";
            break;

        case 4:
            head = deleteFirstNode(head);
            break;
        case 5:
            deleteAtLast();
            break;
        case 6:
            cout << "Enter the index to delete..." << endl;
            cin >> index;
            deleteAtPosition(index);
            break;
        case 7:
            linked_list_traversal(head);
            break;
        case 8:
            cout << "Exiting Program...." << endl;
            break;
        default:
            cout << "Enter a valid choice";
        }
    } while (choice != 8);
    return 0;
}