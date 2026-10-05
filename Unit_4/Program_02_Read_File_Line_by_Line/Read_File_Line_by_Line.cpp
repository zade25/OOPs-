#include <fstream>
#include <iostream>
#include <string>
using namespace std;

int main()
{
    // Open notes.txt file for reading
    ifstream inputFile("notes.txt");

    // Check whether the file opened successfully
    if (!inputFile)
    {
        cerr << "Error: Could not open notes.txt" << endl;
        return 1;
    }

    // Variable to store each line read from the file
    string line;

    // Variable to keep track of the line number
    int lineNumber = 1;

    // Display the program heading
    cout << "Contents of notes.txt:" << endl;
    cout << "-----------------------" << endl;

    // Read the file line by line until the end of the file
    while (getline(inputFile, line))
    {
        // Display the line number followed by the line content
        cout << lineNumber << ". " << line << endl;

        // Increase the line number for the next line
        lineNumber++;
    }

    // Close the file after reading
    inputFile.close();

    return 0;
}