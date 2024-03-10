#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;

    Node(int value) : data(value), next(nullptr) {}
};

class Stack
{
private:
    Node *top;

public:
    Stack() : top(nullptr) {}

    void push(int value)
    {
        Node *newNode = new Node(value);
        if (top == nullptr)
        {
            top = newNode;
        }
        else
        {
            newNode->next = top;
            top = newNode;
        }
    }

    void pop()
    {
        if (top == nullptr)
        {
            cout << "Stack is empty. Cannot pop." << endl;
            return;
        }
        Node *temp = top;
        top = top->next;
        delete temp;
    }

    void display()
    {
        if (top == nullptr)
        {
            cout << "Stack is empty." << endl;
            return;
        }

        cout << "Stack elements: ";
        Node *current = top;
        while (current != nullptr)
        {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main()
{
    Stack stack;

    stack.push(10);
    stack.push(20);
    stack.push(30);

    stack.display();
    stack.pop();
    stack.display();

    return 0;
}
