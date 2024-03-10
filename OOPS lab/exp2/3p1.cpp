#include <iostream>
using namespace std;

struct personal
{
    char p_name[20];
    char doj[8];
    float salary;
};
union per

{
    char p_name[20];
    char doj[8];
    float salary;
};
void read(struct personal *p)
{
    cout << "ENTER PERSON NAME:";
    cin >> (p->p_name);
    cout << "ENTER  DATE OF JOINING:";
    cin >> (p->doj);
    cout << "ENTER SALARY:";
    cin >> (p->salary);
}

void print(struct personal *p)
{
    cout << "NAME OF PERSON IS: " << p->p_name << endl;
    cout << "DATE OF JOINING IS: " << p->doj << endl;
    cout << "THE SALARY OF THE PERSON IS :" << p->salary << endl;
}
int main()
{

    struct personal p1;
    union per p2;
    read(&p1);
    print(&p1);

    cout << "THE SIZE OF STRUCTURE PERSONAL IS " << sizeof(p1) << endl;
    cout << "THE SIZE OF STRUCTURE PERSONAL NAME IS " << sizeof(p1.p_name) << endl;
    cout << "THE SIZE OF STRUCTURE PERSONAL DOJ IS " << sizeof(p1.doj) << endl;
    cout << "THE SIZE OF STRUCTURE PERSONAL SALARY IS " << sizeof(p1.salary) << endl;

    cout << endl
         << "THE SIZE OF UNION PERSONAL IS " << sizeof(p2) << endl;
    cout << "THE SIZE OF UNION PERSONAL NAME IS " << sizeof(p2.p_name) << endl;
    cout << "THE SIZE OF UNION PERSONAL DOJ IS " << sizeof(p2.doj) << endl;
    cout << "THE SIZE OF UNION PERSONAL SALARY IS " << sizeof(p2.salary) << endl;

    return 0;
}