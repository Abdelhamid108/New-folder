#ifndef BOOK_H  // Header guard to prevent multiple inclusions
#define BOOK_H

#include "Std_Libraries.h"

// Class representing a book
class book
{
public:
    string name;      // Name of the book
    string author;    // Name of the author
    string category;  // Category of the book (e.g., Fiction, Mystery, etc.)
    int p_year;       // Publish year of the book

    // Default constructor to initialize book details
    book()
    {
        cout << "\n******************************************\n";
        cout << "           Enter Book Details             \n";
        cout << "******************************************\n";

        // Prompt user for the book's name
        cout << "Enter the name of the book: ";
        getline(cin, name);  // Allow spaces in the book name

        // Prompt user for the author's name
        cout << "Enter the author of the book: ";
        getline(cin, author);  // Allow spaces in the author's name

        // Prompt user to select the category of the book
        int i;
        cout << "\nSelect the category of the book:\n";
        cout << "1. Fiction\n";
        cout << "2. Mystery / Thriller / Crime\n";
        cout << "3. Fantasy\n";
        cout << "4. Science Fiction\n";
        cout << "5. Romance\n";
        cout << "Enter your choice (1-5): ";

        // Input validation for category selection
        do
        {
            cin >> i;
            if(cin.fail())
            {
                cin.clear();  // Clear error flag
                cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Discard invalid input
                cout << "Invalid input. Please enter a number between 1 and 5.\n";
            }
        } while((i < 1) || (i > 5));  // Loop until valid input is entered

        // Set the book category based on user input
        switch(i)
        {
            case 1: category = "Fiction"; break;
            case 2: category = "Mystery / Thriller / Crime"; break;
            case 3: category = "Fantasy"; break;
            case 4: category = "Science Fiction"; break;
            case 5: category = "Romance"; break;
        }

        // Prompt user for the publish year with input validation
        cout << "\nEnter the publish year (between 1000 and 2025): ";
        while(true)
        {  // Input validation for publish year
            cin >> p_year;

            // Check if the input is a valid number within the specified range
            if ((cin.fail()) || (p_year < 1000) || (p_year > 2025))
            {
                cin.clear();  // Clear error flag
                cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Discard invalid input
                cout << "Invalid input. Please enter a valid year between 1000 and 2025: ";
            }
            else
            {
                break;  // Exit loop if input is valid
            }
        }
        cin.ignore();  // Ignore remaining newline character in the buffer
        cout << "******************************************\n";
    }

    // Method to update book data (e.g., name, author, category, and publish year)
    void update_data()
    {
        cout << "******************************************\n";
        cout << "           Update Book Details            \n";
        cout << "******************************************\n";

        // Prompt user for updated book information
        cout << "Enter the new name of the book: ";
        getline(cin, name);  // Allow spaces in the book name

        cout << "Enter the new author of the book: ";
        getline(cin, author);  // Allow spaces in the author's name

        cout << "Enter the new category of the book: ";
        getline(cin, category);  // Allow spaces in the category

        // Prompt user for the new publish year with input validation
        cout << "\nEnter the new publish year (between 1000 and 2025): ";
        while (true) {  // Input validation for publish year
            cin >> p_year;

            // Check if the input is a valid number within the specified range
            if (cin.fail() || p_year < 1000 || p_year > 2025) {
                cin.clear();  // Clear error flag
                cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Discard invalid input
                cout << "Invalid input. Please enter a valid year between 1000 and 2025: ";
            } else {
                break;  // Exit loop if input is valid
            }
        }
        cin.ignore();  // Ignore remaining newline character in the buffer
        cout << "******************************************\n";
    }

    // Method to print book details in a well-structured and formatted manner
    void print() const
    {
        cout << "*******************************************\n";
        cout << "             Book Information              \n";
        cout << "*******************************************\n";
        cout << "Name        : " << name << endl;
        cout << "Author      : " << author << endl;
        cout << "Category    : " << category << endl;
        cout << "Publish Year: " << p_year << endl;
        cout << "******************************************\n";
    }
};

#endif  // End of the header guard
