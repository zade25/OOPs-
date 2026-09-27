#include <fstream>
#include <iostream>
#include <limits>
#include <string>
using namespace std;

int main()
{
    ofstream outputFile("students.txt", ios::app);

    if (!outputFile)
    {
        cerr << "Error: Could not open students.txt" << endl;
        return 1;
    }

    int rollNumber;
    string name;
    double marks;
    string courseName;
    string mobileNumber;

    cout << "Enter roll number: ";
    cin >> rollNumber;

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "Enter name: ";
    getline(cin, name);

    cout << "Enter marks: ";
    cin >> marks;

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "Enter course name: ";
    getline(cin, courseName);

    cout << "Enter mobile number: ";
    getline(cin, mobileNumber);

    outputFile << rollNumber << '|'
               << name << '|'
               << marks << '|'
               << courseName << '|'
               << mobileNumber << '\n';

    outputFile.close();

    cout << "Student record saved successfully." << endl;

    return 0;
}