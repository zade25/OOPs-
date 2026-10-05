#include <fstream>
#include <iostream>
#include <limits>
#include <string>
using namespace std;

int main()
{
    // Open students.txt in append mode
    // New student records will be added at the end of the file
    ofstream outputFile("students.txt", ios::app);

    // Check whether the file opened successfully
    if (!outputFile)
    {
        cerr << "Error: Could not open students.txt" << endl;
        return 1;
    }

    // Variables to store student details
    int rollNumber;
    string name;
    double marks;
    string courseName;
    string mobileNumber;

    // Ask the user to enter the roll number
    cout << "Enter roll number: ";
    cin >> rollNumber;

    // Clear the newline left in the input buffer
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    // Ask the user to enter the student name
    cout << "Enter name: ";
    getline(cin, name);

    // Ask the user to enter marks
    cout << "Enter marks: ";
    cin >> marks;

    // Clear the newline left in the input buffer
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    // Ask the user to enter the course name
    cout << "Enter course name: ";
    getline(cin, courseName);

    // Ask the user to enter the mobile number
    cout << "Enter mobile number: ";
    getline(cin, mobileNumber);

    // Store the student record in the file
    // The | symbol separates different fields
    outputFile << rollNumber << '|'
               << name << '|'
               << marks << '|'
               << courseName << '|'
               << mobileNumber << '\n';

    // Close the file after saving the record
    outputFile.close();

    // Display a success message
    cout << "Student record saved successfully." << endl;

    return 0;
}