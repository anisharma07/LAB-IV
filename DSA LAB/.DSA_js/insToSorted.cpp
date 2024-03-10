// WAP to insert an element into a sorted array ,
// user will input the array elements and,
// tell about the size of the array.
// give the element to insert
#include <iostream>
using namespace std;

int ins_into_sorted(int arr[], int &n, int value)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > value)
        {
            for (int j = n; j >= i; j--)
            {
                arr[j + 1] = arr[j];
            }
            arr[i] = value;
            n++;
            return 1;
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
    int n;
    int element;
    int arr[100];
    cout << "Enter the elements in the array: " << endl;
    for (int i = 0; i < 99; i++)
    {
        cin >> arr[i];
        if (arr[i] == 0)
        {
            break;
        }
    }
    cout << "Enter the capacity of array: ";
    cin >> n;
    cout << "your arr: ";
    show(arr, n);
    cout << "\nEnter the element to insert: ";
    cin >> element;

    ins_into_sorted(arr, n, element);
    cout << "your sorted array: ";
    // n++;
    show(arr, n);
    return 0;
}