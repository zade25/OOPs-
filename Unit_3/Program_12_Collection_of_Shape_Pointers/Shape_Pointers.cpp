#include <iostream>
using namespace std;

class Shape
{
public:
    virtual void area() = 0;

    virtual ~Shape() {}
};

class Circle : public Shape
{
private:
    double radius;

public:
    Circle(double r)
    {
        radius = r;
    }

    void area() override
    {
        cout << "Area of Circle: " << 3.14159 * radius * radius << endl;
    }
};

class Rectangle : public Shape
{
private:
    int length;
    int width;

public:
    Rectangle(int l, int w)
    {
        length = l;
        width = w;
    }

    void area() override
    {
        cout << "Area of Rectangle: " << length * width << endl;
    }
};

int main()
{
    Circle circle(4);
    Rectangle rectangle(8, 5);

    Shape* shapes[2];

    shapes[0] = &circle;
    shapes[1] = &rectangle;

    cout << "Collection of Shape Pointers" << endl;
    cout << "Student: Prachi Zade" << endl;
    cout << "----------------------------" << endl;

    for (int i = 0; i < 2; i++)
    {
        shapes[i]->area();
    }

    return 0;
}