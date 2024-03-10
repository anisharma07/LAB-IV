#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <cstdlib>

using namespace std;
// Function to calculate the average of a specific column
double calculateColumnAverage(string filename, int columnToAverage)
{
    ifstream file(filename);
    if (!file)
    {
        cerr << "Failed to open the CSV file: " << filename << endl;
        exit(1);
    }

    string line;
    double sum = 0.0;
    int count = 0;

    while (getline(file, line))
    {
        istringstream lineStream(line);
        string cell;
        int column = 0;

        while (getline(lineStream, cell, ','))
        {
            if (column == columnToAverage)
            {
                try
                {
                    double value = stod(cell);
                    sum += value;
                    count++;
                }
                catch (const invalid_argument &e)
                {
                    // Ignore parsing errors in the CSV column
                }
            }
            column++;
        }
    }

    if (count > 0)
    {
        return sum / count;
    }
    else
    {
        return 0.0; // Return 0 if no valid values found in the specified column
    }
}

int main()
{
    string filename = "/home/anirudh/Desktop/c programs/CS_lab/rest/data.csv";
    int columnToAverage = 2;
    double average = calculateColumnAverage(filename, columnToAverage);
    cout << "Average of column " << columnToAverage << ": " << average << endl;
    return 0;
}
