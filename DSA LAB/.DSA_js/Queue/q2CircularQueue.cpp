#include <iostream>
using namespace std;
struct circularQueue
{
    int size;
    int r;
    int f;
    int *arr;
};
int isFull(circularQueue *q)
{
    if ((q->r + 1) % q->size == q->f)
    {
        return 1;
    }
    return 0;
}
int isEmpty(circularQueue *q)
{
    if ((q->r) == (q->f))
    {
        return 1;
    }
    return 0;
}
int decircularQueue(circularQueue *q)
{
    if (isEmpty(q))
    {
        cout << "Failed to decircularQueue, circularQueue is Empty!";
        return -1;
    }
    q->f = (q->f) % q->size + 1;
    return q->arr[q->f];
}
void encircularQueue(circularQueue *q, int val)
{
    if (isFull(q))
    {
        cout << "Cannot insert circularQueue is full";
        return;
    }
    q->r = (q->r + 1) % q->size + 1;
    q->arr[q->r] = val;
    cout << q->arr[q->r] << " pushed to the circularQueue successfully!" << endl;
}
void display(circularQueue *q)
{
    cout << "q: ";
    for (int i = q->f + 1; i <= q->r; i++)
    {
        cout << q->arr[i] << " ";
    }
}
int main()
{
    circularQueue q;
    q.size = 8;
    q.r = q.f = 0;
    q.arr = new int[q.size];

    int choice;
    do
    {
        cout << endl;
        cout << "1.EncircularQueue\t";
        cout << "2.DecircularQueue\t";
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
            encircularQueue(&q, element);
            break;
        case 2:
            cout << decircularQueue(&q) << " Deleted from the circularQueue!";
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