#pragma once
#include "function.h"

//Stack class declaration
class VectorStack {
private:
    vector<int> container;
    int itemCount = 0;

public:
    // Constructor
    VectorStack();

    // Check if the Stack is empty
    bool isEmpty() const;

    //Insert some integer values onto the stack.
    void push(int newItem);

    //Remove an element from the stack.
    int pop();

    //Find the Top of the stack.
    void FindTop();

    //Find average value of the stack elements.
    double average();

    // Print the list
    void print();
};