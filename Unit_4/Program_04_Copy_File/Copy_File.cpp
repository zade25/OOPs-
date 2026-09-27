#include <fstream>
#include <iostream>
#include <string>
using namespace std;

int main()
{
    ifstream inputFile("source.txt");
    ofstream outputFile("cpp_lines.txt");

    if (!inputFile)
    {
        cerr << "Error: Could not open source.txt" << endl;
        return 1;
    }

    if (!outputFile)
    {
        cerr << "Error: Could not create cpp_lines.txt" << endl;
        return 1;
    }

    string line;
    int copiedLines = 0;

    while (getline(inputFile, line))
    {
        if (line.find("C++") != string::npos)
        {
            outputFile << line << endl;
            copiedLines++;
        }
    }

    inputFile.close();
    outputFile.close();

    cout << "Lines containing C++ copied successfully." << endl;
    cout << "Number of lines copied: " << copiedLines << endl;

    return 0;
}