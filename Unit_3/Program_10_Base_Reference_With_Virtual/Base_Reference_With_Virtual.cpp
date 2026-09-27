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

void display(Base& ref)
{
    ref.show();
}

int main()
{
    Derived obj;

    cout << "Base Reference With Virtual Function" << endl;
    cout << "Student: Prachi Zade" << endl;
    cout << "-----------------------------------" << endl;

    cout << "Calling show() using base class reference:" << endl;
    display(obj);

    return 0;
}