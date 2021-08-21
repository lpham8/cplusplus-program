// user inputs class

#ifndef UserInputs_H
#define UserInputs_H
#include <iostream>
#include <vector>
#include "ItemsPurchased.h"
using namespace std;

class UserInputs {
public:
	UserInputs();
	~UserInputs();
	void DisplayMenu();
	string Option2Input();


private:
	// varriables delcared
	int i = 0;
	int j = 0;
	string itemInput = "";
	ItemsPurchased iPurchased;


};

#endif

