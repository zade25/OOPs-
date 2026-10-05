#include <iostream>
using namespace std;

// Base class
class Base
{
public:
    // Public function of the base class
    void show() const
    {
        cout << "Base public function" << endl;
    }
};

// Public inheritance
class PublicDerived : public Base
{
    // Base public members remain public
};

// Private inheritance
class PrivateDerived : private Base
{
public:
    // Function to call the private inherited base function
    void callBaseShow() const
    {
        show();
    }
};

int main()
{
    // Create an object of PublicDerived
    PublicDerived publicObject;

    // Public inheritance allows direct access to show()
    publicObject.show();

    // Create an object of PrivateDerived
    PrivateDerived privateObject;

    // Access the inherited function through a public member function
    privateObject.callBaseShow();

    // privateObject.show();
    // This would give an error because show() is private
    // through private inheritance.

    return 0;
}