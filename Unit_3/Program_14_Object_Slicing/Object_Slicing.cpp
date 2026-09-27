#include <iostream>
using namespace std;

class Base
{
public:
    int baseValue;

    Base(int value = 10)
    {
        baseValue = value;
    }

    void display()
    {
        cout << "Base value: " << baseValue << endl;
    }
};

class Derived : public Base
{
public:
    int derivedValue;

    Derived(int b, int d) : Base(b)
    {
        derivedValue = d;
    }

    void display()
    {
        cout << "Base value: " << baseValue << endl;
        cout << "Derived value: " << derivedValue << endl;
    }
};

int main()
{
    Derived derivedObj(20, 30);

    cout << "Object Slicing Demonstration" << endl;
    cout << "Student: Prachi Zade" << endl;
    cout << "----------------------------" << endl;

    cout << "Derived object:" << endl;
    derivedObj.display();

    Base baseObj = derivedObj;

    cout << "After assigning Derived object to Base object:" << endl;
    baseObj.display();

    return 0;
}