// Experiment 3
// Implement following sorting algorithms to sort an array (make a dynamic array):
// 1.	Write a function to sort an array using Bubble sort. Use 1-bit variable FLAG to signal when no interchange take place during pass. If FLAG is 0 after any pass, then list is already sorted and there is no need to continue.(optimized bubble sort)
// 2.	Write a function to sort an array using Selection sort.
// 3.	Write a function to sort an array using Insertion sort.
// Write a menu driven program to implement above sorting. Discuss Best, Average and Worst case time complexity of each sorting algorithm implemented above.
#include <iostream>
using namespace std;

void swapArrEl(int arr[], int i, int j)
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

void arrayTraversal(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void bubbleSortWithFlag(int arr[], int n)
{
    for (int i = 0; i < n - 1; ++i)
    {
        int flag = 0;
        for (int j = 0; j < n - i - 1; ++j)
        {
            if (arr[j] > arr[j + 1])
            {
                flag = 1;
                swapArrEl(arr, j, j + 1);
            }
        }
        if (flag == 0)
            break;
    }
}

void insertionSort(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void selectionSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }
        swapArrEl(arr, i, minIndex);
    }
}
int main()
{
    int choice = 0;
    do
    {
        int n = 0;
        // int choice1 = 0;

        cout << "Enter the size of array: " << endl;
        cin >> n;
        int arr[n];
        cout << "Enter the elements: " << endl;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        cout << "Array Elements: ";
        arrayTraversal(arr, n);
        cout << "How do you wanna sort the array?";
        cout << "\n1. Bubble Sort" << endl;
        cout << "2. Insertion Sort" << endl;
        cout << "3. Selection Sort" << endl;
        cout << "4. Exit" << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
            bubbleSortWithFlag(arr, n);
            cout << "Array after bubbleSort: ";
            arrayTraversal(arr, n);
            break;
        case 2:
            insertionSort(arr, n);
            cout << "Array after InsertionSort: ";
            arrayTraversal(arr, n);
            break;
        case 3:
            selectionSort(arr, n);
            cout << "Array after Selection Sort: ";
            arrayTraversal(arr, n);
            break;
        case 4:
            cout << "Exiting program...";
            break;
        default:
            cout << "Enter a valid statement";
            break;
        }
    } while (choice != 4);

    return 0;
}