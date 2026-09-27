#include <cctype>
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

int main()
{
    ifstream inputFile("message.txt");

    if (!inputFile)
    {
        cerr << "Error: Could not open message.txt" << endl;
        return 1;
    }

    int vowels = 0;
    int consonants = 0;
    int digits = 0;
    int spaces = 0;
    int punctuation = 0;

    char ch;

    while (inputFile.get(ch))
    {
        if (isalpha(static_cast<unsigned char>(ch)))
        {
            char lower = tolower(static_cast<unsigned char>(ch));

            if (lower == 'a' || lower == 'e' || lower == 'i' ||
                lower == 'o' || lower == 'u')
            {
                vowels++;
            }
            else
            {
                consonants++;
            }
        }
        else if (isdigit(static_cast<unsigned char>(ch)))
        {
            digits++;
        }
        else if (isspace(static_cast<unsigned char>(ch)))
        {
            spaces++;
        }
        else if (ispunct(static_cast<unsigned char>(ch)))
        {
            punctuation++;
        }
    }

    inputFile.close();

    cout << "File Character Statistics" << endl;
    cout << "-------------------------" << endl;
    cout << "Vowels: " << vowels << endl;
    cout << "Consonants: " << consonants << endl;
    cout << "Digits: " << digits << endl;
    cout << "Spaces: " << spaces << endl;
    cout << "Punctuation characters: " << punctuation << endl;

    return 0;
}