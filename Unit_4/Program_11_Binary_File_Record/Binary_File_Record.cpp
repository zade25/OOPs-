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

    // Write each student record into the binary file
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

    // Variable to store one student record while reading
    StudentRecord student;

    // Display the program heading
    cout << "Binary File Student Records" << endl;
    cout << "---------------------------" << endl;

    // Read student records from the binary file
    while (inputFile.read(
        reinterpret_cast<char*>(&student),
        sizeof(StudentRecord)))
    {
        // Display the student record
        cout << "Roll Number: " << student.rollNumber << endl;
        cout << "Name: " << student.name << endl;
        cout << "Marks: " << student.marks << endl;
        cout << "---------------------------" << endl;
    }

    // Close the input file
    inputFile.close();

    // Display a success message
    cout << "Records written and read successfully." << endl;

    return 0;
}