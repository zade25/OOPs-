#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

// Function to add a new student record
void addStudent()
{
    // Open students.txt in append mode
    ofstream outputFile("students.txt", ios::app);

    // Check whether the file opened successfully
    if (!outputFile)
    {
        cout << "Error: Could not open students.txt" << endl;
        return;
    }

    // Variables to store student details
    int rollNumber;
    string name;
    double marks;

    // Ask the user to enter the roll number
    cout << "Enter roll number: ";
    cin >> rollNumber;

    // Clear the newline from the input buffer
    cin.ignore();

    // Ask the user to enter the student name
    cout << "Enter student name: ";
    getline(cin, name);

    // Ask the user to enter marks
    cout << "Enter marks: ";
    cin >> marks;

    // Store the student record using | as a separator
    outputFile << rollNumber << "|" << name << "|" << marks << endl;

    // Close the file
    outputFile.close();

    // Display a success message
    cout << "Student record added successfully." << endl;
}

// Function to display all student records
void displayStudents()
{
    // Open students.txt for reading
    ifstream inputFile("students.txt");

    // Check whether the file exists
    if (!inputFile)
    {
        cout << "No student records found." << endl;
        return;
    }

    // Variable to store each line from the file
    string line;

    // Display the heading
    cout << "\nStudent Records" << endl;
    cout << "----------------------------------------" << endl;

    // Read the file line by line
    while (getline(inputFile, line))
    {
        // Create a string stream to separate the fields
        stringstream record(line);

        // Variables to store individual fields
        string rollNumber;
        string name;
        string marks;

        // Extract roll number, name, and marks
        if (getline(record, rollNumber, '|') &&
            getline(record, name, '|') &&
            getline(record, marks))
        {
            // Display the student record
            cout << "Roll Number: " << rollNumber << endl;
            cout << "Name: " << name << endl;
            cout << "Marks: " << marks << endl;
            cout << "----------------------------------------" << endl;
        }
    }

    // Close the file
    inputFile.close();
}

// Function to search for a student using roll number
void searchStudent()
{
    // Open students.txt for reading
    ifstream inputFile("students.txt");

    // Check whether the file exists
    if (!inputFile)
    {
        cout << "No student records found." << endl;
        return;
    }

    // Variable to store the roll number to search
    int searchRoll;

    // Ask the user for the roll number
    cout << "Enter roll number to search: ";
    cin >> searchRoll;

    // Variable to store each line from the file
    string line;

    // Variable to check whether the student was found
    bool found = false;

    // Read the file line by line
    while (getline(inputFile, line))
    {
        // Create a string stream for the current record
        stringstream record(line);

        // Variables to store individual fields
        string rollText;
        string name;
        string marks;

        // Extract the student details
        if (getline(record, rollText, '|') &&
            getline(record, name, '|') &&
            getline(record, marks))
        {
            // Convert roll number from string to integer
            int rollNumber = stoi(rollText);

            // Check whether the roll number matches
            if (rollNumber == searchRoll)
            {
                // Display the matching record
                cout << "\nRecord Found" << endl;
                cout << "Roll Number: " << rollNumber << endl;
                cout << "Name: " << name << endl;
                cout << "Marks: " << marks << endl;

                // Mark the record as found
                found = true;

                // Stop searching
                break;
            }
        }
    }

    // Display a message if the record was not found
    if (!found)
    {
        cout << "Student record not found." << endl;
    }

    // Close the file
    inputFile.close();
}

// Function to update the marks of a student
void updateMarks()
{
    // Open the original file for reading
    ifstream inputFile("students.txt");

    // Create a temporary file for storing updated records
    ofstream temporaryFile("students_temp.txt");

    // Check whether both files opened successfully
    if (!inputFile || !temporaryFile)
    {
        cout << "Error: Could not open file." << endl;
        return;
    }

    // Variables to store the roll number and new marks
    int searchRoll;
    double newMarks;

    // Ask the user for the roll number to update
    cout << "Enter roll number to update: ";
    cin >> searchRoll;

    // Ask the user for the new marks
    cout << "Enter new marks: ";
    cin >> newMarks;

    // Variable to store each line from the file
    string line;

    // Variable to check whether the student was found
    bool found = false;

    // Read the original file line by line
    while (getline(inputFile, line))
    {
        // Create a string stream for the current record
        stringstream record(line);

        // Variables to store individual fields
        string rollText;
        string name;
        string marks;

        // Extract the student details
        if (getline(record, rollText, '|') &&
            getline(record, name, '|') &&
            getline(record, marks))
        {
            // Convert the roll number from string to integer
            int rollNumber = stoi(rollText);

            // Check whether the roll number matches
            if (rollNumber == searchRoll)
            {
                // Write the updated record to the temporary file
                temporaryFile << rollNumber << "|"
                              << name << "|"
                              << newMarks << endl;

                found = true;
            }
            else
            {
                // Copy unchanged records to the temporary file
                temporaryFile << line << endl;
            }
        }
    }

    // Close both files
    inputFile.close();
    temporaryFile.close();

    // Replace the original file with the updated temporary file
    if (found)
    {
        // Delete the original file
        remove("students.txt");

        // Rename the temporary file
        rename("students_temp.txt", "students.txt");

        cout << "Marks updated successfully." << endl;
    }
    else
    {
        // Delete the temporary file if no record was found
        remove("students_temp.txt");

        cout << "Student record not found." << endl;
    }
}

int main()
{
    // Variable to store the user's menu choice
    int choice;

    // Display the program heading
    cout << "Student Record Manager" << endl;
    cout << "======================" << endl;

    // Display the menu repeatedly until the user chooses Exit
    do
    {
        cout << "\n1. Add Student" << endl;
        cout << "2. Display Students" << endl;
        cout << "3. Search Student" << endl;
        cout << "4. Update Marks" << endl;
        cout << "5. Exit" << endl;

        // Ask the user to select an option
        cout << "Enter your choice: ";
        cin >> choice;

        // Perform the selected operation
        switch (choice)
        {
            case 1:
                addStudent();
                break;

            case 2:
                displayStudents();
                break;

            case 3:
                searchStudent();
                break;

            case 4:
                updateMarks();
                break;

            case 5:
                cout << "Exiting Student Record Manager." << endl;
                break;

            default:
                cout << "Invalid choice. Please try again." << endl;
        }

    } while (choice != 5);

    return 0;
}