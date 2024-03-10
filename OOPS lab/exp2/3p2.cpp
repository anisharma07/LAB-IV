// To calculate total marks(including endSem, midSem and internal) for a particular subject.

#include <iostream>
#include <string>

using namespace std;
// Define the structure for student information
struct Student
{
    int rollNo;
    int marks[3]; // Assuming 3 subjects
};

// Function to input student data
int inputStudentData(Student &student)
{
    cout << "Enter Roll No: ";
    cin >> student.rollNo;

    cout << "Enter marks for midSem:\n";
    cin >> student.marks[0];

    cout << "Enter marks for EndSem:\n";
    cin >> student.marks[1];

    cout << "Enter marks for Internal:\n";
    cin >> student.marks[2];

    return 0;
}

// Function to calculate total marks
int calculateTotalMarks(const Student &student)
{
    int total = 0;
    for (int i = 0; i < 3; ++i)
    {
        total += student.marks[i];
    }
    return total;
}

int main()
{
    const int numStudents = 1;
    Student students[numStudents];

    // Input data for each student
    for (int i = 0; i < numStudents; ++i)
    {
        cout << "\nEnter data for Student " << i + 1 << ":\n";
        inputStudentData(students[i]);
    }

    // Calculate and display total marks for each student
    cout << "\nTotal Marks Obtained by Each Student:\n";
    for (int i = 0; i < numStudents; ++i)
    {
        int totalMarks = calculateTotalMarks(students[i]);
        cout << "Student " << i + 1 << " - Roll No: " << students[i].rollNo
             << ", Total Marks: " << totalMarks << endl;
    }

    return 0;
}