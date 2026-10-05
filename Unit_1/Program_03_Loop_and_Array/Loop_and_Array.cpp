#include <iostream>
using namespace std;

int main()
{
    // Create an array to store marks of five students
    int marks[5] = {78, 82, 91, 67, 88};

    // Use a for loop to access and display each array element
    for (int i = 0; i < 5; i++)
    {
        // Display the marks of the current student
        cout << marks[i] << " ";
    }

    return 0;
}