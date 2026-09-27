#include <fstream>
#include <iostream>
#include <string>
using namespace std;

int main()
{
    ofstream outputFile("notes.txt");

    if (!outputFile)
    {
        cerr << "Error: Could not create notes.txt" << endl;
        return 1;
    }

    string line1, line2, line3;

    cout << "Enter first line: ";
    getline(cin, line1);

    cout << "Enter second line: ";
    getline(cin, line2);

    cout << "Enter third line: ";
    getline(cin, line3);

    outputFile << line1 << endl;
    outputFile << line2 << endl;
    outputFile << line3 << endl;

    outputFile.close();

    cout << "Three lines written successfully to notes.txt" << endl;

    return 0;
}