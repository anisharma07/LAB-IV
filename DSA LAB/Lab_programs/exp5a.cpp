// Experiment 5
// I.	Write a program to implement STACK using arrays that performs following operations
// (a)	PUSH
// (b)	POP
// (c)	PEEP
// (d)	DISPLAY
// Implememting Stack using Array:
#include <iostream>
using namespace std;

struct stack
{
    int size;
    int top;
    int *arr;
};

void push(stack *ptr, int val)
{
    if (ptr->top == ptr->size - 1)
    {
        cout << "Stack overflow, Cannot push " << val << " to the stack!" << endl;
        return;
    }
    ptr->top++;
    ptr->arr[ptr->top] = val;
    cout << val << " pushed to stack!" << endl;
}
int pop(stack *ptr)
{
    if (ptr->top == -1)
    {
        cout << "Stack underflow, nothing to pop!" << endl;
        return -1;
    }
    int val = ptr->arr[ptr->top];
    cout << val << " popped from the stack!" << endl;
    ptr->top--;
    return val;
}
int peep(stack *ptr)
{
    if (ptr->top == -1)
    {
        cout << "Stack underflow, top = -1" << endl;
        return -1;
    }
    cout << "Value at top: " << ptr->arr[ptr->top] << endl;
    cout << "Top Index: " << ptr->top << endl;
    return ptr->top;
}
void Display(stack *ptr)
{
    if (ptr->top == -1)
    {
        cout << "Stack is empty!" << endl;
        return;
    }
    cout << "stack_elements: ";
    for (int i = ptr->top; i >= 0; i--)
    {
        cout << ptr->arr[i] << " ";
    }
    cout << endl;
}
int main()
{
    stack *s = new stack;
    s->size = 10;
    s->top = -1;
    s->arr = new int[s->size];
    int choice = 0;
    cout << "Operations: " << endl;
    cout << "1.PUSH\t\t2.POP\t\t3.PEEP" << endl;
    cout << "4.DISPLAY\t5.Exit" << endl;
    do
    {
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            int el;
            cout << "Enter the element to push: ";
            cin >> el;
            push(s, el);
            break;
        case 2:
            pop(s);
            break;
        case 3:
            peep(s);
            break;
        case 4:
            Display(s);
            break;
        case 5:
            cout << "Exiting Program..." << endl;
            break;
        default:
            cout << "Invalid choice. Try Again!" << endl;
            break;
        }
    } while (choice != 5);
    return 0;
}