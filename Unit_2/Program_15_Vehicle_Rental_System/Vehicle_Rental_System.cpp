#include <iostream>
using namespace std;

// Base class
class Person
{
protected:
    string name;

public:
    // Constructor to initialize the name
    Person(string n)
    {
        name = n;
    }

    // Function to display the name
    void displayName() const
    {
        cout << "Name: " << name << endl;
    }
};

// Student inherits from Person
class Student : public Person
{
protected:
    int rollNumber;

public:
    // Constructor to initialize Student details
    Student(string n, int r)
        : Person(n)
    {
        rollNumber = r;
    }

    // Function to display student details
    void displayStudent() const
    {
        cout << "Roll Number: " << rollNumber << endl;
    }
};

// Employee also inherits from Person
class Employee : public Person
{
protected:
    int employeeId;

public:
    // Constructor to initialize Employee details
    Employee(string n, int id)
        : Person(n)
    {
        employeeId = id;
    }

    // Function to display employee details
    void displayEmployee() const
    {
        cout << "Employee ID: " << employeeId << endl;
    }
};

// TeachingAssistant inherits from both Student and Employee
class TeachingAssistant : public Student, public Employee
{
public:
    // Constructor to initialize both base classes
    TeachingAssistant(string n, int r, int id)
        : Student(n, r), Employee(n, id)
    {
    }

    // Function to display Teaching Assistant details
    void display() const
    {
        cout << "Teaching Assistant Details" << endl;

        // Access Student's copy of Person
        cout << "Student Side:" << endl;
        Student::displayName();
        displayStudent();

        // Access Employee's copy of Person
        cout << "Employee Side:" << endl;
        Employee::displayName();
        displayEmployee();
    }
};

int main()
{
    // Create a TeachingAssistant object
    TeachingAssistant assistant("Prachi", 62, 1001);

    // Display all details
    assistant.display();

    return 0;
}