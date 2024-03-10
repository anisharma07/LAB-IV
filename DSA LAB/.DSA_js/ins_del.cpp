#include <iostream>
using namespace std;

void show(int arr[], int n)
{
    // Array Traversal
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int indInsertion(int arr[], int n, int capacity, int elementToInsert, int index)
{
    if (n >= capacity)
    {
        return -1;
    }
    for (int i = n; i > index; i--)
    {
        arr[i] = arr[i - 1];
    }
    arr[index] = elementToInsert;
    return 1;
}

int indDeletion(int arr[], int index, int n)
{
    for (int i = index; i < n; i++)
    {
        arr[i] = arr[i + 1];
    }
    return 1;
}

int main()
{
    int arr[100] = {324, 5, 2, 6, 234, 34};
    show(arr, 6);
    indInsertion(arr, 6, 100, 236, 2);
    show(arr, 7);
    indDeletion(arr, 0, 7);
    show(arr, 6);
    return 0;
}