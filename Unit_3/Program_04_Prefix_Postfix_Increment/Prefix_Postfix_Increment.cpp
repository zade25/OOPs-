#include <iostream>
using namespace std;

class Counter
{
private:
    int value;

public:
    // Constructor to initialize the counter value
    Counter(int v) : value(v) {}

    // Prefix increment operator
    Counter& operator++()
    {
        ++value;
        return *this;
    }

    // Postfix increment operator
    Counter operator++(int)
    {
        Counter temp = *this;
        value++;
        return temp;
    }

    // Prefix decrement operator
    Counter& operator--()
    {
        --value;
        return *this;
    }

    // Postfix decrement operator
    Counter operator--(int)
    {
        Counter temp = *this;
        value--;
        return temp;
    }

    // Function to display the current value
    void display() const
    {
        cout << value << endl;
    }
};

int main()
{
    // Create a Counter object with initial value 10
    Counter count(10);

    // Display program title and student name
    cout << "Prefix and Postfix Increment and Decrement Operator" << endl;
    cout << "Student: Prachi Zade" << endl;
    cout << "--------------------------------------------------" << endl;

    // Display the original value
    cout << "Original value: ";
    count.display();

    // Apply prefix increment
    ++count;
    cout << "After prefix increment: ";
    count.display();

    // Apply postfix increment
    count++;
    cout << "After postfix increment: ";
    count.display();

    // Apply prefix decrement
    --count;
    cout << "After prefix decrement: ";
    count.display();

    // Apply postfix decrement
    count--;
    cout << "After postfix decrement: ";
    count.display();

    return 0; // End of the program
}