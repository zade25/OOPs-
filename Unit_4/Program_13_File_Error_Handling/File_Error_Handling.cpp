#include <fstream>
#include <iostream>
#include <string>
using namespace std;

int main()
{
    // Variable to store the file name entered by the user
    string fileName;

    // Create an input file stream object
    ifstream inputFile;

    // Display the program heading
    cout << "File Error Handling" << endl;
    cout << "-------------------" << endl;

    // Keep asking for a file name until a file is opened successfully
    while (true)
    {
        // Ask the user to enter the file name
        cout << "Enter file name: ";
        getline(cin, fileName);

        // Try to open the entered file
        inputFile.open(fileName);

        // Check whether the file opened successfully
        if (inputFile.is_open())
        {
            cout << "File opened successfully." << endl;
            break;
        }

        // Display an error message if the file could not be opened
        cout << "Error: File could not be opened." << endl;
        cout << "Please enter a valid file name." << endl;
    }

    // Variable to store each line read from the file
    string line;

    // Display the file contents heading
    cout << "\nFile Contents:" << endl;
    cout << "--------------" << endl;

    // Read and display the file line by line
    while (getline(inputFile, line))
    {
        cout << line << endl;
    }

    // Check whether the end of the file was reached normally
    if (inputFile.eof())
    {
        cout << "\nEnd of file reached normally." << endl;
    }
    // Check for a serious input/output error
    else if (inputFile.bad())
    {
        cout << "\nA serious file I/O error occurred." << endl;
    }
    // Check for another logical file reading error
    else if (inputFile.fail())
    {
        cout << "\nA logical file read error occurred." << endl;
    }

    // Close the file after reading
    inputFile.close();

    return 0;
}