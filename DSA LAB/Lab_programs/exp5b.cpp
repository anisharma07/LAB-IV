// Experiment 5
// II.	Write a program to implement STACK using Linked List that performs following operations
// (a)	PUSH
// (b)	POP
// (c)	PEEP
// (d)	DISPLAY
// Implementing Stack by using linked List:

#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};
Node *top = new Node;

void Display(Node *tp)
{
    if (tp == nullptr)
    {
        cout << "Stack is Empty!" << endl;
        return;
    }
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
    int val = n->data;
    n = top->next;
    delete top;
    cout << val << " popped from stack!" << endl;
    return n;
}
void peep()
{
    if (top == nullptr)
    {
        cout << "Stack is empty, Top is null" << endl;
        return;
    }
    cout << "TOP ELEMENT: " << top->data << endl;
}
int main()
{
    top = NULL;
    int choice;
    cout << "1.PUSH\t";
    cout << "2.POP\t";
    cout << "3.PEEP\t";
    cout << "4.DISPLAY\t";
    cout << "5.EXIT" << endl;
    do
    {
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
            peep();
            break;
        case 4:
            Display(top);
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