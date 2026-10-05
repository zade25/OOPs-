#include <fstream>
#include <iostream>
using namespace std;

// Structure to store student record details
struct StudentRecord
{
    int rollNumber;
    char name[30];
    float marks;
};

int main()
{
    // Create an array containing three student records
    StudentRecord students[3] =
    {
        {101, "Prachi", 88.5f},
        {102, "Neha", 91.0f},
        {103, "Rahul", 84.5f}
    };

    // Open students.dat in binary writing mode
    ofstream outputFile("students.dat", ios::binary);

    // Check whether the binary file was created successfully
    if (!outputFile)
    {
        cerr << "Error: Could not create students.dat" << endl;
        return 1;
    }

    // Write all student records to the binary file
    for (int i = 0; i < 3; i++)
    {
        outputFile.write(
            reinterpret_cast<char*>(&students[i]),
            sizeof(StudentRecord)
        );
    }

    // Close the output file
    outputFile.close();

    // Open students.dat in binary reading mode
    ifstream inputFile("students.dat", ios::binary);

    // Check whether the binary file opened successfully
    if (!inputFile)
    {
        cerr << "Error: Could not open students.dat" << endl;
        return 1;
    }

    // Variable to store the roll number entered by the user
    int searchRollNumber;

    // Ask the user for the roll number to search
    cout << "Enter roll number to search: ";
    cin >> searchRollNumber;

    // Variable to store a student record while reading
    StudentRecord student;

    // Variable to check whether the record was found
    bool found = false;

    // Read student records one by one from the binary file
    while (inputFile.read(
        reinterpret_cast<char*>(&student),
        sizeof(StudentRecord)))
    {
        // Check whether the current roll number matches
        // the roll number entered by the user
        if (student.rollNumber == searchRollNumber)
        {
            // Display the matching student record
            cout << "\nRecord Found" << endl;
            cout << "---------------------------" << endl;
            cout << "Roll Number: " << student.rollNumber << endl;
            cout << "Name: " << student.name << endl;
            cout << "Marks: " << student.marks << endl;

            // Mark the record as found
            found = true;

            // Stop searching after finding the record
            break;
        }
    }

    // Display a message if no matching record was found
    if (!found)
    {
        cout << "\nRecord not found." << endl;
    }

    // Close the input file
    inputFile.close();

    return 0;
}
