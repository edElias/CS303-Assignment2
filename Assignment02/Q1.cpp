#include "function.h"
#include <fstream>
#include <sstream>

Linked myLinked;

void readFile() //load names into myLinked list
{
	string name;
	ifstream inputFile;
	inputFile.open("names.txt");
	if (!inputFile.is_open()) {
		cout << "Error opening file!" << endl;
		return;
	}

	while (inputFile >> name)
	{
		myLinked.push_back(name);
	}
}

void enterLinkedList()
{
	readFile(); //Load Names
	string name;
	int userIndex;
	cout << "This is the current list: " << endl;
	myLinked.print();

	//shows if list is empty
	cout << "Is List Empty: ";
	if (myLinked.isEmpty() == 1)
		cout << " Yes " << endl;
	else
		cout << " No " << endl;

	//Enter 2 Names to push to front and back
	cout << "\nEnter a name to push onto the Front of list: " << endl;
	cin >> name;
	myLinked.push_front(name);

	cout << "\nEnter a name to push onto the Back of list: " << endl;
	cin >> name;
	myLinked.push_back(name);

	//Inserting 
	cout << "\nEnter an index: " << endl;
	cin >> userIndex;
	cout << "\nIndexed removed successful: ";
		if (myLinked.remove(userIndex) == 1)
			cout << " Yes " << endl;
		else
			cout << " No " << endl;

	//remove
	cout << "\nThe following will remove an item using the index" << endl;
	cout << "\nEnter an index: " << endl;
	cin >> userIndex;
	cout << "\nEnter a name: " << endl;
	cin >> name;
	myLinked.insert(userIndex, name);

	//Recurrence
	cout << "\nCurrent List: ";
	myLinked.print();
	cout << endl;
	cout << "\nThe following will attempt to find a name of your choosing" << endl;
	cout << "\nEnter a name to find: " << endl;
	cin >> name;
	int temp;
	temp = myLinked.find(name);
	if (temp == myLinked.getSize())
		cout << "Name was not found, the size of the list is: " << temp << endl;
	else
		cout << "Name was found in index: " << temp << endl;
	
	//Following prints our FRONT and BACK using ONLY VIEW
	//POP front & back then prints
	//Removes all items from list, THEN checks if list is empty
	cout << "\nViewing Head: " << myLinked.check_front() << "\nViewing Tail: " << myLinked.check_back() << endl;
	cout << "\nPop Front: " << myLinked.pop_front() << "\nPop Back: " << myLinked.pop_back() << endl;
	cout << "\nRemoved list items" << endl;
	myLinked.clear();
	cout << "\nIs List Empty: ";
	if (myLinked.isEmpty() == 1)
		cout << " Yes " << endl;
	else
		cout << " No " << endl;

}