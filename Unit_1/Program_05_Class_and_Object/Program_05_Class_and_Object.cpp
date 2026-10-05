#include <iostream>
#include <string>
using namespace std;

// Define a Student class
class Student
{
public:
    // Data members to store student details
    string name;
    int age;

    // Member function to display student details
    void show()
    {
        cout << name << " " << age << endl;
    }
};

int main()
{
    // Create an object of the Student class
    Student s1;

    // Assign values to the object's data members
    s1.name = "Amit";
    s1.age = 20;

    // Call the member function using the object
    s1.show();

    return 0;
}