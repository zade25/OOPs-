#include <iostream>
using namespace std;

// Abstract base class
class Shape
{
public:
    // Pure virtual function
    virtual void area() = 0;

    // Virtual destructor for safe cleanup
    virtual ~Shape() {}
};

// Derived class for Circle
class Circle : public Shape
{
private:
    double radius;

public:
    // Constructor to initialize radius
    Circle(double r)
    {
        radius = r;
    }

    // Override area() function
    void area() override
    {
        cout << "Area of Circle: " << 3.14159 * radius * radius << endl;
    }
};

// Derived class for Rectangle
class Rectangle : public Shape
{
private:
    int length;
    int width;

public:
    // Constructor to initialize length and width
    Rectangle(int l, int w)
    {
        length = l;
        width = w;
    }

    // Override area() function
    void area() override
    {
        cout << "Area of Rectangle: " << length * width << endl;
    }
};

// Derived class for Triangle
class Triangle : public Shape
{
private:
    double base;
    double height;

public:
    // Constructor to initialize base and height
    Triangle(double b, double h)
    {
        base = b;
        height = h;
    }

    // Override area() function
    void area() override
    {
        cout << "Area of Triangle: " << 0.5 * base * height << endl;
    }
};

int main()
{
    // Create objects of different shapes
    Circle circle(4);
    Rectangle rectangle(8, 5);
    Triangle triangle(6, 4);

    // Create an array of base class pointers
    Shape* shapes[3];

    // Store addresses of different derived objects
    shapes[0] = &circle;
    shapes[1] = &rectangle;
    shapes[2] = &triangle;

    // Display program title and student name
    cout << "Collection of Shape Pointers" << endl;
    cout << "Student: Prachi Zade" << endl;
    cout << "----------------------------" << endl;

    // Call the correct area() function using polymorphism
    for (int i = 0; i < 3; i++)
    {
        shapes[i]->area();
    }

    return 0; // End of the program
}