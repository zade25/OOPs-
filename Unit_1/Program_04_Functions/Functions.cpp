#include <iostream>
using namespace std;

// Function prototype
// This tells the compiler about the add() function
int add(int, int);

int main()
{
    // Store two numbers
    int a = 10;
    int b = 20;

    // Call the add() function and display the result
    cout << "Sum = " << add(a, b) << endl;

    return 0;
}

// Function definition
// This function returns the sum of two integers
int add(int x, int y)
{
    return x + y;
}