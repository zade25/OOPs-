#include <iostream>
using namespace std;

class Balance
{
private:
    double amount;

public:
    Balance(double value) : amount(value) {}

    Balance operator-() const
    {
        return Balance(-amount);
    }

    void display() const
    {
        cout << amount << endl;
    }
};

int main()
{
    Balance accountBalance(2500.50);
    Balance negativeBalance = -accountBalance;

    cout << "Unary Minus Operator Overloading" << endl;
    cout << "Student: Prachi Zade" << endl;
    cout << "--------------------------------" << endl;

    cout << "Original balance: ";
    accountBalance.display();

    cout << "Negative balance: ";
    negativeBalance.display();

    return 0;
}