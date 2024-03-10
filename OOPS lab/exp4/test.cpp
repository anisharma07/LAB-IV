#include <iostream>
#include <string>
using namespace std;

class BankAccount {
private:
    string name;
    int account_number;
    string account_type;
    double balance;

public:
    BankAccount(string n, int acc_num, string acc_type, double init_balance) {
        name = n;
        account_number = acc_num;
        account_type = acc_type;
        balance = init_balance;
    }

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Amount " << amount << " deposited. New balance: " << balance << endl;
        } else {
            cout << "Invalid deposit amount." << endl;
        }
    }

    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "Amount " << amount << " withdrawn. New balance: " << balance << endl;
        } else {
            cout << "Insufficient balance or invalid amount." << endl;
        }
    }

    void display() {
        cout << "Name: " << name << endl;
        cout << "Account Number: " << account_number << endl;
        cout << "Account Type: " << account_type << endl;
        cout << "Balance: " << balance << endl;
    }
};

int main() {
    BankAccount customers[5] = {
        BankAccount("Customer 1", 1001, "Savings", 1500),
        BankAccount("Customer 2", 1002, "Checking", 2000),
        BankAccount("Customer 3", 1003, "Savings", 3000),
        BankAccount("Customer 4", 1004, "Checking", 500),
        BankAccount("Customer 5", 1005, "Savings", 10000)
    };

    // Testing the bank accounts
    for (int i = 0; i < 5; ++i) {
        cout << "Customer " << i + 1 << ":" << endl;
        customers[i].display();
        cout << endl;

        customers[i].deposit(1000);
        customers[i].withdraw(500);

        cout << endl;
    }

    return 0;
}
