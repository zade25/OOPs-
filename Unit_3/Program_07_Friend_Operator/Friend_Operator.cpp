#include <iostream>
using namespace std;

class Number
{
private:
    int value;

public:
    // Constructor to initialize the number
    Number(int v = 0)
    {
        value = v;
    }

    // Function to return the stored value
    int getValue() const
    {
        return value;
    }

    // Declare the subtraction operator as a friend function
    friend Number operator-(int n, const Number& obj);

    // Function to display the value
    void display() const
    {
        cout << value << endl;
    }
};

// Non-member friend operator function
// Supports subtraction in the form: 10 - object
Number operator-(int n, const Number& obj)
{
    return Number(n - obj.value);
}

int main()
{
    // Create a Number object
    Number n1(25);

    // Use the friend operator with an integer on the left side
    Number result = 10 - n1;

    // Display program title and student name
    cout << "Friend Function for Operator Overloading" << endl;
    cout << "Student: Prachi Zade" << endl;
    cout << "----------------------------------------" << endl;

    // Display the original number
    cout << "Number object: ";
    n1.display();

    // Display the result of 10 - object
    cout << "Result of 10 - object: ";
    result.display();

    return 0; // End of the program
}