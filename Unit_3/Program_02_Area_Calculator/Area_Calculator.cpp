#include <iostream>
using namespace std;

int calculateArea(int side)
{
    return side * side;
}

int calculateArea(int length, int width)
{
    return length * width;
}

double calculateArea(double radius)
{
    constexpr double PI = 3.141592653589793;
    return PI * radius * radius;
}

// Overloaded function for triangle
double calculateArea(double base, double height)
{
    return 0.5 * base * height;
}

int main()
{
    cout << "Area Calculator Using Function Overloading" << endl;
    cout << "Student: Prachi Zade" << endl;
    cout << "------------------------------------------" << endl;

    cout << "Square Area: " << calculateArea(7) << endl;
    cout << "Rectangle Area: " << calculateArea(8, 5) << endl;
    cout << "Circle Area: " << calculateArea(3.0) << endl;
    cout << "Triangle Area: " << calculateArea(6.0, 4.0) << endl;

    return 0;
}