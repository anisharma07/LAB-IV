#include <iostream>
using namespace std;

// Function for binary search
int binarySearch(int arr[], int left, int right, int target)
{
    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        // If the target is found, return its index
        if (arr[mid] == target)
        {
            return mid;
        }

        // If the target is in the left half of the array
        if (arr[mid] > target)
        {
            right = mid - 1;
        }
        // If the target is in the right half of the array
        else
        {
            left = mid + 1;
        }
    }

    // If the target is not found, return -1
    return -1;
}

int main()
{
    int size, target;

    cout << "Enter the size of the sorted array: ";
    cin >> size;

    int arr[size];

    cout << "Enter the elements of the sorted array:" << endl;
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }

    cout << "Enter the target element to search for: ";
    cin >> target;

    int result = binarySearch(arr, 0, size - 1, target);

    if (result != -1)
    {
        cout << "Target element found at index " << result << "." << endl;
    }
    else
    {
        cout << "Target element not found in the array." << endl;
    }

    return 0;
}