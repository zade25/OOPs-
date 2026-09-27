#include <fstream>
#include <iostream>
using namespace std;

struct StudentRecord
{
    int rollNumber;
    char name[30];
    float marks;
};

int main()
{
    StudentRecord students[3] =
    {
        {101, "Prachi", 88.5f},
        {102, "Neha", 91.0f},
        {103, "Rahul", 84.5f}
    };

    ofstream outputFile("students.dat", ios::binary);

    if (!outputFile)
    {
        cerr << "Error: Could not create students.dat" << endl;
        return 1;
    }

    for (int i = 0; i < 3; i++)
    {
        outputFile.write(
            reinterpret_cast<char*>(&students[i]),
            sizeof(StudentRecord)
        );
    }

    outputFile.close();

    ifstream inputFile("students.dat", ios::binary);

    if (!inputFile)
    {
        cerr << "Error: Could not open students.dat" << endl;
        return 1;
    }

    int searchRollNumber;

    cout << "Enter roll number to search: ";
    cin >> searchRollNumber;

    StudentRecord student;
    bool found = false;

    while (inputFile.read(
        reinterpret_cast<char*>(&student),
        sizeof(StudentRecord)))
    {
        if (student.rollNumber == searchRollNumber)
        {
            cout << "\nRecord Found" << endl;
            cout << "---------------------------" << endl;
            cout << "Roll Number: " << student.rollNumber << endl;
            cout << "Name: " << student.name << endl;
            cout << "Marks: " << student.marks << endl;

            found = true;
            break;
        }
    }

    if (!found)
    {
        cout << "\nRecord not found." << endl;
    }

    inputFile.close();

    return 0;
}