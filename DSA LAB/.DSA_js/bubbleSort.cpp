#include <iostream>
using namespace std;

void swap(int arr, int j)
{
    int *temp = arr[j];
    arr[j + 1] = arr[j];
    arr[j] = *temp;
}
int bubbleSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {

        for (int j = i; j < n - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr, j);
            }
        }
    }
}
void show(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int arr[100] = {1, 3, 5, 2, 6, 9, 8};
    bubbleSort(arr, 7);
    show(arr, 7);

    return 0;
}