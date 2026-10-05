#include <iostream>
using namespace std;

// Base class
class Base
{
public:
    // Base class constructor
    Base()
    {
        cout << "Base constructor called" << endl;
    }

    // Virtual destructor
    // It ensures that the derived class destructor
    // is also called when deleting through a base pointer
    virtual ~Base()
    {
        cout << "Base destructor called" << endl;
    }
};

// Derived class inherited from Base
class Derived : public Base
{
public:
    // Derived class constructor
    Derived()
    {
        cout << "Derived constructor called" << endl;
    }

    // Derived class destructor
    ~Derived()
    {
        cout << "Derived destructor called" << endl;
    }
};

int main()
{
    // Display program title and student name
    cout << "Virtual Destructor Demonstration" << endl;
    cout << "Student: Prachi Zade" << endl;
    cout << "--------------------------------" << endl;

    // Create a Derived object using a Base class pointer
    Base* ptr = new Derived();

    // Delete the object using the base class pointer
    // Because the destructor is virtual, both destructors are called
    cout << "Deleting object using base pointer:" << endl;
    delete ptr;

    return 0; // End of the program
}