#include <iostream>
#include <string>
#include <utility>
using namespace std;

// Base class
class Person
{
protected:
    // Protected member to store the person's name
    string name;

public:
    // Constructor to initialize the person's name
    explicit Person(string personName)
        : name(std::move(personName))
    {
    }

    // Function to display person's details
    void showPerson() const
    {
        cout << "Name: " << name << endl;
    }
};

// Employee inherits from Person
class Employee : public Person
{
protected:
    // Protected member to store employee ID
    int employeeId;

public:
    // Constructor to initialize Person and Employee members
    Employee(string employeeName, int id)
        : Person(std::move(employeeName)), employeeId(id)
    {
    }

    // Function to display employee details
    void showEmployee() const
    {
        cout << "Employee ID: " << employeeId << endl;
    }
};

// Manager inherits from Employee
class Manager : public Employee
{
private:
    // Private member to store team size
    int teamSize;

public:
    // Constructor to initialize all three levels
    Manager(string managerName, int id, int size)
        : Employee(std::move(managerName), id), teamSize(size)
    {
    }

    // Function to display manager details
    void showManager() const
    {
        // Call the Person class function
        showPerson();

        // Call the Employee class function
        showEmployee();

        // Display manager's team size
        cout << "Team Size: " << teamSize << endl;
    }
};

int main()
{
    // Create a Manager object
    Manager manager("Ravi", 501, 8);

    // Display all manager details
    manager.showManager();

    return 0;
}