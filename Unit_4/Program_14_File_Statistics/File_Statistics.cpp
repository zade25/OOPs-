#include <cctype>
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

// Function to check whether a character is a vowel
bool isVowel(char ch)
{
    // Convert the character to lowercase
    ch = static_cast<char>(tolower(static_cast<unsigned char>(ch)));

    // Return true if the character is a vowel
    return ch == 'a' || ch == 'e' || ch == 'i' ||
           ch == 'o' || ch == 'u';
}

int main()
{
    // Variable to store the file name entered by the user
    string fileName;

    // Ask the user to enter the file name
    cout << "Enter file name: ";
    getline(cin, fileName);

    // Open the specified file for reading
    ifstream inputFile(fileName);

    // Check whether the file opened successfully
    if (!inputFile)
    {
        cerr << "Error: Could not open " << fileName << endl;
        return 1;
    }

    // Variables to store different file statistics
    int lines = 0;
    int words = 0;
    int characters = 0;
    int vowels = 0;
    int digits = 0;
    int spaces = 0;

    // Used to determine whether the current character is inside a word
    bool insideWord = false;

    // Variable to store each character read from the file
    char ch;

    // Read the file character by character
    while (inputFile.get(ch))
    {
        // Count every character
        characters++;

        // Count lines whenever a newline character is found
        if (ch == '\n')
        {
            lines++;
        }

        // Check whether the character is whitespace
        if (isspace(static_cast<unsigned char>(ch)))
        {
            // Count normal spaces
            if (ch == ' ')
            {
                spaces++;
            }

            // A whitespace character means the current word has ended
            insideWord = false;
        }
        else if (!insideWord)
        {
            // A non-whitespace character after whitespace starts a new word
            words++;
            insideWord = true;
        }

        // Count vowels
        if (isalpha(static_cast<unsigned char>(ch)) && isVowel(ch))
        {
            vowels++;
        }

        // Count digits
        if (isdigit(static_cast<unsigned char>(ch)))
        {
            digits++;
        }
    }

    // If the file does not end with a newline,
    // count the last line as well
    if (characters > 0)
    {
        // Clear the end-of-file flag
        inputFile.clear();

        // Move the input pointer to the last character
        inputFile.seekg(-1, ios::end);

        // Variable to store the last character
        char lastCharacter;

        // Read the last character
        inputFile.get(lastCharacter);

        // If the last character is not a newline,
        // the final line needs to be counted
        if (lastCharacter != '\n')
        {
            lines++;
        }
    }

    // Close the file after reading
    inputFile.close();

    // Display the calculated file statistics
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
