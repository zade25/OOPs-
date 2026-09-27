#include <fstream>
#include <iostream>
#include <string>
using namespace std;

int main()
{
    ofstream outputFile("notes.txt", ios::app);

    if (!outputFile)
    {
        cerr << "Error: Could not open notes.txt" << endl;
        return 1;
    }

    string newLine;

    cout << "Enter a line to append: ";
    getline(cin, newLine);

    outputFile << newLine << endl;

    outputFile.close();

    cout << "New line appended successfully to notes.txt" << endl;

    return 0;
}