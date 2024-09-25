#include "function.h"
#include "LinkedList.h"

// 
// Function to display the menu options
static void displayMenu() {
    cout << "\n--- Main Menu ---\n";
    cout << "1. Enter Single Linked List\n";
    cout << "2. Enter Stack\n";
    cout << "0. Exit\n";
    cout << "Choose an option: ";
}

//VectorStack myStack
//loading names into linked list
//void readFile(Linked& myLinked);
int main() {

    string choice;

    while(choice!= "0")
    {
        displayMenu();
        cin >> choice;
        if (choice == "1")
        {
            enterLinkedList();
        }
        else if (choice == "2")
        {
            enterStackList();
        }
    };
    return 0;
}