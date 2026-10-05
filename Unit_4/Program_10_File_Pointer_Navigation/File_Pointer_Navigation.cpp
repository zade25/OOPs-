#include <fstream>
#include <iostream>
using namespace std;

int main()
{
    // Open navigation.txt for both reading and writing
    // ios::trunc clears the file before writing
    fstream file("navigation.txt",
                 ios::in | ios::out | ios::trunc);

    // Check whether the file opened successfully
    if (!file)
    {
        cerr << "Error: Could not open navigation.txt" << endl;
        return 1;
    }

    // Write the characters ABCDE into the file
    file << "ABCDE";

    // Display the current output position
    cout << "Output position after writing: "
         << file.tellp() << endl;

    // Make sure all written data is stored in the file
    file.flush();

    // Move the input pointer to the beginning of the file
    file.seekg(0, ios::beg);

    // Variable to store the first character
    char firstCharacter;

    // Read the first character
    file.get(firstCharacter);

    // Display the first character
    cout << "First character: "
         << firstCharacter << endl;

    // Display the current input position
    cout << "Input position after reading one character: "
         << file.tellg() << endl;

    // Move the input pointer to position 2
    file.seekg(2, ios::beg);

    // Variable to store the character at position 2
    char thirdCharacter;

    // Read the character at position 2
    file.get(thirdCharacter);

    // Display the character at position 2
    cout << "Character at position 2: "
         << thirdCharacter << endl;

    // Move the input pointer one character before the end
    // This reads the last character of the file
    file.seekg(-1, ios::end);

    // Variable to store the last character
    char lastCharacter;

    // Read the last character
    file.get(lastCharacter);

    // Display the last character
    cout << "Last character using seekg(): "
         << lastCharacter << endl;

    // Move the output pointer to position 5
    file.seekp(5, ios::beg);

    // Write F at position 5
    file << "F";

    // Close the file
    file.close();

    // Display a completion message
    cout << "Navigation completed. Check navigation.txt"
         << endl;

    return 0;
}