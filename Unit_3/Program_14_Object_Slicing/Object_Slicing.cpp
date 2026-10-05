#include <iostream>
using namespace std;

// Base class
class Base
{
public:
    int baseValue;

    // Constructor to initialize base value
    Base(int value = 10)
    {
        baseValue = value;
    }

    // Function to display the base class value
    void display() const
    {
        cout << "Base value: " << baseValue << endl;
    }
};

// Derived class inherits from Base
class Derived : public Base
{
public:
    int derivedValue;

    // Constructor to initialize base and derived values
    Derived(int b, int d) : Base(b)
    {
        derivedValue = d;
    }

    // Function to display both base and derived values
    void display() const
    {
        cout << "Base value: " << baseValue << endl;
        cout << "Derived value: " << derivedValue << endl;
    }
};

// Function that accepts a Base object by value
// This causes object slicing
void displayByValue(Base object)
{
    object.display();
}

// Function that accepts a Base object by reference
// The complete derived object is preserved
void displayByReference(const Base& object)
{
    object.display();
}

// Function that accepts a pointer to a Base object
// It is called using the address of the derived object
void displayByPointer(const Base* object)
{
    object->display();
}

int main()
{
    // Create a Derived class object
    Derived derivedObj(20, 30);

    // Display program title and student name
    cout << "Object Slicing Demonstration" << endl;
    cout << "Student: Prachi Zade" << endl;
    cout << "----------------------------" << endl;

    // Display the complete derived object
    cout << "Derived object:" << endl;
    derivedObj.display();

    // Assign Derived object to Base object
    // Only the Base part is copied, causing object slicing
    Base baseObj = derivedObj;

    cout << "After assigning Derived object to Base object:" << endl;
    baseObj.display();

    // Demonstrate passing the derived object by value
    cout << "Passing Derived object by value:" << endl;
    displayByValue(derivedObj);

    // Demonstrate passing the derived object by reference
    cout << "Passing Derived object by reference:" << endl;
    displayByReference(derivedObj);

    // Demonstrate passing the address of the derived object
    // using a Base class pointer
    cout << "Passing Derived object by pointer:" << endl;
    displayByPointer(&derivedObj);

    return 0;
}