// Experiment 1
// Create a structure for student which should contain fields like roll No., name, CGPI, semester. Create an array of structure student to store this information about 10 students. Write individual functions to perform the following task:
// (a)	Insert a new record of student at kth position (value of k will be entered by the user at run time).
// (b)	Display the record of all students.
// (c)	Display records of all students having CGPI greater than k (value of k will be entered by the user at run time).

// Write a menu-driven program to implement above operations.
#include <iostream>
using namespace std;
struct Student
{
    string rollNo;
    string name;
    float cgpi;
    int semester;
};

const int MAX_STUDENTS = 10;

Student students[MAX_STUDENTS];
int currentSize = 0;

void tableHead();
void printStudentRecord(int i);

void insertRecord()
{
    int position = 0;
    cout << "Enter the index: ";
    cin >> position;
    if (position < 1 || position > currentSize + 1)
    {
        cout << "Invalid position. Record not inserted.\n";
        return;
    }
    if (currentSize >= MAX_STUDENTS)
    {
        cout << "Array is full. Cannot insert more records.\n";
        return;
    }

    Student newStudent;
    cout << "Enter Roll No: ";
    cin.ignore();
    getline(cin, newStudent.rollNo);
    cout << "Enter Name: ";
    getline(cin, newStudent.name);
    cout << "Enter CGPI: ";
    cin >> newStudent.cgpi;
    cout << "Enter Semester: ";
    cin >> newStudent.semester;

    for (int i = currentSize; i >= position; --i)
    {
        students[i] = students[i - 1];
    }
    students[position - 1] = newStudent;
    ++currentSize;
    cout << "Record inserted successfully.\n";
}

void displayAllRecords()
{
    if (currentSize == 0)
    {
        cout << "No records to display.\n";
        return;
    }

    cout << "Student Records:\n"
         << endl;
    tableHead();
    for (int i = 0; i < currentSize; ++i)
    {
        printStudentRecord(i);
    }
    cout << endl;
}

void displayRecordsByCGPI(float threshold)
{
    int checkIfRecord = 0;
    if (currentSize == 0)
    {
        cout << "No records to display.\n";
        return;
    }

    cout << "Student Records with CGPI greater than " << threshold << ":\n"
         << endl;
    tableHead();
    for (int i = 0; i < currentSize; ++i)
    {
        if (students[i].cgpi > threshold)
        {
            printStudentRecord(i);
            checkIfRecord++;
        }
    }
    if (checkIfRecord == 0)
    {
        cout << "no record to display" << endl;
    }
}

int main()
{
    int choice;
    do
    {
        cout << "---- --- --- --- --- --- --- --- ----" << endl;
        cout << "1. Insert a new record" << endl;
        cout << "2. Display record of all students" << endl;
        cout << "3. Display the record of students with cgpi > k" << endl;
        cout << "4.Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            insertRecord();
            break;

        case 2:
            displayAllRecords();
            break;
        case 3:
            float i;
            cout << "threshold cgpi: " << endl;
            cin >> i;
            displayRecordsByCGPI(i);
            break;
        case 4:
            cout << "Exiting Program...." << endl;
            break;
        default:
            cout << "Enter a valid choice!" << endl;
        }
    } while (choice != 4);
    return 0;
}

void tableHead()
{
    cout << "---- --- --- --- --- --- --- --- ----\n"
         << endl;
    cout << "Semester"
         << "\t"
         << "CGPI"
         << "\t\t"
         << "Roll No."
         << "\t\t"
         << "Name"
         << endl;
}

void printStudentRecord(int i)
{
    cout << students[i].semester << "\t\t" << students[i].cgpi << "\t\t" << students[i].rollNo << "\t\t" << students[i].name
         << "\n";
}