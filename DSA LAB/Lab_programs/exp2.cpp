// Experiment 2:
// write a program to search an item in a sorted array using binary search. If found then delete that item from arr, if not found then insert that item at kth position in a way that the resultant array must be sorted. Write individual function for binary search, insertion and deletion.
#include <iostream>
using namespace std;

int binarySearch(int arr[], int target, int filled_capacity)
{
    int left = 0;
    int right = filled_capacity - 1;
    while (left <= right)
    {
        int midIndex = left + ((right - left) / 2);
        if (arr[midIndex] == target)
        {
            return midIndex;
        }
        else if (arr[midIndex] < target)
        {
            left = midIndex + 1;
        }
        else
        {
            right = midIndex - 1;
        }
    }
    return -1;
}

void insertSorted(int arr[], int value_to_insert, int filled_capacity, int totalCapacity)
{
    if (filled_capacity >= totalCapacity)
    {
        cout << "No space in Array" << endl;
        return;
    }
    int i = filled_capacity;
    while (arr[i] > value_to_insert)
    {
        arr[i + 1] = arr[i];
        i--;
        if (arr[i] < value_to_insert || i == -1)
        {
            break;
        }
    }

    arr[i + 1] = value_to_insert;
    cout << "Value Inserted, resultant array: " << endl;

    for (int i = 0; i <= filled_capacity; i++)
    {
        cout << arr[i] << " ";
    }
}

void deletionAtIndex(int arr[], int index_to_delete, int filled_capacity)
{

    for (int i = index_to_delete; i <= filled_capacity; i++)
    {
        arr[i] = arr[i + 1];
    }
    cout << "value deleted, resultant array: ";
    for (int i = 0; i < filled_capacity - 1; i++)
    {
        cout << arr[i] << " ";
    }
}

int main()
{
    int filled = 13;
    int target_value = 0;
    int arrSize = 20;
    cout << "Enter element to Delete: ";
    cin >> target_value;
    int myArray[20] = {2, 3, 5, 8, 10, 12, 15, 18, 33, 45, 67, 89, 97};
    int isfoundIndex = binarySearch(myArray, target_value, filled);
    if (isfoundIndex == -1)
    {
        insertSorted(myArray, target_value, filled, arrSize);
    }
    else
    {
        deletionAtIndex(myArray, isfoundIndex, filled);
    }
    return 0;
}