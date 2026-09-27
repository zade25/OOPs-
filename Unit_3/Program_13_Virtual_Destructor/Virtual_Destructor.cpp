#include <iostream>
using namespace std;

class Base
{
public:
    Base()
    {
        cout << "Base constructor called" << endl;
    }

    virtual ~Base()
    {
        cout << "Base destructor called" << endl;
    }
};

class Derived : public Base
{
public:
    Derived()
    {
        cout << "Derived constructor called" << endl;
    }

    ~Derived()
    {
        cout << "Derived destructor called" << endl;
    }
};

int main()
{
    cout << "Virtual Destructor Demonstration" << endl;
    cout << "Student: Prachi Zade" << endl;
    cout << "--------------------------------" << endl;

    Base* ptr = new Derived();

    cout << "Deleting object using base pointer:" << endl;
    delete ptr;

    return 0;
}