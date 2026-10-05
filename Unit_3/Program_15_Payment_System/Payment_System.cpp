#include <iostream>
using namespace std;

// Abstract base class for different payment methods
class Payment
{
public:
    // Virtual function for processing payment
    virtual void pay(double amount) const
    {
        cout << "Processing payment of Rs. " << amount << endl;
    }

    // Virtual destructor
    virtual ~Payment() {}
};

// Derived class for Credit Card payment
class CreditCard : public Payment
{
public:
    // Override the pay() function
    void pay(double amount) const override
    {
        cout << "Credit Card Payment: Rs. " << amount << endl;
    }
};

// Derived class for UPI payment
class UPI : public Payment
{
public:
    // Override the pay() function
    void pay(double amount) const override
    {
        cout << "UPI Payment: Rs. " << amount << endl;
    }
};

// Derived class for Wallet payment
class WalletPayment : public Payment
{
public:
    // Override the pay() function
    void pay(double amount) const override
    {
        cout << "Wallet Payment: Rs. " << amount << endl;
    }
};

// Function that processes payment using a base class reference
// Runtime polymorphism calls the correct pay() function
void processPayment(const Payment& payment, double amount)
{
    payment.pay(amount);
}

int main()
{
    // Create objects for different payment methods
    CreditCard card;
    UPI upi;
    WalletPayment wallet;

    // Display program title and student name
    cout << "Payment System Using Polymorphism" << endl;
    cout << "Student: Prachi Zade" << endl;
    cout << "----------------------------------" << endl;

    // Process Credit Card payment
    processPayment(card, 2500);

    // Process UPI payment
    processPayment(upi, 1200);

    // Process Wallet payment
    processPayment(wallet, 800);

    return 0;
}