#include <iostream>
#include <cstring>

using namespace std;

// Function to count occurrences of each vowel and total number of vowels in the string
void countVowels(const char *str, int &totalVowels, int *vowelCounts)
{
    while (*str)
    {
        char ch = tolower(*str);

        switch (ch)
        {
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':
            totalVowels++;
            vowelCounts[ch - 'a']++;
            break;
        }

        str++;
    }
}

int main()
{
    const int numVowels = 5;
    int totalVowels = 0;
    int vowelCounts[numVowels] = {0};

    char str[100];

    cout << "Enter a string: ";
    cin.getline(str, 100);

    countVowels(str, totalVowels, vowelCounts);

    cout << "Occurrences of each vowel:" << endl;
    for (int i = 0; i < numVowels; i++)
    {
        char vowel = 'a' + i;
        cout << vowel << ": " << vowelCounts[i] << endl;
    }

    cout << "Total number of vowels in the string: " << totalVowels << endl;

    return 0;
}