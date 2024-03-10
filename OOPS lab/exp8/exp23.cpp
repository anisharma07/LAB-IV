#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    char input[100];
    cout << "Enter a string: ";
    cin.getline(input, 100); // Read the input string

    char vowels[] = "aeiouAEIOU"; // List of vowels

    int vowelCount[10] = {0}; // Array to store vowel counts, index 0-4 for lowercase vowels, 5-9 for uppercase vowels

    char *ptr = input; // Pointer to traverse the input string

    while (*ptr != '\0')
    {
        for (int i = 0; i < 10; i++)
        {
            if (*ptr == vowels[i])
            {
                vowelCount[i]++;
                break;
            }
        }
        ptr++;
    }

    int totalCount = 0;
    for (int i = 0; i < 10; i++)
    {
        if (i < 5)
        {
            cout << "Occurrences of " << vowels[i] << ": " << vowelCount[i] << endl;
        }
        else
        {
            cout << "Occurrences of " << vowels[i] << ": " << vowelCount[i] << endl;
        }
        totalCount += vowelCount[i];
    }

    cout << "Total number of vowels: " << totalCount << endl;

    return 0;
}
