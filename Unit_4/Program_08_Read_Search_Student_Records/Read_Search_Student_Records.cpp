#include <fstream>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
using namespace std;

int main()
{
    ifstream inputFile("students.txt");

    if (!inputFile)
    {
        cerr << "Error: Could not open students.txt" << endl;
        return 1;
    }

    string line;

    cout << "Student Records" << endl;
    cout << "--------------------------------------------------------------------------" << endl;
    cout << left << setw(12) << "Roll No."
         << setw(22) << "Name"
         << setw(12) << "Marks"
         << setw(30) << "Course"
         << setw(15) << "Mobile" << endl;
    cout << "--------------------------------------------------------------------------" << endl;

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
            cout << left << setw(12) << rollText
                 << setw(22) << name
                 << setw(12) << marksText
                 << setw(30) << courseName
                 << setw(15) << mobileNumber << endl;
        }
    }

    inputFile.close();

    return 0;
}