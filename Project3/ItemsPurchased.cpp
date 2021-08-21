
#include "ItemsPurchased.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;

ItemsPurchased::ItemsPurchased() {} // default constructor

// read txt file
void ItemsPurchased::ReadFile() {
	
	ifstream myFile;
	myFile.open("ItemsPurchased.txt");

	if (myFile.is_open()) {
		while (getline(myFile, readLine)) {
			// if (count())
			if (find(itemsPurchased.begin(), itemsPurchased.end(), readLine) == itemsPurchased.end()) {
				itemsPurchased.push_back(readLine);
			}			
		}
	}

	// lists purchased items for customers to view
	cout << "Items Purchased: " << endl;
	for (i = 0; i < itemsPurchased.size(); ++i) {
		cout << itemsPurchased[i] << ", ";
	}
	
	cout << endl << endl;

	myFile.close();

}


ItemsPurchased::~ItemsPurchased() {}