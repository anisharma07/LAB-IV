#include <iostream>
#include <vector>
using namespace std;

class Student
{
public:
    string name;
    int age;

    Student(string sname, int sage) : name(sname), age(sage) {}
};

int main()
{
    Student student1("Alice", 20);
    Student student2("Bob", 22);
    Student student3("Charlie", 19);

    vector<Student> students = {student1, student2, student3};

    Student youngestStudent = students[0];
    for (auto student : students)
    {
        if (student.age < youngestStudent.age)
        {
            youngestStudent = student;
        }
    }

    cout << "Youngest Student Details:" << endl;
    cout << "Name: " << youngestStudent.name << endl;
    cout << "Age: " << youngestStudent.age << endl;

    return 0;
}
