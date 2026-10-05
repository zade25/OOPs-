#include <iostream>
using namespace std;

// Abstract base class
class Shape
{
public:
    // Pure virtual function
    // This makes Shape an abstract class
    virtual void area() const = 0;
};

// Derived class Rectangle
class Rectangle : public Shape
{
private:
    int length;
    int width;

public:
    // Constructor to initialize rectangle dimensions
    Rectangle(int l, int w)
        : length(l), width(w)
    {
    }

    // Override the pure virtual function
    void area() const override
    {
        cout << "Area of Rectangle: " << length * width << endl;
    }
};

// Derived class Circle
class Circle : public Shape
{
private:
    double radius;

public:
    // Constructor to initialize radius
    Circle(double r)
        : radius(r)
    {
    }

    // Override the pure virtual function
    void area() const override
    {
        cout << "Area of Circle: "
             << 3.14159 * radius * radius << endl;
    }
};

int main()
{
    // Create objects of derived classes
    Rectangle rectangle(10, 5);
    Circle circle(4);

    // Call the overridden area() functions
    rectangle.area();
    circle.area();

    return 0;
}