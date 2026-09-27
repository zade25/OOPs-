#include <iostream>
using namespace std;

class Base
{
public:
    void show()
    {
        cout << "Base class show() function" << endl;
    }
};

class Derived : public Base
{
public:
    void show()
    {
        cout << "Derived class show() function" << endl;
    }
};

int main()
{
    Derived obj;
    Base* ptr = &obj;

    cout << "Base Pointer Without Virtual Function" << endl;
    cout << "Student: Prachi Zade" << endl;
    cout << "-------------------------------------" << endl;

    cout << "Calling show() using base class pointer:" << endl;
    ptr->show();

    cout << "Calling show() directly using derived object:" << endl;
    obj.show();

    return 0;
}