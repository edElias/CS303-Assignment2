#include "function.h"


VectorStack myStack;

void loadStack() //load random nums into myStack
{
	const int size = 10;
	int num;
	// Seed for random number generation
	srand(time(0));

	// Generate 15 random numbers
	for (int i = 0; i < size; ++i) {
		num = rand() % 100 + 1; // Random number between 1 and 100
		myStack.push(num);
	}
}

void enterStackList()
{
	double avg;
	//checking if stack is empty
	cout << "\nChecking if stack is empty: ";
	if (myStack.isEmpty() == 1)
		cout << "\n Stack is Empty" << endl;
	else
		cout << "\n Stack is Not Empty " << endl;

	//load stack with random numbers
	cout << "\n Loading Stack... ";
	loadStack();
	cout << endl;

	cout << "\nNEW UPDATE: ";
	myStack.print();
	cout << endl;
	
	//Removing an element 
	cout << "Removing an element: ";
	myStack.pop();
	
	cout << "\nNEW UPDATE: ";
	myStack.print();
	cout << endl;

	//Finding the top of stack

	cout << "\nFinding the top of your stack...";
	myStack.FindTop();

	//Average of stack numbers
	avg = myStack.average();
	cout << "\nThe Stacks average is: " << fixed << setprecision(2) << avg << endl;
}
