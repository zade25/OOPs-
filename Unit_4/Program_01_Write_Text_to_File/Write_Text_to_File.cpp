#include <fstream>
#include <iostream>
#include <string>
using namespace std;

int main()
{
    // Open notes.txt file for writing
    ofstream outputFile("notes.txt");

    // Check whether the file was created successfully
    if (!outputFile)
    {
        cerr << "Error: Could not create notes.txt" << endl;
        return 1;
    }

    // Variables to store three lines entered by the user
    string line1, line2, line3;

    // Ask the user to enter the first line
    cout << "Enter first line: ";
    getline(cin, line1);

    // Ask the user to enter the second line
    cout << "Enter second line: ";
    getline(cin, line2);

    // Ask the user to enter the third line
    cout << "Enter third line: ";
    getline(cin, line3);

    // Write the first line to the file
    outputFile << line1 << endl;

    // Write the second line to the file
    outputFile << line2 << endl;

    // Write the third line to the file
    outputFile << line3 << endl;

    // Close the file after writing
    outputFile.close();

    // Display a success message
    cout << "Three lines written successfully to notes.txt" << endl;

    return 0;
}