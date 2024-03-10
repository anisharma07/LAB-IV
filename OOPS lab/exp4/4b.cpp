// 4b. Define a Class "bank_account" having following data members and member functions:
//         Data members:
//           1. Name of the depositer.
//           2. Account number.
//           3. Type of account.
//           4. Balance amount in the account.
//         Member functions:
//           1. To assign the initial values.
//           2. To deposit an amount.
//           3. To withdraw an amount after checking the balance.
//           4. To display name and balance.
//    Write a main program to test the program for 5 customers.

#include <iostream>
#include <string>
using namespace std;
class bank_Account
{
private:
    string Name, account_type;
    int account_number;
    double Balance;

public:
    void bankAccount(string n, int acc_num, string acc_type, double init_balance)
    {
        Name = n;
        account_number = acc_num;
        account_type = acc_type;
        Balance = init_balance;
    }

    void deposit(float x)
    {
        if (x > 0)
        {
            Balance = Balance + x;
            cout << "Amount " << x << " deposited." << endl;
        }
        else
        {
            cout << "Invalid deposit Amount." << endl;
        }
    }
    void withdraw(float y)
    {
        if (y > 0 && Balance >= y)
        {
            cout << "Your Balance: " << Balance << endl;
            Balance = Balance - y;
            cout << "Withdrawn: Rs." << y << ". New Balance: " << Balance << endl;
        }
        else
            {cout << "Invalid amount." << endl;}}
    void display_balance(void){
        cout << "Name: " << Name << endl;
        cout << "Balance: " << Balance << endl;}};
int main(){
    bank_Account customers[5];
    customers[0].bankAccount("Anirudh", 1001, "Savings", 1500);
    customers[1].bankAccount("Pushpdeep", 1002, "Checking", 2000);
    customers[2].bankAccount("Rohan", 1003, "Savings", 3000);
    customers[3].bankAccount("Anshul", 1004, "Checking", 500);
    customers[4].bankAccount("Risabh", 1005, "Savings", 10000);

    for (int i = 0; i < 5; ++i)
    {
        cout << "Customer " << i + 1 << ":" << endl;
        customers[i].display_balance();
        customers[i].deposit(1000);
        customers[i].withdraw(500);
        cout << endl;
    }
    return 0;
}