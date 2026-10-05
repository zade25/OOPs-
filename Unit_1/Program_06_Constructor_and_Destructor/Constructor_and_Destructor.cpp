#include <iostream>
using namespace std;

// Define a Demo class
class Demo
{
public:
    // Constructor
    // It is automatically called when the object is created
    Demo()
    {
        cout << "Constructor called" << endl;
    }

    // Destructor
    // It is automatically called when the object is destroyed
    ~Demo()
    {
        cout << "Destructor called" << endl;
    }
};

int main()
{
    // Create an object of the Demo class
    Demo d;

    return 0;
}