#include <iostream>
using namespace std;

// Function to calculate the area of a square
// Takes one integer parameter: side
int calculateArea(int side)
{
    return side * side;
}

// Function to calculate the area of a rectangle
// Takes two integer parameters: length and width
int calculateArea(int length, int width)
{
    return length * width;
}

// Function to calculate the area of a circle
// Takes radius as a double value
double calculateArea(double radius)
{
    constexpr double PI = 3.141592653589793;
    return PI * radius * radius;
}

// Overloaded function to calculate the area of a triangle
// Takes base and height as double values
double calculateArea(double base, double height)
{
    return 0.5 * base * height;
}

int main()
{
    // Display program title and student name
    cout << "Area Calculator Using Function Overloading" << endl;
    cout << "Student: Prachi Zade" << endl;
    cout << "------------------------------------------" << endl;

    // Calculate and display the area of a square
    cout << "Square Area: " << calculateArea(7) << endl;

    // Calculate and display the area of a rectangle
    cout << "Rectangle Area: " << calculateArea(8, 5) << endl;

    // Calculate and display the area of a circle
    cout << "Circle Area: " << calculateArea(3.0) << endl;

    // Calculate and display the area of a triangle
    cout << "Triangle Area: " << calculateArea(6.0, 4.0) << endl;

    return 0; // End of the program
}