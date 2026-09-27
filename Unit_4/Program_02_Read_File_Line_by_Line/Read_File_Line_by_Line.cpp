#include <fstream>
#include <iostream>
#include <string>
using namespace std;

int main()
{
    ifstream inputFile("notes.txt");

    if (!inputFile)
    {
        cerr << "Error: Could not open notes.txt" << endl;
        return 1;
    }

    string line;

    cout << "Contents of notes.txt:" << endl;
    cout << "-----------------------" << endl;

    while (getline(inputFile, line))
    {
        cout << line << endl;
    }

    inputFile.close();

    return 0;
}