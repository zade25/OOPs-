#include <iostream>
using namespace std;

class Payment
{
public:
    virtual void pay(double amount)
    {
        cout << "Processing payment of Rs. " << amount << endl;
    }

    virtual ~Payment() {}
};

class CreditCard : public Payment
{
public:
    void pay(double amount) override
    {
        cout << "Credit Card Payment: Rs. " << amount << endl;
    }
};

class UPI : public Payment
{
public:
    void pay(double amount) override
    {
        cout << "UPI Payment: Rs. " << amount << endl;
    }
};

int main()
{
    CreditCard card;
    UPI upi;

    Payment* payment1 = &card;
    Payment* payment2 = &upi;

    cout << "Payment System Using Polymorphism" << endl;
    cout << "Student: Prachi Zade" << endl;
    cout << "----------------------------------" << endl;

    payment1->pay(2500);
    payment2->pay(1200);

    return 0;
}