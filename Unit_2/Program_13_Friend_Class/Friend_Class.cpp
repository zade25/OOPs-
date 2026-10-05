#include <iostream>
using namespace std;

// First base class
class A
{
public:
    // Function with the same name as class B
    void show() const
    {
        cout << "Show function of class A" << endl;
    }
};

// Second base class
class B
{
public:
    // Function with the same name as class A
    void show() const
    {
        cout << "Show function of class B" << endl;
    }
};

// Derived class inherits from both A and B
class C : public A, public B
{
};

int main()
{
    // Create an object of derived class
    C object;

    // Calling show() directly would be ambiguous:
    // object.show();

    // Specify the base class to remove ambiguity
    object.A::show();

    // Call the show() function of class B
    object.B::show();

    return 0;
}