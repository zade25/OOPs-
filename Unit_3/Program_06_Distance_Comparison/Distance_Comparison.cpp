#include <iostream>
using namespace std;

class Distance
{
private:
    int feet;
    int inches;

public:
    Distance(int f = 0, int i = 0)
    {
        feet = f;
        inches = i;
        normalize();
    }

    void normalize()
    {
        if (inches >= 12)
        {
            feet += inches / 12;
            inches = inches % 12;
        }
    }

    bool operator>(const Distance& other) const
    {
        int totalInches = feet * 12 + inches;
        int otherTotalInches = other.feet * 12 + other.inches;

        return totalInches > otherTotalInches;
    }

    void display() const
    {
        cout << feet << " feet " << inches << " inches" << endl;
    }
};

int main()
{
    Distance d1(5, 8);
    Distance d2(6, 2);

    cout << "Distance Comparison Using Operator Overloading" << endl;
    cout << "Student: Prachi Zade" << endl;
    cout << "----------------------------------------------" << endl;

    cout << "First distance: ";
    d1.display();

    cout << "Second distance: ";
    d2.display();

    if (d1 > d2)
        cout << "First distance is greater." << endl;
    else
        cout << "Second distance is greater." << endl;

    return 0;
}