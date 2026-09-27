#include <fstream>
#include <iostream>
#include <string>
using namespace std;

int main()
{
    string fileName;
    ifstream inputFile;

    cout << "File Error Handling" << endl;
    cout << "-------------------" << endl;

    while (true)
    {
        cout << "Enter file name: ";
        getline(cin, fileName);

        inputFile.open(fileName);

        if (inputFile.is_open())
        {
            cout << "File opened successfully." << endl;
            break;
        }

        cout << "Error: File could not be opened." << endl;
        cout << "Please enter a valid file name." << endl;
    }

    string line;

    cout << "\nFile Contents:" << endl;
    cout << "--------------" << endl;

    while (getline(inputFile, line))
    {
        cout << line << endl;
    }

    if (inputFile.eof())
    {
        cout << "\nEnd of file reached normally." << endl;
    }
    else if (inputFile.bad())
    {
        cout << "\nA serious file I/O error occurred." << endl;
    }
    else if (inputFile.fail())
    {
        cout << "\nA logical file read error occurred." << endl;
    }

    inputFile.close();

    return 0;
}