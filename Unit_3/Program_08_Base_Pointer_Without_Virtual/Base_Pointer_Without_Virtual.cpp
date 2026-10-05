#include <iostream>
using namespace std;

// Base class
class Base
{
public:
    // Function of the base class
    void show()
    {
        cout << "Base class show() function" << endl;
    }
};

// Derived class inherits from Base
class Derived : public Base
{
public:
    // Function of the derived class
    // This hides the base class show() function
    void show()
    {
        cout << "Derived class show() function" << endl;
    }
};

int main()
{
    // Create an object of the derived class
    Derived obj;

    // Create a base class pointer pointing to the derived object
    Base* ptr = &obj;

    // Display program title and student name
    cout << "Base Pointer Without Virtual Function" << endl;
    cout << "Student: Prachi Zade" << endl;
    cout << "-------------------------------------" << endl;

    // Call show() using the base class pointer
    // Since show() is not virtual, the Base class function is called
    cout << "Calling show() using base class pointer:" << endl;
    ptr->show();

    // Call show() directly using the derived object
    // The Derived class function is called
    cout << "Calling show() directly using derived object:" << endl;
    obj.show();

    return 0; // End of the program
}