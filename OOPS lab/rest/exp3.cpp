#include <iostream>
#include <algorithm>

using namespace std;
class Employee
{
public:
    int employeeID;
    string name;
    double salary;

    Employee(int id, const string empName, double empSalary)
        : employeeID(id), name(empName), salary(empSalary) {}
};

bool compareBySalary(Employee &emp1, Employee &emp2)
{
    return emp1.salary < emp2.salary;
}

int main()
{
    const int numEmployees = 4;
    Employee employees[numEmployees] = {
        Employee(101, "Alice", 50000.0),
        Employee(102, "Bob", 60000.0),
        Employee(103, "Charlie", 55000.0),
        Employee(104, "David", 48000.0)};

    // Sort the employees based on salary in ascending order
    sort(employees, employees + numEmployees, compareBySalary);

    // Display the sorted employee details
    cout << "Employees Sorted by Salary (Ascending):" << endl;
    for (int i = 0; i < numEmployees; ++i)
    {
        const Employee &employee = employees[i];
        cout << "ID: " << employee.employeeID << ", Name: " << employee.name << ", Salary: " << employee.salary << endl;
    }

    return 0;
}
