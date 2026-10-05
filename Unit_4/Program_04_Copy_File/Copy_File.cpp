#include <fstream>
#include <iostream>
#include <string>
using namespace std;

int main()
{
    // Open source.txt for reading
    ifstream inputFile("source.txt");

    // Open cpp_lines.txt for writing
    ofstream outputFile("cpp_lines.txt");

    // Check whether source.txt opened successfully
    if (!inputFile)
    {
        cerr << "Error: Could not open source.txt" << endl;
        return 1;
    }

    // Check whether cpp_lines.txt was created successfully
    if (!outputFile)
    {
        cerr << "Error: Could not create cpp_lines.txt" << endl;
        return 1;
    }

    // Variable to store each line read from the source file
    string line;

    // Variable to count the number of copied lines
    int copiedLines = 0;

    // Read the source file line by line
    while (getline(inputFile, line))
    {
        // Check whether the line contains the word "C++"
        if (line.find("C++") != string::npos)
        {
            // Copy the matching line to cpp_lines.txt
            outputFile << line << endl;

            // Increase the copied line count
            copiedLines++;
        }
    }

    // Close both files after completing the operation
    inputFile.close();
    outputFile.close();

    // Display the result
    cout << "Lines containing C++ copied successfully." << endl;
    cout << "Number of lines copied: " << copiedLines << endl;

    return 0;
}