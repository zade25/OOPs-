#include <iostream>
using namespace std;

class Counter
{
private:
    int value;

public:
    Counter(int v) : value(v) {}

    // Prefix increment
    Counter& operator++()
    {
        ++value;
        return *this;
    }

    // Postfix increment
    Counter operator++(int)
    {
        Counter temp = *this;
        value++;
        return temp;
    }

    void display() const
    {
        cout << value << endl;
    }
};

int main()
{
    Counter count(10);

    cout << "Prefix and Postfix Increment Operator" << endl;
    cout << "Student: Prachi Zade" << endl;
    cout << "------------------------------------" << endl;

    cout << "Original value: ";
    count.display();

    ++count;
    cout << "After prefix increment: ";
    count.display();

    count++;
    cout << "After postfix increment: ";
    count.display();

    return 0;
}