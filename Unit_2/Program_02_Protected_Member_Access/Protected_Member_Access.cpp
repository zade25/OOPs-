#include <iostream>
#include <string>
#include <utility>
using namespace std;

// Base class
class Employee
{
protected:
    // Protected member can be accessed inside the derived class
    string name;

public:
    // Constructor to initialize employee name
    explicit Employee(string employeeName)
        : name(std::move(employeeName))
    {
    }
};

// Derived class inheriting from Employee
class Developer : public Employee
{
private:
    // Private member to store programming language
    string language;

public:
    // Constructor to initialize base and derived members
    Developer(string employeeName, string programmingLanguage)
        : Employee(std::move(employeeName)),
          language(std::move(programmingLanguage))
    {
    }

    // Function to display developer details
    void display() const
    {
        // Access the protected name directly from the base class
        cout << "Developer: " << name << endl;

        // Display the private language member
        cout << "Language: " << language << endl;
    }
};

int main()
{
    // Create a Developer object
    Developer developer("Neha", "C++");

    // Display developer details
    developer.display();

    return 0;
}