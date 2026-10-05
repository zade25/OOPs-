#include <iostream>
using namespace std;

// Base class
class Base
{
public:
    // Base class constructor
    Base()
    {
        cout << "Base constructor" << endl;
    }

    // Virtual destructor
    // It ensures proper destruction of derived objects
    virtual ~Base()
    {
        cout << "Base destructor" << endl;
    }
};

// Derived class
class Derived : public Base
{
public:
    // Derived class constructor
    Derived()
    {
        cout << "Derived constructor" << endl;
    }

    // Derived class destructor
    ~Derived()
    {
        cout << "Derived destructor" << endl;
    }
};

int main()
{
    // Create a Derived object using a Base class pointer
    Base* ptr = new Derived();

    // Delete the object through the base class pointer
    // Because the destructor is virtual,
    // the Derived destructor is called first
    delete ptr;

    return 0;
}