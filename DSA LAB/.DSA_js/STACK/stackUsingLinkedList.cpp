// Implementing Stack by using linked List:

#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};
Node *top = new Node;

void linked_list_traversal(Node *tp)
{
    cout << "Stack elements: ";
    while (tp != NULL)
    {
        cout << tp->data << " ";
        tp = tp->next;
    }
    cout << endl;
}
Node *push(Node *top, int data)
{
    Node *n = new Node;
    if (n == nullptr)
    {
        cout << "Stack is Full, Overflow" << endl;
        return nullptr;
    }
    n->data = data;
    n->next = top;
    cout << data << " pushed to Stack!" << endl;
    return n;
}
Node *pop()
{
    if (top == NULL)
    {
        cout << "UnderFlow, cannot Pop!" << endl;
        return nullptr;
    }
    Node *n = top;
    n = top->next;
    delete top;
    return n;
}
int main()
{
    top = NULL;
    int choice;
    do
    {
        cout << "1.PUSH\t";
        cout << "2.POP\t";
        cout << "3.PEEP\t";
        cout << "4.DISPLAY\t";
        cout << "5.EXIT" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cout << endl;
        switch (choice)
        {
        case 1:
            int element;
            cout << "Enter element to push: ";
            cin >> element;
            top = push(top, element);
            break;
        case 2:
            top = pop();
            break;
        case 3:
            cout << "coming Soon!" << endl;
            break;
        case 4:
            linked_list_traversal(top);
            break;
        case 5:
            cout << "Exiting Program..." << endl;
            break;
        default:
            cout << "Invalid choice..." << endl;
            break;
        }
    } while (choice != 5);
    return 0;
}