#include <iostream> // to include library functions

using namespace std; // to standaralize the std function

/**
 *
 *
 * to create a function for element input by the user
 *
 *
 */
void readMatrix(int rows, int cols, int matrix[][100])
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << "Enter element at position (" << i << ", " << j << "): ";
            cin >> matrix[i][j];
        }
    }
}
/**
 * declare function for adding two matrices
 *
 * it will input all resultant sum into the resultMatrix
 *
 */

void addMatrices(int rows, int cols, int matrix1[][100], int matrix2[][100], int resultMatrix[][100])
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            resultMatrix[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
}

// A global function to print any matrix

void printMatrix(int rows, int cols, int matrix[][100])
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

/**
 *
 *
 * The main function
 *
 *
 */
int main()
{
    int rows, cols; // declare variables
    cout << "Enter the number of rows: ";
    cin >> rows;
    cout << "Enter the number of columns: ";
    cin >> cols;

    int matrix1[100][100], matrix2[100][100], resultMatrix[100][100];

    cout << "Enter elements of the first matrix:" << endl;
    readMatrix(rows, cols, matrix1);

    cout << "Enter elements of the second matrix:" << endl;
    readMatrix(rows, cols, matrix2);

    addMatrices(rows, cols, matrix1, matrix2, resultMatrix);

    // print the input matrix
    // cout << "matrix1 is:" << endl;
    // printMatrix(rows, cols, matrix1);

    // cout << "matrix2 is:" << endl;
    // printMatrix(rows, cols, matrix2);

    // prints the sum or resultant matrix
    cout << "Resultant matrix after addition:" << endl;
    printMatrix(rows, cols, resultMatrix);

    return 0;
}