#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

// Class to store and manage book records
class Book
{
private:
    // Data members for book details
    int bookId;
    string title;
    string author;

public:
    // Constructor to initialize book details
    Book(int id = 0, string bookTitle = "", string bookAuthor = "")
    {
        bookId = id;
        title = bookTitle;
        author = bookAuthor;
    }

    // Function to save a book record to the file
    void saveToFile()
    {
        // Open library.txt in append mode
        ofstream outputFile("library.txt", ios::app);

        // Check whether the file opened successfully
        if (!outputFile)
        {
            cout << "Error: Could not open library.txt" << endl;
            return;
        }

        // Store the book details using | as a separator
        outputFile << bookId << "|" << title << "|" << author << endl;

        // Close the file after writing
        outputFile.close();

        // Display a success message
        cout << "Book record added successfully." << endl;
    }

    // Static function to display all book records
    static void displayBooks()
    {
        // Open library.txt for reading
        ifstream inputFile("library.txt");

        // Check whether the file exists
        if (!inputFile)
        {
            cout << "No book records found." << endl;
            return;
        }

        // Variable to store each line from the file
        string line;

        // Display the library heading
        cout << "\nLibrary Records" << endl;
        cout << "----------------------------------------" << endl;

        // Read the file line by line
        while (getline(inputFile, line))
        {
            // Create a string stream to separate the fields
            stringstream record(line);

            // Variables to store book details
            string id;
            string title;
            string author;

            // Extract the book ID, title, and author
            if (getline(record, id, '|') &&
                getline(record, title, '|') &&
                getline(record, author))
            {
                // Display the book details
                cout << "Book ID: " << id << endl;
                cout << "Title: " << title << endl;
                cout << "Author: " << author << endl;
                cout << "----------------------------------------" << endl;
            }
        }

        // Close the file
        inputFile.close();
    }

    // Static function to search for a book using its ID
    static void searchBook()
    {
        // Open library.txt for reading
        ifstream inputFile("library.txt");

        // Check whether the file exists
        if (!inputFile)
        {
            cout << "No book records found." << endl;
            return;
        }

        // Variable to store the ID entered by the user
        int searchId;

        // Ask the user for the book ID
        cout << "Enter book ID to search: ";
        cin >> searchId;

        // Variable to store each line from the file
        string line;

        // Variable to check whether the book was found
        bool found = false;

        // Read the file line by line
        while (getline(inputFile, line))
        {
            // Create a string stream for the current record
            stringstream record(line);

            // Variables to store book details
            string id;
            string title;
            string author;

            // Extract the book details
            if (getline(record, id, '|') &&
                getline(record, title, '|') &&
                getline(record, author))
            {
                // Compare the stored ID with the searched ID
                if (stoi(id) == searchId)
                {
                    // Display the matching book
                    cout << "\nBook Found" << endl;
                    cout << "Book ID: " << id << endl;
                    cout << "Title: " << title << endl;
                    cout << "Author: " << author << endl;

                    // Mark the book as found
                    found = true;

                    // Stop searching
                    break;
                }
            }
        }

        // Display a message if the book was not found
        if (!found)
        {
            cout << "Book not found." << endl;
        }

        // Close the file
        inputFile.close();
    }
};

int main()
{
    // Variable to store the user's menu choice
    int choice;

    // Display the program heading
    cout << "Library Record Manager" << endl;
    cout << "======================" << endl;

    // Display the menu repeatedly until the user chooses Exit
    do
    {
        cout << "\n1. Add Book" << endl;
        cout << "2. Display Books" << endl;
        cout << "3. Search Book" << endl;
        cout << "4. Exit" << endl;

        // Ask the user to select an option
        cout << "Enter your choice: ";
        cin >> choice;

        // Perform the selected operation
        switch (choice)
        {
            case 1:
            {
                // Variables to store book details
                int id;
                string title;
                string author;

                // Ask the user to enter the book ID
                cout << "Enter book ID: ";
                cin >> id;

                // Clear the newline from the input buffer
                cin.ignore();

                // Ask the user to enter the book title
                cout << "Enter book title: ";
                getline(cin, title);

                // Ask the user to enter the author's name
                cout << "Enter author name: ";
                getline(cin, author);

                // Create a Book object using the entered details
                Book book(id, title, author);

                // Save the book record to the file
                book.saveToFile();

                break;
            }

            case 2:
                // Display all book records
                Book::displayBooks();
                break;

            case 3:
                // Search for a book by ID
                Book::searchBook();
                break;

            case 4:
                // Exit the program
                cout << "Exiting Library Record Manager." << endl;
                break;

            default:
                // Handle an invalid menu choice
                cout << "Invalid choice. Please try again." << endl;
        }

    } while (choice != 4);

    return 0;
}