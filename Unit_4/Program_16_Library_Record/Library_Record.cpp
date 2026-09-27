#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

class Book
{
private:
    int bookId;
    string title;
    string author;

public:
    Book(int id = 0, string bookTitle = "", string bookAuthor = "")
    {
        bookId = id;
        title = bookTitle;
        author = bookAuthor;
    }

    void saveToFile()
    {
        ofstream outputFile("library.txt", ios::app);

        if (!outputFile)
        {
            cout << "Error: Could not open library.txt" << endl;
            return;
        }

        outputFile << bookId << "|" << title << "|" << author << endl;

        outputFile.close();

        cout << "Book record added successfully." << endl;
    }

    static void displayBooks()
    {
        ifstream inputFile("library.txt");

        if (!inputFile)
        {
            cout << "No book records found." << endl;
            return;
        }

        string line;

        cout << "\nLibrary Records" << endl;
        cout << "----------------------------------------" << endl;

        while (getline(inputFile, line))
        {
            stringstream record(line);

            string id;
            string title;
            string author;

            if (getline(record, id, '|') &&
                getline(record, title, '|') &&
                getline(record, author))
            {
                cout << "Book ID: " << id << endl;
                cout << "Title: " << title << endl;
                cout << "Author: " << author << endl;
                cout << "----------------------------------------" << endl;
            }
        }

        inputFile.close();
    }

    static void searchBook()
    {
        ifstream inputFile("library.txt");

        if (!inputFile)
        {
            cout << "No book records found." << endl;
            return;
        }

        int searchId;

        cout << "Enter book ID to search: ";
        cin >> searchId;

        string line;
        bool found = false;

        while (getline(inputFile, line))
        {
            stringstream record(line);

            string id;
            string title;
            string author;

            if (getline(record, id, '|') &&
                getline(record, title, '|') &&
                getline(record, author))
            {
                if (stoi(id) == searchId)
                {
                    cout << "\nBook Found" << endl;
                    cout << "Book ID: " << id << endl;
                    cout << "Title: " << title << endl;
                    cout << "Author: " << author << endl;

                    found = true;
                    break;
                }
            }
        }

        if (!found)
        {
            cout << "Book not found." << endl;
        }

        inputFile.close();
    }
};

int main()
{
    int choice;

    cout << "Library Record Manager" << endl;
    cout << "======================" << endl;

    do
    {
        cout << "\n1. Add Book" << endl;
        cout << "2. Display Books" << endl;
        cout << "3. Search Book" << endl;
        cout << "4. Exit" << endl;

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
            {
                int id;
                string title;
                string author;

                cout << "Enter book ID: ";
                cin >> id;

                cin.ignore();

                cout << "Enter book title: ";
                getline(cin, title);

                cout << "Enter author name: ";
                getline(cin, author);

                Book book(id, title, author);
                book.saveToFile();

                break;
            }

            case 2:
                Book::displayBooks();
                break;

            case 3:
                Book::searchBook();
                break;

            case 4:
                cout << "Exiting Library Record Manager." << endl;
                break;

            default:
                cout << "Invalid choice. Please try again." << endl;
        }

    } while (choice != 4);

    return 0;
}