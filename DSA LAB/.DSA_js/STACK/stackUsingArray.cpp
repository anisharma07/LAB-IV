// Implememting Stack using Array:
#include <iostream>
using namespace std;

struct stack
{
    int size;
    int top;
    int *arr;
};

int isEmpty(stack *ptr)
{
    if (ptr->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isFull(stack *ptr)
{
    if (ptr->top == ptr->size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void push(stack *ptr, int val)
{
    if (isFull(ptr))
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
    if (isEmpty(ptr))
    {
        cout << "Stack underflow, nothing to pop!" << endl;
        return -1;
    }
    int val = ptr->arr[ptr->top];
    cout << val << " popped from the stack!" << endl;
    ptr->top--;
    return val;
}
int peek(stack *ptr, int index)
{
    int arrInd = ptr->top - index + 1; // formula
    if (isEmpty(ptr))
    {
        cout << "underflow, index not found" << endl;
        return -1;
    }
    if (arrInd < 0)
    {
        cout << "Invalid Index, cannot get element!" << endl;
        return -1;
    }
    return ptr->arr[arrInd];
}
int peep(stack *ptr)
{
    if (isEmpty(ptr))
    {
        cout << "Stack underflow, top = -1" << endl;
        return -1;
    }
    cout << "Value at top: " << ptr->arr[ptr->top] << endl;
    cout << "top pointer: " << ptr->top << endl;
    return ptr->top;
}
void traverse_using_peek(stack *ptr)
{
    cout << "stack_elements: ";
    for (int i = 1; i <= ptr->top + 1; i++)
    {
        cout << peek(ptr, i) << " ";
    }
    cout << endl;
}
int main()
{
    stack *s = new stack;
    s->size = 10;
    s->top = -1;
    s->arr = new int[s->size];
    push(s, 10);
    push(s, 5);
    push(s, 3);
    push(s, 6);
    push(s, 7);
    push(s, 2);
    push(s, 2);
    push(s, 2);
    push(s, 2);
    push(s, 2);
    push(s, 2);
    push(s, 2);
    push(s, 2);
    push(s, 2);
    push(s, 2);
    push(s, 2);
    push(s, 2);
    cout << peek(s, 1) << endl;
    traverse_using_peek(s);
    cout << "operating Peep: " << endl;
    cout << peep(s);
    return 0;
}
