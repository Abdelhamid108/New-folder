#ifndef DoublyLinked_list_h
#define DoublyLinked_list_h

#include "book.h"  // For the book class, which holds the data for each node

// Node class to represent each element in the doubly linked list
class node
{
    public:
    book data;  // Data for each node, stored as a 'book' object
    node* next = nullptr;  // Pointer to the next node in the list (initialized to null)
    node* prev = nullptr;  // Pointer to the previous node in the list (initialized to null)
};

// Doubly linked list class
class doubly_linkedlist
{
    public:
    // Constructor to initialize the list
    doubly_linkedlist();
    // Destructor to clean up memory when the list is destroyed
    ~doubly_linkedlist();

    // Methods for inserting nodes into the list at various positions
    void insert_first();  // Insert at the beginning of the list
    void insert_last();   // Insert at the end of the list
    //void insert_before(); // Insert before a specific node (based on book name)
    void insert_at_pos(int n);  // Insert at a specific position (based on index)

    // Methods for deleting nodes from the list
    void delete_first();  // Delete the first node in the list
    void delete_book(const string& name);   // Delete a specific book by its name
    void delete_book(node* delPtr);      //Delete a book using a pointer to the node
    void delete_at_end();  // Delete the last node in the list
    void delete_at_pos(int n);  // Delete a node at a specific position (based on index)


    void update_book(const string& book_name);
    // Methods for searching, displaying, and sorting the list
    bool isFound(const string& name);  // Check if a book with the given name is in the list
    void display_Forward();  // Display the list from head to tail
    void display_backward();  // Display the list from tail to head
    node* search_Book(const string& name);  // Search for a book by its name and display its data
    void sort();  // Sort the list alphabetically by book name

    // Utility methods for managing the list
    int get_length();  // Display the current length of the list
    bool isEmpty();  // Check if the list is empty
    void freeList();  // Delete all nodes in the list to free memory

    protected:
    node* head;  // Pointer to the first node (head) of the list
    node* tail;  // Pointer to the last node (tail) of the list
    int length;  // Number of nodes in the list
};

#endif
