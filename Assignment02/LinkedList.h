//pre-processors
#pragma once
#include <string>
#include <iostream>
using namespace std;

template <class Item_type>	
struct Node {
	Item_type data;
	Node* nextPtr; //pointer to the next node structure
};

//Linked class declaration
template <class Item_type>
class Linked {
protected:
	Node* headPtr;
	Node* tailPtr; //not really needed
	int num_Items;

public:
    // Constructor
    Linked();
    // Destructor
    ~Linked();

    // Add a new item to the front or back of the list
    void push_front(Item_type newItem);
    void push_back(Item_type newItem);

    // Remove and return the front or back item
    Item_type pop_front();
    Item_type pop_back();

    // Return the front or back item without removing it
    Item_type check_front() const;
    Item_type check_back() const;

    // Check if the list is empty
    bool isEmpty() const;

    // Insert item at a specific index
    void insert(size_t index, const Item_type& item);

    // Remove item at a specific index
    bool remove(size_t index);

    // Find the index of the first occurrence of an item
    size_t find(const Item_type& item) const;

    // Get the number of items in the list
    int getSize() const;

    // Print the list
    void print() const;
};
};