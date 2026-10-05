#include <iostream>
using namespace std;

// Common base class
class Person
{
public:
    // Function to display a message
    void show() const
    {
        cout << "Person class function" << endl;
    }
};

// Student virtually inherits from Person
class Student : virtual public Person
{
};

// Employee virtually inherits from Person
class Employee : virtual public Person
{
};

// Intern inherits from both Student and Employee
class Intern : public Student, public Employee
{
};

int main()
{
    // Create an object of Intern
    Intern intern;

    // Because Person is a virtual base class,
    // only one copy of Person exists in Intern.
    intern.show();

    return 0;
}