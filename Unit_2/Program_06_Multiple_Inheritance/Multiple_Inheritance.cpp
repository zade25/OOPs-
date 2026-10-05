#include <iostream>
using namespace std;

// First base class
class Camera
{
public:
    // Function to take a photo
    void takePhoto() const
    {
        cout << "Photo taken" << endl;
    }
};

// Second base class
class Phone
{
public:
    // Function to make a phone call
    void makeCall() const
    {
        cout << "Call made" << endl;
    }
};

// Derived class inherits from both Camera and Phone
class SmartPhone : public Camera, public Phone
{
public:
    // Function specific to SmartPhone
    void browseInternet() const
    {
        cout << "Browsing internet" << endl;
    }
};

int main()
{
    // Create a SmartPhone object
    SmartPhone smartphone;

    // Access the function inherited from Camera
    smartphone.takePhoto();

    // Access the function inherited from Phone
    smartphone.makeCall();

    // Access the SmartPhone's own function
    smartphone.browseInternet();

    return 0;
}