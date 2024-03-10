// Infix to postfix
#include <iostream>
#include <stdlib.h>
#include <string>
using namespace std;

struct stack
{
    int size;
    int top;
    char *arr;
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
int precendence(char ch)
{
    if (ch == '*' || ch == '/')
    {
        return 1;
    }
    else if (ch == '+' || ch == '-')
    {
        return 2;
    }
    else
    {
        return 0;
    }
}
int isOperator(char ch)
{
    if (ch == '*' || ch == '/' || ch == '+' || ch == '-')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void push(stack *ptr, char val)
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
int peep(stack *ptr)
{
    return ptr->arr[ptr->top];
}

string infixToPostfix(string infix, int lengthOfInfix)
{
    stack *sp = new stack;
    sp->size = 10;
    sp->top = -1;
    sp->arr = new char[sp->size];
    string postfix;
    int i = 0;
    int j = 0;
    while (infix[i] != '\0')
    {
        if (!isOperator(infix[i]))
        {
            postfix[j] = infix[i];
            i++;
            j++;
        }
        else
        {
            if (precendence(infix[i]) > precendence(peep(sp)))
            {
                push(sp, infix[i]);
                i++;
            }
            else
            {
                postfix[j] = pop(sp);
                j++;
            }
        }
    }
    while (!isEmpty(sp))
    {
        postfix[j] = pop(sp);
        j++;
    }
    postfix[j] = "\0";
    return postfix;
}
int main()
{
    string infix = "x+y-z/x+t";
    string postfix = infixToPostfix(infix, 9);
    for (int i = 0; i < 9; i++)
    {
        cout << postfix[i] << " ";
    }

    return 0;
}
