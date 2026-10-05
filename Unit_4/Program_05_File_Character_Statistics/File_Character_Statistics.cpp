#include <cctype>
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

int main()
{
    // Open message.txt for reading
    ifstream inputFile("message.txt");

    // Check whether the file opened successfully
    if (!inputFile)
    {
        cerr << "Error: Could not open message.txt" << endl;
        return 1;
    }

    // Variables to store different character counts
    int vowels = 0;
    int consonants = 0;
    int digits = 0;
    int spaces = 0;
    int punctuation = 0;

    // Variable to store each character read from the file
    char ch;

    // Read the file character by character
    while (inputFile.get(ch))
    {
        // Check whether the character is an alphabet
        if (isalpha(static_cast<unsigned char>(ch)))
        {
            // Convert the character to lowercase
            char lower = tolower(static_cast<unsigned char>(ch));

            // Check whether the character is a vowel
            if (lower == 'a' || lower == 'e' || lower == 'i' ||
                lower == 'o' || lower == 'u')
            {
                vowels++;
            }
            else
            {
                // If it is not a vowel, it is a consonant
                consonants++;
            }
        }
        // Check whether the character is a digit
        else if (isdigit(static_cast<unsigned char>(ch)))
        {
            digits++;
        }
        // Check whether the character is a space or whitespace
        else if (isspace(static_cast<unsigned char>(ch)))
        {
            spaces++;
        }
        // Check whether the character is punctuation
        else if (ispunct(static_cast<unsigned char>(ch)))
        {
            punctuation++;
        }
    }

    // Close the file after reading
    inputFile.close();

    // Display the character statistics
    cout << "File Character Statistics" << endl;
    cout << "-------------------------" << endl;
    cout << "Vowels: " << vowels << endl;
    cout << "Consonants: " << consonants << endl;
    cout << "Digits: " << digits << endl;
    cout << "Spaces: " << spaces << endl;
    cout << "Punctuation characters: " << punctuation << endl;

    return 0;
}