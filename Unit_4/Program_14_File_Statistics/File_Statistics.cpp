#include <cctype>
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

bool isVowel(char ch)
{
    ch = static_cast<char>(tolower(static_cast<unsigned char>(ch)));

    return ch == 'a' || ch == 'e' || ch == 'i' ||
           ch == 'o' || ch == 'u';
}

int main()
{
    string fileName;

    cout << "Enter file name: ";
    getline(cin, fileName);

    ifstream inputFile(fileName);

    if (!inputFile)
    {
        cerr << "Error: Could not open " << fileName << endl;
        return 1;
    }

    int lines = 0;
    int words = 0;
    int characters = 0;
    int vowels = 0;
    int digits = 0;
    int spaces = 0;

    bool insideWord = false;
    char ch;

    while (inputFile.get(ch))
    {
        characters++;

        if (ch == '\n')
        {
            lines++;
        }

        if (isspace(static_cast<unsigned char>(ch)))
        {
            if (ch == ' ')
            {
                spaces++;
            }

            insideWord = false;
        }
        else if (!insideWord)
        {
            words++;
            insideWord = true;
        }

        if (isalpha(static_cast<unsigned char>(ch)) && isVowel(ch))
        {
            vowels++;
        }

        if (isdigit(static_cast<unsigned char>(ch)))
        {
            digits++;
        }
    }

    if (characters > 0)
    {
        inputFile.clear();
        inputFile.seekg(-1, ios::end);

        char lastCharacter;
        inputFile.get(lastCharacter);

        if (lastCharacter != '\n')
        {
            lines++;
        }
    }

    inputFile.close();

    cout << "\nFile Statistics" << endl;
    cout << "----------------" << endl;
    cout << "Lines: " << lines << endl;
    cout << "Words: " << words << endl;
    cout << "Characters: " << characters << endl;
    cout << "Vowels: " << vowels << endl;
    cout << "Digits: " << digits << endl;
    cout << "Spaces: " << spaces << endl;

    return 0;
}