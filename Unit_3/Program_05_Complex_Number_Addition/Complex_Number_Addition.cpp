#include <iostream>
using namespace std;

class Complex
{
private:
    int real;
    int imaginary;

public:
    Complex(int r = 0, int i = 0)
    {
        real = r;
        imaginary = i;
    }

    Complex operator+(const Complex& other)
    {
        return Complex(real + other.real, imaginary + other.imaginary);
    }

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
    Complex c1(4, 5);
    Complex c2(3, 2);

    Complex result = c1 + c2;

    cout << "Complex Number Addition Using Operator Overloading" << endl;
    cout << "Student: Prachi Zade" << endl;
    cout << "--------------------------------------------------" << endl;

    cout << "First complex number: ";
    c1.display();

    cout << "Second complex number: ";
    c2.display();

    cout << "Sum: ";
    result.display();

    return 0;
}