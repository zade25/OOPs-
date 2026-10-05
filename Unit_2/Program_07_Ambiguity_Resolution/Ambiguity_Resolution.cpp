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
    // Base class constructor
    explicit Person(string personName)
        : name(std::move(personName))
    {
        cout << "Person constructor called" << endl;
    }
};

// Derived class inherits from Person
class Student : public Person
{
private:
    // Private member to store the student's roll number
    int rollNumber;

public:
    // Derived class constructor
    // First calls the Person constructor
    Student(string studentName, int roll)
        : Person(std::move(studentName)), rollNumber(roll)
    {
        cout << "Student constructor called" << endl;
    }

    // Function to display student details
    void display() const
    {
        cout << "Name: " << name << endl;
        cout << "Roll Number: " << rollNumber << endl;
    }
};

int main()
{
    // Create a Student object
    // The Person constructor executes first,
    // followed by the Student constructor
    Student student("Amit", 101);

    // Display student details
    student.display();

    return 0;
}