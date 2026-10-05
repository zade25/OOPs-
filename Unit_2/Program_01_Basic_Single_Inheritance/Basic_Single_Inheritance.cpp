#include <iostream>
#include <string>
#include <utility>
using namespace std;

// Base class
class Person
{
protected:
    // Protected member can be accessed by the derived class
    string name;

public:
    // Constructor to initialize the person's name
    explicit Person(string personName)
        : name(std::move(personName))
    {
    }

    // Function to display the person's name
    void displayName() const
    {
        cout << "Name: " << name << endl;
    }
};

// Derived class inheriting from Person
class Student : public Person
{
private:
    // Private member to store the student's roll number
    int rollNumber;

public:
    // Constructor to initialize both base and derived members
    Student(string studentName, int roll)
        : Person(std::move(studentName)), rollNumber(roll)
    {
    }

    // Function to display student details
    void displayStudent() const
    {
        // Call the base class function
        displayName();

        // Display the roll number
        cout << "Roll Number: " << rollNumber << endl;
    }
};

int main()
{
    // Create a Student object
    Student student("Amit", 101);

    // Display the student's details
    student.displayStudent();

    return 0;
}