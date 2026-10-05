#include <iostream>
using namespace std;

// Base class
class Base
{
public:
    // Virtual function
    virtual void show()
    {
        cout << "Base class show() function" << endl;
    }
};

// Derived class
class Derived : public Base
{
public:
    // Override the virtual function
    void show() override
    {
        cout << "Derived class show() function" << endl;
    }
};

// Another derived class to demonstrate virtual functions
class Cow : public Base
{
public:
    // Override the virtual function
    void show() override
    {
        cout << "Cow moos" << endl;
    }
};

int main()
{
    // Create a Derived object
    Derived obj;

    // Base class pointer pointing to Derived object
    Base* ptr = &obj;

    // Display program title and student name
    cout << "Base Pointer With Virtual Function" << endl;
    cout << "Student: Prachi Zade" << endl;
    cout << "----------------------------------" << endl;

    // Virtual function call using base class pointer
    // Derived class function is called at runtime
    cout << "Calling show() using base class pointer:" << endl;
    ptr->show();

    // Create a Cow object
    Cow cow;

    // Base class pointer pointing to Cow object
    ptr = &cow;

    // Virtual function call for Cow object
    cout << "Calling show() for Cow object:" << endl;
    ptr->show();

    return 0; // End of the program
}