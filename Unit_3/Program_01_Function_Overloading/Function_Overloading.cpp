#include <iostream>
using namespace std;

// Function with two integer parameters
int add(int a, int b)
{
    return a + b;
}

// Function with two double parameters
double add(double a, double b)
{
    return a + b;
}

// Function with three integer parameters
int add(int a, int b, int c)
{
    return a + b + c;
}

int main()
{
    cout << "C++ Function Overloading Demonstration" << endl;
    cout << "Student: Prachi Zade" << endl;
    cout << "---------------------------------------" << endl;

    cout << "Sum of two integers: " << add(15, 25) << endl;
    cout << "Sum of two decimal numbers: " << add(4.5, 2.5) << endl;
    cout << "Sum of three integers: " << add(10, 20, 30) << endl;

    return 0;
}