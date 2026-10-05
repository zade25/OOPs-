#include <iostream>
#include <string>
using namespace std;

// Function with two integer parameters
// This function returns the sum of two integers
int add(int a, int b)
{
    return a + b;
}

// Function with two double parameters
// This function returns the sum of two decimal numbers
double add(double a, double b)
{
    return a + b;
}

// Function with three integer parameters
// This function returns the sum of three integers
int add(int a, int b, int c)
{
    return a + b + c;
}

// Overloaded function with two string parameters
// This function joins (concatenates) two strings
string add(string a, string b)
{
    return a + b;
}

int main()
{
    // Display the program title and student name
    cout << "C++ Function Overloading Demonstration" << endl;
    cout << "Student: Prachi Zade" << endl;
    cout << "---------------------------------------" << endl;

    // Calling the overloaded function with two integers
    cout << "Sum of two integers: " << add(15, 25) << endl;

    // Calling the overloaded function with two double values
    cout << "Sum of two decimal numbers: " << add(4.5, 2.5) << endl;

    // Calling the overloaded function with three integers
    cout << "Sum of three integers: " << add(10, 20, 30) << endl;

    // Calling the overloaded function with two strings
    // The two strings are joined together
    cout << "Joined strings: " << add("Prachi ", "Zade") << endl;

    return 0; // End of the program
}