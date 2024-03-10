#include <iostream>
using namespace std;
class Matrix
{
    int rows;
    int cols;
    int **ptr;

public:
    Matrix() {}
    Matrix(int x, int y) : rows(x), cols(y)
    {
        ptr = new int *[cols];
        for (int i = 0; i < cols; i++)
        {
            ptr[i] = new int[rows];
        }
    }
    void insert()
    {
        cout << "Enter the Matrix elements: " << endl;
        for (int i = 0; i < cols; i++)
        {
            for (int j = 0; j < rows; j++)
            {
                int elmt;
                cin >> elmt;
                ptr[i][j] = elmt;
            }
        }
    }
    void display()
    {
        cout << "The Matrix is: " << endl;
        for (int i = 0; i < cols; i++)
        {
            for (int j = 0; j < rows; j++)
            {
                cout << ptr[i][j] << " ";
            }
            cout << endl;
        }
    }
    Matrix operator+(const Matrix &m)
    {
        if (m.rows == rows && m.cols == cols)
        {
            Matrix temp(rows, cols);
            for (int i = 0; i < cols; i++)
            {
                for (int j = 0; j < rows; j++)
                {
                    temp.ptr[i][j] = ptr[i][j] + m.ptr[i][j];
                }
            }
            return temp;
        }
        else
        {
            cout << "Matrix operation cannot be performed" << endl;
        }
    };

    Matrix operator-(const Matrix &m)
    {
        if (m.rows == rows && m.cols == cols)
        {
            Matrix temp(rows, cols);
            for (int i = 0; i < cols; i++)
            {
                for (int j = 0; j < rows; j++)
                {
                    temp.ptr[i][j] = ptr[i][j] - m.ptr[i][j];
                }
            }
            return temp;
        }
        else
        {
            cout << "Matrix operation cannot be performed" << endl;
        }
    };
};

int main()
{
    cout << "Enter Dimensions of Matrix 1: " << endl;
    int a, b;
    cin >> a >> b;
    Matrix m1(a, b);
    m1.insert();
    m1.display();

    cout << "Enter Dimensions of Matrix 2: " << endl;
    cin >> a >> b;
    Matrix m2(a, b);
    m2.insert();
    m2.display();

    Matrix m3 = m1 + m2;
    Matrix m4 = m1 - m2;

    cout << "Addition Result: " << endl;
    m3.display();

    cout << "Substraction Result: " << endl;
    m4.display();

    return 0;
}