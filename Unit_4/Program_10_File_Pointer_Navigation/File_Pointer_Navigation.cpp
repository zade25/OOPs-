#include <fstream>
#include <iostream>
using namespace std;

int main()
{
    fstream file("navigation.txt",
                 ios::in | ios::out | ios::trunc);

    if (!file)
    {
        cerr << "Error: Could not open navigation.txt" << endl;
        return 1;
    }

    file << "ABCDE";

    cout << "Output position after writing: "
         << file.tellp() << endl;

    file.flush();

    file.seekg(0, ios::beg);

    char firstCharacter;
    file.get(firstCharacter);

    cout << "First character: "
         << firstCharacter << endl;

    cout << "Input position after reading one character: "
         << file.tellg() << endl;

    file.seekg(2, ios::beg);

    char thirdCharacter;
    file.get(thirdCharacter);

    cout << "Character at position 2: "
         << thirdCharacter << endl;

    // Modification: read the last character using seekg()
    file.seekg(-1, ios::end);

    char lastCharacter;
    file.get(lastCharacter);

    cout << "Last character using seekg(): "
         << lastCharacter << endl;

    file.seekp(5, ios::beg);
    file << "F";

    file.close();

    cout << "Navigation completed. Check navigation.txt"
         << endl;

    return 0;
}