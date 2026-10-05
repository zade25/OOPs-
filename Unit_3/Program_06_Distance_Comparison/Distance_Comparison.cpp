#include <iostream>
using namespace std;

class Distance
{
private:
    int feet;
    int inches;

public:
    // Constructor to initialize feet and inches
    Distance(int f = 0, int i = 0)
    {
        feet = f;
        inches = i;
        normalize();
    }

    // Function to convert extra inches into feet
    void normalize()
    {
        if (inches >= 12)
        {
            feet += inches / 12;
            inches = inches % 12;
        }
    }

    // Overload > operator to compare which distance is greater
    bool operator>(const Distance& other) const
    {
        int totalInches = feet * 12 + inches;
        int otherTotalInches = other.feet * 12 + other.inches;

        return totalInches > otherTotalInches;
    }

    // Overload == operator to check whether two distances are equal
    bool operator==(const Distance& other) const
    {
        int totalInches = feet * 12 + inches;
        int otherTotalInches = other.feet * 12 + other.inches;

        return totalInches == otherTotalInches;
    }

    // Function to display the distance
    void display() const
    {
        cout << feet << " feet " << inches << " inches" << endl;
    }
};

int main()
{
    // Create two Distance objects
    Distance d1(5, 8);
    Distance d2(6, 2);

    // Display program title and student name
    cout << "Distance Comparison Using Operator Overloading" << endl;
    cout << "Student: Prachi Zade" << endl;
    cout << "----------------------------------------------" << endl;

    // Display the first distance
    cout << "First distance: ";
    d1.display();

    // Display the second distance
    cout << "Second distance: ";
    d2.display();

    // Compare the two distances using > operator
    if (d1 > d2)
        cout << "First distance is greater." << endl;
    else
        cout << "Second distance is greater." << endl;

    // Compare the two distances using == operator
    if (d1 == d2)
        cout << "Both distances are equal." << endl;
    else
        cout << "Both distances are not equal." << endl;

    return 0; // End of the program
}