#include <iostream>
using namespace std;

class Complex
{
private:
    int real;
    int imaginary;

public:
    // Constructor to initialize real and imaginary parts
    Complex(int r = 0, int i = 0)
    {
        real = r;
        imaginary = i;
    }

    // Overload + operator for addition of complex numbers
    Complex operator+(const Complex& other)
    {
        return Complex(real + other.real, imaginary + other.imaginary);
    }

    // Overload - operator for subtraction of complex numbers
    Complex operator-(const Complex& other)
    {
        return Complex(real - other.real, imaginary - other.imaginary);
    }

    // Function to display a complex number
    void display() const
    {
        cout << real;

        if (imaginary >= 0)
            cout << " + " << imaginary << "i" << endl;
        else
            cout << " - " << -imaginary << "i" << endl;
    }
};

int main()
{
    // Create two complex number objects
    Complex c1(4, 5);
    Complex c2(3, 2);

    // Add the two complex numbers
    Complex sum = c1 + c2;

    // Subtract the second complex number from the first
    Complex difference = c1 - c2;

    // Display program title and student name
    cout << "Complex Number Addition and Subtraction" << endl;
    cout << "Student: Prachi Zade" << endl;
    cout << "----------------------------------------" << endl;

    // Display the first complex number
    cout << "First complex number: ";
    c1.display();

    // Display the second complex number
    cout << "Second complex number: ";
    c2.display();

    // Display the sum
    cout << "Sum: ";
    sum.display();

    // Display the difference
    cout << "Difference: ";
    difference.display();

    return 0; // End of the program
}