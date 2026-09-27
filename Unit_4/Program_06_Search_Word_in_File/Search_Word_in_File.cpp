#include <cctype>
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

string cleanWord(string word)
{
    string cleaned;

    for (char ch : word)
    {
        if (isalnum(static_cast<unsigned char>(ch)))
        {
            cleaned += tolower(static_cast<unsigned char>(ch));
        }
    }

    return cleaned;
}

int main()
{
    ifstream inputFile("message.txt");

    if (!inputFile)
    {
        cerr << "Error: Could not open message.txt" << endl;
        return 1;
    }

    string searchWord;

    cout << "Enter word to search: ";
    cin >> searchWord;

    searchWord = cleanWord(searchWord);

    string word;
    int count = 0;

    while (inputFile >> word)
    {
        word = cleanWord(word);

        if (word == searchWord)
        {
            count++;
        }
    }

    inputFile.close();

    cout << "The word '" << searchWord << "' occurred "
         << count << " time(s)." << endl;

    return 0;
}