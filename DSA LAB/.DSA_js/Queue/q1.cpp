#include <iostream>
using namespace std;
struct Queue
{
    int size;
    int r;
    int f;
    int *arr;
};
int isFull(Queue *q)
{
    if (q->r == q->size - 1)
    {
        return 1;
    }
    return 0;
}
int isEmpty(Queue *q)
{
    if ((q->r) == (q->f))
    {
        return 1;
    }
    return 0;
}
int dequeue(Queue *q)
{
    if (isEmpty(q))
    {
        cout << "Failed to dequeue, Queue is Empty!";
        return -1;
    }
    int val = q->arr[q->f + 1];
    q->f = q->f + 1;
    return val;
}
void enqueue(Queue *q, int val)
{
    if (isFull(q))
    {
        cout << "Cannot insert queue is full";
        return;
    }
    q->r = q->r + 1;
    q->arr[q->r] = val;
    cout << q->arr[q->r] << " pushed to the queue successfully!" << endl;
}
void display(Queue *q)
{
    cout << "q: ";
    for (int i = q->f + 1; i <= q->r; i++)
    {
        cout << q->arr[i] << " ";
    }
}
int main()
{
    Queue q;
    q.size = 100;
    q.r = q.f = -1;
    q.arr = new int[q.size];

    int choice;
    do
    {
        cout << endl;
        cout << "1.Enqueue\t";
        cout << "2.Dequeue\t";
        cout << "3.PEEk\t";
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
            enqueue(&q, element);
            break;
        case 2:
            cout << dequeue(&q) << " Deleted from the queue!";
            break;
        case 3:
            cout << "coming Soon!" << endl;
            break;
        case 4:
            display(&q);
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