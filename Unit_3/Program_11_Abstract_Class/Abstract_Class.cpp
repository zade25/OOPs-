#include <iostream>
using namespace std;

class Shape
{
public:
    virtual void area() = 0;
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
        cout << "Area of rectangle: " << length * width << endl;
    }
};

int main()
{
    Rectangle rectangle(8, 5);

    cout << "Abstract Class Demonstration" << endl;
    cout << "Student: Prachi Zade" << endl;
    cout << "----------------------------" << endl;

    rectangle.area();

    return 0;
}