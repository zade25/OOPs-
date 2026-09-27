#include <iostream>
using namespace std;

class Number
{
private:
    int value;

public:
    Number(int v = 0)
    {
        value = v;
    }

    int getValue() const
    {
        return value;
    }

    friend Number operator+(const Number& n1, const Number& n2);

    void display() const
    {
        cout << value << endl;
    }
};

// Non-member friend operator function
Number operator+(const Number& n1, const Number& n2)
{
    return Number(n1.value + n2.value);
}

int main()
{
    Number n1(25);
    Number n2(15);

    Number result = n1 + n2;

    cout << "Friend Function for Operator Overloading" << endl;
    cout << "Student: Prachi Zade" << endl;
    cout << "----------------------------------------" << endl;

    cout << "First number: ";
    n1.display();

    cout << "Second number: ";
    n2.display();

    cout << "Sum: ";
    result.display();

    return 0;
}