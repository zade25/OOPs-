#include <iostream>
using namespace std;

// Class to demonstrate unary minus operator overloading
class Balance
{
private:
    double amount;

public:
    // Constructor to initialize the balance amount
    Balance(double value) : amount(value) {}

    // Overload unary minus operator
    // Returns a new Balance object with a negative amount
    Balance operator-() const
    {
        return Balance(-amount);
    }

    // Function to display the balance amount
    void display() const
    {
        cout << amount << endl;
    }
};

int main()
{
    // Create an object with the original account balance
    Balance accountBalance(2500.50);

    // Apply unary minus operator to get the negative balance
    Balance negativeBalance = -accountBalance;

    // Display program title and student name
    cout << "Unary Minus Operator Overloading" << endl;
    cout << "Student: Prachi Zade" << endl;
    cout << "--------------------------------" << endl;

    // Display the original balance
    cout << "Original balance: ";
    accountBalance.display();

    // Display the negative balance
    cout << "Negative balance: ";
    negativeBalance.display();

    return 0; // End of the program
}