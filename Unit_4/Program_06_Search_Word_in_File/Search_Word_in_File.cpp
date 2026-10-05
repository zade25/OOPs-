#include <cctype>
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

// Function to remove punctuation and convert a word to lowercase
string cleanWord(string word)
{
    string cleaned;

    // Check each character of the word
    for (char ch : word)
    {
        // Keep only letters and digits
        if (isalnum(static_cast<unsigned char>(ch)))
        {
            // Convert characters to lowercase
            cleaned += tolower(static_cast<unsigned char>(ch));
        }
    }

    // Return the cleaned word
    return cleaned;
}

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

    // Variable to store the word entered by the user
    string searchWord;

    // Ask the user for the word to search
    cout << "Enter word to search: ";
    cin >> searchWord;

    // Clean the search word by removing punctuation
    // and converting it to lowercase
    searchWord = cleanWord(searchWord);

    // Variable to store each word read from the file
    string word;

    // Variable to count the number of occurrences
    int count = 0;

    // Read the file word by word
    while (inputFile >> word)
    {
        // Clean the word before comparing it
        word = cleanWord(word);

        // Compare the cleaned words
        if (word == searchWord)
        {
            count++;
        }
    }

    // Close the file after searching
    inputFile.close();

    // Display the number of occurrences
    cout << "The word '" << searchWord << "' occurred "
         << count << " time(s)." << endl;

    return 0;
}