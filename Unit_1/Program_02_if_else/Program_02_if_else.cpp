#include <iostream>
using namespace std;

int main()
{
    // Store the student's marks
    int marks = 45;

    // Check whether the student has scored 40 or more marks
    if (marks >= 40)
    {
        // Display Pass if the condition is true
        cout << "Pass";
    }
    else
    {
        // Display Fail if the condition is false
        cout << "Fail";
    }

    return 0;
}