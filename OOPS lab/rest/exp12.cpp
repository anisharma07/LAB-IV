#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>
using namespace std;

struct Employee
{
    string name;
    string department;
    double salary;
};

int main()
{
    ifstream file("/home/anirudh/Desktop/c programs/CS_lab/rest/employee.csv");
    if (!file)
    {
        cerr << "Failed to open the CSV file." << endl;
        return 1;
    }

    map<int, Employee> employeeMap; // Using employee ID as the key

    string line;
    getline(file, line); // Read and discard the header line

    while (getline(file, line))
    {
        istringstream lineStream(line);
        string token;
        int employeeID;

        // Parse the CSV line
        if (getline(lineStream, token, ','))
            employeeID = stoi(token);
        else
            continue; // Skip lines with missing data

        Employee employee;
        if (getline(lineStream, employee.name, ',') &&
            getline(lineStream, employee.department, ',') &&
            getline(lineStream, token, ','))
        {
            employee.salary = stod(token);
        }
        else
        {
            continue; // Skip lines with missing data
        }

        employeeMap[employeeID] = employee;
    }

    // Search for an employee by ID
    int searchID;
    cout << "Enter the employee id you want to find: ";
    cin >> searchID;
    auto it = employeeMap.find(searchID);

    if (it != employeeMap.end())
    {
        cout << "Employee ID: " << it->first << "\n";
        cout << "Name: " << it->second.name << "\n";
        cout << "Department: " << it->second.department << "\n";
        cout << "Salary: $" << it->second.salary << "\n";
    }
    else
    {
        cout << "Employee not found." << endl;
    }

    return 0;
}
