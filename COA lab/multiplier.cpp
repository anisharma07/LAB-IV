#include<iostream>
using namespace std;


int main()
{
    int n;
    cout << "Enter the size of multiplicand: ";
    cin >> n;
    int M[n];
    cout << "Enter the multiplicand: ";
    for (int i = 0; i < n; i++)
    {
        cin >> M[i];
    }
    int m;
    cout << "Enter the size of multiplier: ";
    cin >> m;
    int Q[m];
    cout << "Enter the multiplier: ";
    for (int i = 0; i < m; i++)
    {
        cin >> Q[i];
    }

    cout << "Multiplicand = ";
    for (int i = 0; i < n; i++)
    {
        cout << M[i] << " ";
    }
    cout << "\nmultiplier: ";
    for (int i = 0; i < m; i++)
    {
        cout << Q[i] << " ";
    }
    // User inputs Recieved
    int M_dash[n] = {0};
    for (int i = 0; i < n; i++)
    {
        M_dash[i] = M[i];
    }
    twosComplement(M_dash, n);
    cout << "\nM_dash:";
    for (int i = 0; i < n; i++)
    {
        cout << M_dash[i] << " ";
    }

    int acc_size = 0;
    if (n >= m)
    {
        acc_size = n;
    }
    else
    {
        acc_size = m;
    }

    int ACC[acc_size] = {0};

    boothAlgo(M, M_dash, Q, ACC, n, m, acc_size);

    cout << "\nResult: ";
    for (int i = 0; i < acc_size; i++)
    {
        cout << ACC[i] << " ";
    }
    for (int i = 0; i < m; i++)
    {
        cout << Q[i] << " ";
    }
    return 0;
}

// Implementing signed bit multiplication using partial product approach
int signedBitMultiplication(int multiplicand[], int multiplier[], int a_size, int m_size)
{
    int product[a_size + m_size] = {0};

    for (int i = 0; i < m_size; i++)
    {
        if (multiplier[i] == 1)
        {
            int temp[a_size + m_size] = {0};
            for (int j = 0; j < a_size; j++)
            {
                temp[j + i] = multiplicand[j];
            }
            parallelAdder(temp, product, a_size + m_size, a_size + m_size);
        }
    }

    int result = 0;
    for (int i = 0; i < a_size; i++)
    {
        result += product[i + m_size] * pow(2, i);
    }

    return result;
}