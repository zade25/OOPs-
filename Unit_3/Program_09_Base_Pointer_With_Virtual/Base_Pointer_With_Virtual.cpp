#include <iostream>
using namespace std;

class Base
{
public:
    virtual void show()
    {
        cout << "Base class show() function" << endl;
    }
};

class Derived : public Base
{
public:
    void show() override
    {
        cout << "Derived class show() function" << endl;
    }
};

int main()
{
    Derived obj;
    Base* ptr = &obj;

    cout << "Base Pointer With Virtual Function" << endl;
    cout << "Student: Prachi Zade" << endl;
    cout << "----------------------------------" << endl;

    cout << "Calling show() using base class pointer:" << endl;
    ptr->show();

    return 0;
}