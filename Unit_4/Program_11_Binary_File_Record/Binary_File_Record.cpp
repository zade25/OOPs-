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

    StudentRecord student;

    cout << "Binary File Student Records" << endl;
    cout << "---------------------------" << endl;

    while (inputFile.read(
        reinterpret_cast<char*>(&student),
        sizeof(StudentRecord)))
    {
        cout << "Roll Number: " << student.rollNumber << endl;
        cout << "Name: " << student.name << endl;
        cout << "Marks: " << student.marks << endl;
        cout << "---------------------------" << endl;
    }

    inputFile.close();

    cout << "Records written and read successfully." << endl;

    return 0;
}