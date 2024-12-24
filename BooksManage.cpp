#include "BooksManage.h"

// Function to handle input validation for menu choices
template <typename T>
T getValidatedInput(T lowerLimit, T upperLimit, const string& prompt) {
    T input;
    while (true) {
        cout << prompt;
        cin >> input;

        if (cin.fail() || input < lowerLimit || input > upperLimit) {
            cin.clear();  // Clear the error state
            cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Ignore invalid input
            cout << "Invalid input. Please enter a value between " << lowerLimit << " and " << upperLimit << ".\n";
        } else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Only here to clear the buffer after valid input
            break;  // Valid input, break the loop
        }
    }
    return input;
}

// Function to insert a book into the library
void book_manage::insert_book() {
    cout << "****************************************\n";
    cout << "           Insert Book Menu             \n";
    cout << "****************************************\n";
    cout << "1 - Insert book at the beginning\n";
    cout << "2 - Insert book at the end\n";
    cout << "3 - Insert book at a specific position\n";
    cout << "****************************************\n";

    int choice = getValidatedInput(1, 3, "\nEnter the number of the operation you want (1-3): ");

    switch (choice) {
        case 1:
            library.insert_first(); // Insert book at the beginning
            break;
        case 2:
            library.insert_last(); // Insert book at the end
            break;
        case 3:
            {
                int position;
                cout << "Enter the position: ";
                cin >> position;
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clearing the buffer after position input
                library.insert_at_pos(position); // Insert book at a specific position
            }
            break;
    }
}

// Function to delete a book from the library
void book_manage::delete_book() {
    cout << "****************************************\n";
    cout << "           Delete Book Menu             \n";
    cout << "****************************************\n";
    cout << "1 - Delete book at the beginning\n";
    cout << "2 - Delete book at the end\n";
    cout << "3 - Delete book at a specific position\n";
    cout << "4 - Delete book by the title\n";
    cout << "****************************************\n";


    if (library.isEmpty()) {
        cout << "The list is empty. No book to Delete.\n";
        return;
    }

    int choice = getValidatedInput(1, 4, "Enter the number of the operation you want (1-4): ");

    switch (choice) {
        case 1:
            library.delete_first(); // Delete book from the beginning
            break;
        case 2:
            library.delete_at_end(); // Delete book from the end
            break;
        case 3:
            {
                int position;
                cout << "Enter the position: ";
                cin >> position;
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clearing the buffer after position input
                library.delete_at_pos(position); // Delete book from a specific position
            }
            break;
        case 4:
            {
                string title;
                cout << "Enter the name of the book you want to delete: ";
                getline(cin, title);
                library.delete_book(title); // Delete book by title
            }
            break;
    }
}

// Function to search for a book in the library
void book_manage::search() {
    cout << "****************************************\n";
    cout << "           Search Book Menu             \n";
    cout << "****************************************\n";

     if (library.isEmpty()) {
        cout << "The list is empty. No book to search.\n";
        return;
    }

    string title;
    cout << "Enter the name of the book you want to search for: ";
    getline(cin, title);

    node* search = library.search_Book(title); // Search for the book by title
    if (search) {
        int x;
        cout << "Book is found \n\n";
        cout << "------------------------\n\n";
        cout << "1- Print the book information \n";
        cout << "2- Update the book information \n";
        cout << "3- Delete this book \n";
        cout << "4- Exit\n\n";
        x = getValidatedInput(1, 4, "Enter the number of the operation you want (1-4): ");

        switch (x) {
            case 1:
                search->data.print();
                break;
            case 2:
                search->data.update_data();
                break;
            case 3:
                library.delete_book(search);
                break;
            case 4:
                break;
        }
    } else {
        cout << "The book "<<title<<" is not found\n";
    }
}

// Function to sort the books in the library
void book_manage::sort() {
    cout << "****************************************\n";
    cout << "            Sort Book Menu              \n";
    cout << "****************************************\n";

    char choice;
    cout << "Are you sure you want to sort the list? (y/n): ";
    do {
        cin >> choice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clearing the buffer after the 'y/n' input
        if (cin.fail()) {
            cin.clear();
            cout << "Invalid input. Please enter 'y' or 'n'.\n";
        }
    } while (choice != 'y' && choice != 'n' && choice != 'Y' && choice != 'N');

    if (choice == 'y' || choice == 'Y') {
        cout << "Sorting the list...\n";
        library.sort(); // Sort the books
    } else {
        cout << "Sorting process aborted.\n";
    }
}

// Function to display the books in the library
void book_manage::display() {
    cout << "****************************************\n";
    cout << "          Display Book Menu             \n";
    cout << "****************************************\n";
    cout << "1 - Display list forward\n";
    cout << "2 - Display list backward\n";
    cout << "****************************************\n";

    if (library.isEmpty())  // Check if the list is empty
    {
        cout << "The list is empty\n";  // Print message if the list is empty
        return;
    }


    int choice = getValidatedInput(1, 2, "Enter the number of the operation (1-2): ");

    if (choice == 1) {
        library.display_Forward(); // Display books in forward order
    } else {
        library.display_backward(); // Display books in backward order
    }
}

// Function to update book information
void book_manage::updateBook() {
     cout << "****************************************\n";
     cout << "           Update Book Menu             \n";
     cout << "****************************************\n";

     if (library.isEmpty()) {
        cout << "The list is empty. No book to update.\n";
        return;
    }
    string title;
    cout << "Enter the name of the book you want to update its information: ";
    getline(cin, title);
    library.update_book(title); // Update the book information
}

// Function to destroy the book list
void book_manage::destroy_list() {
    cout << "****************************************\n";
    cout << "        Destroy Book List Menu          \n";
    cout << "****************************************\n";

    char choice;
    cout << "Are you sure you want to free the list? (y/n): ";
    do {
        cin >> choice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clearing the buffer after the 'y/n' input
        if (cin.fail()) {
            cin.clear();
            cout << "Invalid input. Please enter 'y' or 'n'.\n";
        }
    } while (choice != 'y' && choice != 'n' && choice != 'Y' && choice != 'N');

    if (choice == 'y' || choice == 'Y') {
        cout << "Freeing the list...\n";
        library.freeList(); // Free the list
    } else {
        cout << "Freeing process aborted.\n";
    }
}

// Function to get the length of the book list
void book_manage::get_length() {
    cout << "The list contains " << library.get_length() << " Books\n";
}
