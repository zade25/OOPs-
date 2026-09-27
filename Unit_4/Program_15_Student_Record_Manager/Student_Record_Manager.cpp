#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

void addStudent()
{
    ofstream outputFile("students.txt", ios::app);

    if (!outputFile)
    {
        cout << "Error: Could not open students.txt" << endl;
        return;
    }

    int rollNumber;
    string name;
    double marks;

    cout << "Enter roll number: ";
    cin >> rollNumber;

    cin.ignore();

    cout << "Enter student name: ";
    getline(cin, name);

    cout << "Enter marks: ";
    cin >> marks;

    outputFile << rollNumber << "|" << name << "|" << marks << endl;

    outputFile.close();

    cout << "Student record added successfully." << endl;
}

void displayStudents()
{
    ifstream inputFile("students.txt");

    if (!inputFile)
    {
        cout << "No student records found." << endl;
        return;
    }

    string line;

    cout << "\nStudent Records" << endl;
    cout << "----------------------------------------" << endl;

    while (getline(inputFile, line))
    {
        stringstream record(line);

        string rollNumber;
        string name;
        string marks;

        if (getline(record, rollNumber, '|') &&
            getline(record, name, '|') &&
            getline(record, marks))
        {
            cout << "Roll Number: " << rollNumber << endl;
            cout << "Name: " << name << endl;
            cout << "Marks: " << marks << endl;
            cout << "----------------------------------------" << endl;
        }
    }

    inputFile.close();
}

void searchStudent()
{
    ifstream inputFile("students.txt");

    if (!inputFile)
    {
        cout << "No student records found." << endl;
        return;
    }

    int searchRoll;
    cout << "Enter roll number to search: ";
    cin >> searchRoll;

    string line;
    bool found = false;

    while (getline(inputFile, line))
    {
        stringstream record(line);

        string rollText;
        string name;
        string marks;

        if (getline(record, rollText, '|') &&
            getline(record, name, '|') &&
            getline(record, marks))
        {
            int rollNumber = stoi(rollText);

            if (rollNumber == searchRoll)
            {
                cout << "\nRecord Found" << endl;
                cout << "Roll Number: " << rollNumber << endl;
                cout << "Name: " << name << endl;
                cout << "Marks: " << marks << endl;

                found = true;
                break;
            }
        }
    }

    if (!found)
    {
        cout << "Student record not found." << endl;
    }

    inputFile.close();
}

void updateMarks()
{
    ifstream inputFile("students.txt");
    ofstream temporaryFile("students_temp.txt");

    if (!inputFile || !temporaryFile)
    {
        cout << "Error: Could not open file." << endl;
        return;
    }

    int searchRoll;
    double newMarks;

    cout << "Enter roll number to update: ";
    cin >> searchRoll;

    cout << "Enter new marks: ";
    cin >> newMarks;

    string line;
    bool found = false;

    while (getline(inputFile, line))
    {
        stringstream record(line);

        string rollText;
        string name;
        string marks;

        if (getline(record, rollText, '|') &&
            getline(record, name, '|') &&
            getline(record, marks))
        {
            int rollNumber = stoi(rollText);

            if (rollNumber == searchRoll)
            {
                temporaryFile << rollNumber << "|"
                              << name << "|"
                              << newMarks << endl;

                found = true;
            }
            else
            {
                temporaryFile << line << endl;
            }
        }
    }

    inputFile.close();
    temporaryFile.close();

    if (found)
    {
        remove("students.txt");
        rename("students_temp.txt", "students.txt");

        cout << "Marks updated successfully." << endl;
    }
    else
    {
        remove("students_temp.txt");
        cout << "Student record not found." << endl;
    }
}

int main()
{
    int choice;

    cout << "Student Record Manager" << endl;
    cout << "======================" << endl;

    do
    {
        cout << "\n1. Add Student" << endl;
        cout << "2. Display Students" << endl;
        cout << "3. Search Student" << endl;
        cout << "4. Update Marks" << endl;
        cout << "5. Exit" << endl;

        cout << "Enter your choice: ";
        cin >> choice;

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