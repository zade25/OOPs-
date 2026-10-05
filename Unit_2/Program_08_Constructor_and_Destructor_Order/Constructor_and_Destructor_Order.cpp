#include <iostream>
using namespace std;

// Base class
class A
{
public:
    // Constructor of class A
    A()
    {
        cout << "Constructor of A" << endl;
    }
};

// Class B inherits from A
class B : public A
{
public:
    // Constructor of class B
    B()
    {
        cout << "Constructor of B" << endl;
    }
};

// Class C inherits from B
class C : public B
{
public:
    // Constructor of class C
    C()
    {
        cout << "Constructor of C" << endl;
    }
};

int main()
{
    // Create an object of class C
    // Constructors are called from base to derived
    C object;

    return 0;
}