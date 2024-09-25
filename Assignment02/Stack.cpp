#include "Stack.h"

// Constructor
VectorStack::VectorStack() : container(10) {}

// Check if the Stack is empty
bool VectorStack::isEmpty() const 
{
	if (itemCount == 0)
		return true;
	return false; 
}

//Insert some integer values onto the stack.
void VectorStack::push(int newItem)
{
	container.at(itemCount) = newItem;
	itemCount++;
}

//Remove an element from the stack.
int VectorStack::pop() 
{
	if (itemCount == 0) {
		cout << "Error: Stack is empty, cannot pop an element!" << endl;
		return 0;
	}
	else {
		int num = container[itemCount - 1]; // Get the top element
		itemCount--; // Decrease the stack count
		return num;
	}
}

//Find the Top of the stack.
void VectorStack::FindTop() 
{
	if (itemCount == 0) {
		cout << "The stack is empty." << endl;
	}
	else {
		cout << "\nTop of the stack: " << container[itemCount - 1] << endl;
	}
}

//Find average value of the stack elements.
double VectorStack::average() 
{
	if (itemCount == 0) {
		cout << "\nThe stack is empty. Cannot calculate average." << endl;
		return 0;
	}

	double sum = 0;
	for (int i = 0; i < itemCount; i++) {
		sum += container[i];
	}

	return sum / itemCount; // Return the average
}

// Print the list
void VectorStack::print() 
{
	if (itemCount == 0) {
		cout << "The stack is empty." << endl;
	}
	else {
		cout << "Stack elements: ";
		for (int i = 0; i < itemCount; i++) {
			cout << container[i] << " ";
		}
		cout << endl;
	}

}