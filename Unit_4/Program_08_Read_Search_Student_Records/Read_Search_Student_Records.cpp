#include <fstream>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
using namespace std;

int main()
{
    // Open students.txt for reading
    ifstream inputFile("students.txt");

    // Check whether the file opened successfully
    if (!inputFile)
    {
        cerr << "Error: Could not open students.txt" << endl;
        return 1;
    }

    // Variable to store each line from the file
    string line;

    // Display the table heading
    cout << "Student Records" << endl;
    cout << "--------------------------------------------------------------------------" << endl;

    // Display the column headings with proper spacing
    cout << left << setw(12) << "Roll No."
         << setw(22) << "Name"
         << setw(12) << "Marks"
         << setw(30) << "Course"
         << setw(15) << "Mobile" << endl;

    cout << "--------------------------------------------------------------------------" << endl;

    // Read student records line by line
    while (getline(inputFile, line))
    {
        // Create a string stream to separate the fields
        stringstream record(line);

        // Variables to store individual student details
        string rollText;
        string name;
        string marksText;
        string courseName;
        string mobileNumber;

        // Extract each field separated by '|'
        if (getline(record, rollText, '|') &&
            getline(record, name, '|') &&
            getline(record, marksText, '|') &&
            getline(record, courseName, '|') &&
            getline(record, mobileNumber))
        {
            // Display the student record in a formatted table
            cout << left << setw(12) << rollText
                 << setw(22) << name
                 << setw(12) << marksText
                 << setw(30) << courseName
                 << setw(15) << mobileNumber << endl;
        }
    }

    // Close the file after reading
    inputFile.close();

    return 0;
}