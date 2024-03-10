#include <iostream>
#include <vector>
using namespace std;
class matrix
{
private:
    int rows;
    int cols;

public:
    vector<vector<int>> data;
    matrix(int r, int c) : rows(r), cols(c)
    {
        data.resize(rows, vector<int>(cols, 0));
    }

    // overload the +
    matrix operator+(const matrix &other) const
    {
        matrix result(rows, cols);
        for (int i = 0; i <= rows; i++)
        {
            for (int j = 0; j <= cols; i++)
            {
                result.data[i][j] = data[i][j] + other.data[i][j];
            }
        }
        // result.display();
        return result;
    }

    // overload the -
    matrix operator-(const matrix &other) const
    {
        matrix result(rows, cols);
        for (int i = 0; i <= rows; i++)
        {
            for (int j = 0; j <= cols; i++)
            {
                result.data[i][j] = data[i][j] - other.data[i][j];
            }
        }
        // result.display();
        return result;
    }

    // now display the matrix
    void display()
    {
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                cout << data[i][j] << " ";
            }
            cout << endl;
        }
    };
};

int main()
{
    matrix m1(2, 2);
    m1.data = {{2, 5}, {9, 3}};
    matrix m2(2, 2);
    m2.data = {{2, 5}, {9, 3}};
    matrix m3(2, 2);
    m3 = m2 + m1;
    matrix m4(2, 2);
    m4 = m2 - m1;
    cout << m3.data[0][0] << " " << m3.data[0][1] << endl;
    cout << m3.data[1][0] << " " << m3.data[1][1] << endl;
    cout << m4.data[0][0] << " " << m4.data[0][1] << endl;
    cout << m4.data[1][0] << " " << m4.data[1][1] << endl;
    return 0;
}