#include <fstream>
#include <iostream>
#include <string>
using namespace std;

int main()
{
    // Open notes.txt in append mode
    // New data will be added at the end of the file
    ofstream outputFile("notes.txt", ios::app);

    // Check whether the file opened successfully
    if (!outputFile)
    {
        cerr << "Error: Could not open notes.txt" << endl;
        return 1;
    }

    // Variables to store the name and date entered by the user
    string name, date;

    // Ask the user to enter their name
    cout << "Enter your name: ";
    getline(cin, name);

    // Ask the user to enter the current date
    cout << "Enter current date: ";
    getline(cin, date);

    // Append the name and date to the file
    outputFile << "Name: " << name << " | Date: " << date << endl;

    // Close the file after appending
    outputFile.close();

    // Display a success message
    cout << "Name and date appended successfully to notes.txt" << endl;

    return 0;
}