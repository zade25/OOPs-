#include <iostream>
#include <string>
#include <utility>
using namespace std;

// Base class
class Vehicle
{
protected:
    // Protected member to store the vehicle registration number
    string registrationNumber;

public:
    // Constructor to initialize the registration number
    explicit Vehicle(string registration)
        : registrationNumber(std::move(registration))
    {
    }

    // Function to start the vehicle
    void start() const
    {
        cout << "Vehicle " << registrationNumber << " started" << endl;
    }
};

// Derived class Car inherits from Vehicle
class Car : public Vehicle
{
public:
    // Constructor to initialize the Car using the base class constructor
    explicit Car(string registration)
        : Vehicle(std::move(registration))
    {
    }

    // Function specific to Car
    void openBoot() const
    {
        cout << "Car boot opened" << endl;
    }
};

// Derived class Bike inherits from Vehicle
class Bike : public Vehicle
{
public:
    // Constructor to initialize the Bike using the base class constructor
    explicit Bike(string registration)
        : Vehicle(std::move(registration))
    {
    }

    // Function specific to Bike
    void helmetReminder() const
    {
        cout << "Please wear a helmet" << endl;
    }
};

int main()
{
    // Create a Car object
    Car car("MH12AB1234");

    // Create a Bike object
    Bike bike("MH12CD5678");

    // Call the common Vehicle function for Car
    car.start();

    // Call the Car-specific function
    car.openBoot();

    // Call the common Vehicle function for Bike
    bike.start();

    // Call the Bike-specific function
    bike.helmetReminder();

    return 0;
}