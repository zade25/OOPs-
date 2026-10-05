#include <iostream>
using namespace std;

// Base class
class Employee
{
public:
    // Virtual function
    // It can be overridden by the derived class
    virtual void display() const
    {
        cout << "Employee class display function" << endl;
    }

    // Virtual destructor
    virtual ~Employee() = default;
};

// Derived class
class Manager : public Employee
{
public:
    // Override the base class display() function
    void display() const override
    {
        cout << "Manager class display function" << endl;
    }
};

int main()
{
    // Create a Manager object
    Manager manager;

    // Create a base class pointer pointing to Manager object
    Employee* employee = &manager;

    // Runtime polymorphism calls Manager's display()
    employee->display();

    return 0;
}