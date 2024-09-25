//pre-processors
#pragma once
#include "function.h"

struct Node {
	string data;
	Node* nextPtr; //pointer to the next node structure
};

//Linked class declaration
 
class Linked {
private:
	Node* headPtr;
	Node* tailPtr; //not really needed
	int num_Items;

public:
    // Constructor
    Linked();
    // Destructor
    ~Linked();

    // Add a new item to the front or back of the list
    void push_front(string newItem);
    void push_back(string newItem);

    // Remove and return the front or back item
    string pop_front();
    string pop_back();

    // Return the front or back item without removing it
    string check_front() const;
    string check_back() const;

    // Check if the list is empty
    bool isEmpty() const;

    // Insert item at a specific index
    void insert(size_t index, const string& item);

    // Remove item at a specific index
    bool remove(size_t index);

    // Find the index of the first occurrence of an item
    size_t find(const string& item) const;

    // Get the number of items in the list
    int getSize() const;

    void clear();

    // Print the list
    void print() const;
};