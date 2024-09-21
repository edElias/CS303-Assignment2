#include "LinkedList.h"
// Constructor
template <class Item_type>
Linked<Item_type>::Linked() : headPtr(nullptr), tailPtr(nullptr), num_Items(0) {}

// Destructor
template <class Item_type>
Linked<Item_type>::~Linked() {
    clear();
}

// Add a new item to the front of the list
template <class Item_type>
void Linked<Item_type>::push_front(Item_type newItem) {
    Node<Item_type>* newNode = new Node<Item_type>{ newItem, headPtr };
    headPtr = newNode;
    if (tailPtr == nullptr) {
        tailPtr = headPtr;
    }
    num_Items++;
}

// Add a new item to the back of the list
template <class Item_type>
void Linked<Item_type>::push_back(Item_type newItem) {
    Node<Item_type>* newNode = new Node<Item_type>{ newItem, nullptr };
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
template <class Item_type>
Item_type Linked<Item_type>::pop_front() {
    if (isEmpty()) {
        throw std::underflow_error("List is empty");
    }
    Node<Item_type>* tempPtr = headPtr;
    Item_type frontData = headPtr->data;  // Store the front data
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
template <class Item_type>
Item_type Linked<Item_type>::pop_back() {
    if (isEmpty()) {
        throw std::underflow_error("List is empty");
    }
    Node<Item_type>* current = headPtr;
    Item_type backData;

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
template <class Item_type>
Item_type Linked<Item_type>::check_front() const {
    if (isEmpty()) {
        throw std::underflow_error("List is empty");
    }
    return headPtr->data;
}

// Return the back item without removing it
template <class Item_type>
Item_type Linked<Item_type>::check_back() const {
    if (isEmpty()) {
        throw std::underflow_error("List is empty");
    }
    return tailPtr->data;
}

// Check if the list is empty
template <class Item_type>
bool Linked<Item_type>::isEmpty() const {
    return num_Items == 0;
}

// Insert an item at a specific index
template <class Item_type>
void Linked<Item_type>::insert(size_t index, const Item_type& item) {
    if (index == 0) {
        insertFront(item);
        return;
    }

    if (index >= num_Items) {
        insertBack(item);
        return;
    }

    Node<Item_type>* current = headPtr;
    for (size_t i = 0; i < index - 1; ++i) {
        current = current->nextPtr;
    }

    Node<Item_type>* newNode = new Node<Item_type>{ item, current->nextPtr };
    current->nextPtr = newNode;
    num_Items++;
}

// Remove an item at a specific index
template <class Item_type>
bool Linked<Item_type>::remove(size_t index) {
    if (index >= num_Items || isEmpty()) {
        return false;
    }

    if (index == 0) {
        pop_front();
        return true;
    }

    Node<Item_type>* current = headPtr;
    for (size_t i = 0; i < index - 1; ++i) {
        current = current->nextPtr;
    }

    Node<Item_type>* toDelete = current->nextPtr;
    current->nextPtr = toDelete->nextPtr;
    if (toDelete == tailPtr) {
        tailPtr = current;
    }
    delete toDelete;
    num_Items--;

    return true;
}

// Find the index of the first occurrence of an item
template <class Item_type>
size_t Linked<Item_type>::find(const Item_type& item) const {
    Node<Item_type>* current = headPtr;
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
template <class Item_type>
int Linked<Item_type>::getSize() const {
    return num_Items;
}

//// Clear the entire list
//template <class Item_type>
//void Linked<Item_type>::clear() {
//    Node<Item_type>* current = headPtr;
//    while (current != nullptr) {
//        Node<Item_type>* nextNode = current->nextPtr;
//        delete current;
//        current = nextNode;
//    }
//    headPtr = tailPtr = nullptr;
//    num_Items = 0;
//}

// Print the list
template <class Item_type>
void Linked<Item_type>::print() const {
    Node<Item_type>* current = headPtr;
    while (current != nullptr) {
        std::cout << current->data << " -> ";
        current = current->nextPtr;
    }
    std::cout << "nullptr" << std::endl;
}
