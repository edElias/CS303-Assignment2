#include "LinkedList.h"
// Constructor
 
Linked::Linked() : headPtr(nullptr), tailPtr(nullptr), num_Items(0) {}

// Destructor
 
Linked::~Linked() {
    clear();
}

// Add a new item to the front of the list
 
void Linked::push_front(string newItem) {
    Node* newNode = new Node{ newItem, headPtr };
    headPtr = newNode;
    if (tailPtr == nullptr) {
        tailPtr = headPtr;
    }
    num_Items++;
}

// Add a new item to the back of the list
 
void Linked::push_back(string newItem) {
    Node* newNode = new Node{ newItem, nullptr };
    if (tailPtr) {
        tailPtr->nextPtr = newNode;
    }
    tailPtr = newNode;
    if (headPtr == nullptr) {
        headPtr = tailPtr;
    }
    num_Items++;
}
// Remove and return the front item
 
string Linked::pop_front() {
    if (isEmpty()) {
        throw underflow_error("List is empty");
    }
    Node* tempPtr = headPtr;
    string frontData = headPtr->data;  // Store the front data
    headPtr = headPtr->nextPtr;           // Move the head pointer
    delete tempPtr;                       // Free memory
    num_Items--;

    // If the list is now empty, set tailPtr to nullptr as well
    if (headPtr == nullptr) {
        tailPtr = nullptr;
    }

    return frontData;
}

// Remove and return the back item
 
string Linked::pop_back() {
    if (isEmpty()) {
        throw underflow_error("List is empty");
    }
    Node* current = headPtr;
    string backData;

    if (headPtr == tailPtr) {
        // If the list has only one item
        backData = headPtr->data;
        delete headPtr;
        headPtr = tailPtr = nullptr;
    }
    else {
        // Traverse to the second-to-last node
        while (current->nextPtr != tailPtr) {
            current = current->nextPtr;
        }
        backData = tailPtr->data;  // Store the tail data
        delete tailPtr;            // Free memory
        tailPtr = current;         // Update the tail pointer
        tailPtr->nextPtr = nullptr;
    }

    num_Items--;
    return backData;
}

// Return the front item without removing it
 
string Linked::check_front() const {
    if (isEmpty()) {
        throw underflow_error("List is empty");
    }
    return headPtr->data;
}

// Return the back item without removing it
 
string Linked::check_back() const {
    if (isEmpty()) {
        throw underflow_error("List is empty");
    }
    return tailPtr->data;
}

// Check if the list is empty
 
bool Linked::isEmpty() const {
    return num_Items == 0;
}

// Insert an item at a specific index
 
void Linked::insert(size_t index, const string& item) {
    if (index == 0) {
        push_front(item);
        return;
    }

    if (index >= num_Items) {
        push_back(item);
        return;
    }

    Node* current = headPtr;
    for (size_t i = 0; i < index - 1; ++i) {
        current = current->nextPtr;
    }

    Node* newNode = new Node{ item, current->nextPtr };
    current->nextPtr = newNode;
    num_Items++;
}

// Remove an item at a specific index
 
bool Linked::remove(size_t index) {
    if (index >= num_Items || isEmpty()) {
        return false;
    }

    if (index == 0) {
        pop_front();
        return true;
    }

    Node* current = headPtr;
    for (size_t i = 0; i < index - 1; ++i) {
        current = current->nextPtr;
    }

    Node* toDelete = current->nextPtr;
    current->nextPtr = toDelete->nextPtr;
    if (toDelete == tailPtr) {
        tailPtr = current;
    }
    delete toDelete;
    num_Items--;

    return true;
}

// Find the index of the first occurrence of an item
 
size_t Linked::find(const string& item) const {
    Node* current = headPtr;
    size_t index = 0;
    while (current != nullptr) {
        if (current->data == item) {
            return index;
        }
        current = current->nextPtr;
        index++;
    }
    return num_Items;
}

// Get the number of items in the list
 
int Linked::getSize() const {
    return num_Items;
}

// Clear the entire list
 
void Linked::clear() {
    Node* current = headPtr;
    while (current != nullptr) {
        Node* nextNode = current->nextPtr;
        delete current;
        current = nextNode;
    }
    headPtr = tailPtr = nullptr;
    num_Items = 0;
}

// Print the list
 
void Linked::print() const {
    Node* current = headPtr;
    while (current != nullptr) {
        cout << current->data << " -> ";
        current = current->nextPtr;
    }
    cout << "nullptr" << endl;
}
