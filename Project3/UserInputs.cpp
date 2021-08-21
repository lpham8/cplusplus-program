#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include <Windows.h>
#include "UserInputs.h"
#include "ItemsPurchased.h"

using namespace std;

// default constructor to display logo
UserInputs::UserInputs() {
		
	// prompts user
	cout << string(33, '*') << endl;
	cout << string(33, '*') << endl;
	cout << string(8, '*') << setw(17) << "" << string(8, '*') << endl;
	cout << string(8, '*') << "  Corner Grocer  " << string(8, '*') << endl;
	cout << string(8, '*') << setw(17) << "" << string(8, '*') << endl;
	cout << string(33, '*') << endl;
	cout << string(33, '*') << endl << endl;
	cout << "Menu: " << endl << endl;

}

// display the menu
void UserInputs::DisplayMenu() {

	cout << "1. List all items purchased and the number of times purchased." << endl;
	cout << "2. Show a number of times a specific item has been purchased." << endl;
	cout << "3. Show Histogram" << endl << endl;

	cout << "Make Your Selection. Enter a # between 1-3: ";
}

// function for option 2 on menu
string UserInputs::Option2Input() {
	cout << "Enter an item to return the number of times purchased: ";
	getline(cin, itemInput);
	transform(itemInput.begin(), itemInput.end(), itemInput.begin(), tolower);
	itemInput[0] = toupper(itemInput[0]);

	for (i = 0; i < iPurchased.itemsPurchased.size(); ++i) {
		if (iPurchased.itemsPurchased[i] == itemInput) {
			return itemInput;
		}
	}
	return itemInput;
}

UserInputs::~UserInputs() {}
