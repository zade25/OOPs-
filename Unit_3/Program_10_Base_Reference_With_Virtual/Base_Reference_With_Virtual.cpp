#include <iostream>
using namespace std;

// Base class
class Base
{
public:
    // Virtual function for run-time polymorphism
    virtual void show()
    {
        cout << "Base class show() function" << endl;
    }
};

// Derived class inherits from Base
class Derived : public Base
{
public:
    // Override the virtual function
    void show() override
    {
        cout << "Derived class show() function" << endl;
    }
};

// Function that accepts a reference to the Base class
// The virtual function allows the correct derived function to be called
void display(Base& ref)
{
    ref.show();
}

int main()
{
    // Create an object of the Derived class
    Derived obj;

    // Display program title and student name
    cout << "Base Reference With Virtual Function" << endl;
    cout << "Student: Prachi Zade" << endl;
    cout << "-----------------------------------" << endl;

    // Pass the derived object to the function as a base class reference
    cout << "Calling show() using base class reference:" << endl;
    display(obj);

    return 0; // End of the program
}