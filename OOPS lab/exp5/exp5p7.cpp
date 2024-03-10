#include <iostream>
using namespace std;

class shape
{
public:
    virtual double area()
    {
        return 0.0;
    }
};
class circle : public shape
{
    double rad;
    double pi = 3.1415;

public:
    circle(double r) : rad(r) {}
    double area()
    {
        return pi * rad * rad;
    }
};
class rectangle : public shape
{
    double l, b;

public:
    rectangle(double x, double y) : l(x), b(y) {}
    double area()
    {
        return l * b;
    }
};

class triangle : public shape
{
    double b, h;

public:
    triangle(double base, double height) : b(base), h(height) {}
    double area()
    {
        return 0.5 * b * h;
    }
};
int main()
{
    circle c(2.34);
    rectangle r(50, 10);
    triangle t(30, 1.4);
    shape *ptr = &c;
    cout << "Area of Circle: " << ptr->area() << endl;
    ptr = &r;
    cout << "Area of rectangle is: " << ptr->area() << endl;
    ptr = &t;
    cout << "Area of triangle is: " << ptr->area() << endl;
    return 0;
}