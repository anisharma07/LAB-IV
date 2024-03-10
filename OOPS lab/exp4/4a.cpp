// Demonstrate the use of Class and Object in C++:

// 4a. Define a Class "Student" having following data members and member functions.
//      Data members:
//        1. Name of the Student.
//        2.Roll Number.
//        3. Department Name.
//      Member functions:
//        1. Enter Student Details.
//        2. Display Student Details.
//     Write a main program to create the object and test the program for 5 students.
#include <iostream>
#include <string>
using namespace std;
class Student
{
private:
    string Student_name;
    string Roll_number;
    string Department_name;

public:
    void Enter_student_details(void)
    {
        cout << "Student Name: ";
        getline(cin, Student_name);

        cout << "Student RollNo: ";
        getline(cin, Roll_number);

        cout << "Student's Department Name: ";
        getline(cin, Department_name);
    }
    void display_student_details(void)
    {
        cout << "Student Name: " << Student_name << endl;
        cout << "Roll Number: " << Roll_number << endl;
        cout << "Department Name: " << Department_name << endl;
    }
};
int main()
{
    Student students[5];
    for (int i = 0; i < 5; i++)
    {
        cout << "\nEnter details for Student: " << i + 1 << endl;
        students[i].Enter_student_details();
    };
    cout << "\nDetails of above five students are: "
         << endl;
    for (int j = 0; j < 5; j++)
    {
        cout << "\nDetails for student: " << j + 1 << endl;
        students[j].display_student_details();
    }
    return 0;
}