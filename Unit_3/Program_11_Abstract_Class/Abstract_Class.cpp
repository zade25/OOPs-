#include <iostream>
using namespace std;

// Abstract base class
class Shape
{
public:
    // Pure virtual function
    // This makes Shape an abstract class
    virtual void area() = 0;
};

// Derived class for Rectangle
class Rectangle : public Shape
{
private:
    int length;
    int width;

public:
    // Constructor to initialize rectangle dimensions
    Rectangle(int l, int w)
    {
        length = l;
        width = w;
    }

    // Override the pure virtual area() function
    void area() override
    {
        cout << "Area of rectangle: " << length * width << endl;
    }
};

// Derived class for Triangle
class Triangle : public Shape
{
private:
    double base;
    double height;

public:
    // Constructor to initialize triangle dimensions
    Triangle(double b, double h)
    {
        base = b;
        height = h;
    }

    // Override the pure virtual area() function
    // Formula: 0.5 × base × height
    void area() override
    {
        cout << "Area of triangle: " << 0.5 * base * height << endl;
    }
};

int main()
{
    // Create a Rectangle object
    Rectangle rectangle(8, 5);

    // Create a Triangle object
    Triangle triangle(6, 4);

    // Display program title and student name
    cout << "Abstract Class Demonstration" << endl;
    cout << "Student: Prachi Zade" << endl;
    cout << "----------------------------" << endl;

    // Display the area of rectangle
    rectangle.area();

    // Display the area of triangle
    triangle.area();

    return 0; // End of the program
}