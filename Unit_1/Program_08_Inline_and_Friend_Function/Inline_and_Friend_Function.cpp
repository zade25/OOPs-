#include <iostream>
using namespace std;

// Define a Test class
class Test
{
private:
    // Private data member
    int value;

public:
    // Constructor to initialize the value
    Test(int v)
    {
        value = v;
    }

    // Inline function to return the private value
    inline int getValue()
    {
        return value;
    }

    // Declare show() as a friend function
    // It can access private members of Test
    friend void show(Test t);
};

// Friend function definition
// This function can directly access the private value
void show(Test t)
{
    cout << t.value;
}

int main()
{
    // Create a Test object with value 50
    Test obj(50);

    // Call the inline getter function
    cout << obj.getValue() << endl;

    // Call the friend function
    show(obj);

    return 0;
}