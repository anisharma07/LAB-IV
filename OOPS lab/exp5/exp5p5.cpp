#include <iostream>
using namespace std;
class Date
{
private:
    int day;
    int month;
    int year;

public:
    Date(int d, int m, int y) : day(d), month(m), year(y){};

    bool operator==(const Date &other) // == operator overloaded
    {
        return (day == other.day && month == other.month && year == other.year);
    }
};
int main()
{
    Date D1(03, 10, 2023);
    Date D2(03, 11, 2023);
    Date D3(10, 10, 2022);
    Date D4(03, 10, 2023);

    if (D1 == D2)
    {
        cout << "Date1 = Date2" << endl;
    }
    else
    {
        cout << "Date1 != Date2" << endl;
    }
    if (D1 == D3)
    {
        cout << "Date1 = Date3" << endl;
    }
    else
    {
        cout << "Date1 != Date3" << endl;
    }
    if (D1 == D4)
    {
        cout << "Date1 = Date4" << endl;
    }
    else
    {
        cout << "Date1 != Date4" << endl;
    }

    return 0;
}