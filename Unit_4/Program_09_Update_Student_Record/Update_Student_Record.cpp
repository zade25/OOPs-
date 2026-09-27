#include <cstdio>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

int main()
{
    ifstream inputFile("students.txt");
    ofstream temporaryFile("students_temp.txt");

    if (!inputFile || !temporaryFile)
    {
        cerr << "Error: Could not open file(s)." << endl;
        return 1;
    }

    int targetRollNumber;
    string updatedName;
    double updatedMarks;

    cout << "Enter roll number to update: ";
    cin >> targetRollNumber;

    cin.ignore();

    cout << "Enter updated name: ";
    getline(cin, updatedName);

    cout << "Enter updated marks: ";
    cin >> updatedMarks;

    string line;
    bool found = false;

    while (getline(inputFile, line))
    {
        stringstream record(line);

        string rollText;
        string name;
        string marksText;
        string courseName;
        string mobileNumber;

        if (getline(record, rollText, '|') &&
            getline(record, name, '|') &&
            getline(record, marksText, '|') &&
            getline(record, courseName, '|') &&
            getline(record, mobileNumber))
        {
            int rollNumber = stoi(rollText);

            if (rollNumber == targetRollNumber)
            {
                temporaryFile << rollNumber << '|'
                              << updatedName << '|'
                              << updatedMarks << '|'
                              << courseName << '|'
                              << mobileNumber << '\n';

                found = true;
            }
            else
            {
                temporaryFile << line << '\n';
            }
        }
    }

    inputFile.close();
    temporaryFile.close();

    if (!found)
    {
        remove("students_temp.txt");
        cout << "Student record not found. No update performed." << endl;
        return 0;
    }

    if (remove("students.txt") != 0)
    {
        cerr << "Error: Could not remove old students.txt" << endl;
        return 1;
    }

    if (rename("students_temp.txt", "students.txt") != 0)
    {
        cerr << "Error: Could not rename temporary file." << endl;
        return 1;
    }

    cout << "Student name and marks updated successfully." << endl;

    return 0;
}