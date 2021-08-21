// items Purchased Class

#ifndef ItemsPurchased_H
#define ItemsPurchased_H
#include <vector>
#include <iostream>
using namespace std;

class ItemsPurchased {
public:
	ItemsPurchased(); 
	~ItemsPurchased();
	void ReadFile();
	vector<string> itemsPurchased;

private:
	// variables
	int i = 0;
	int j = 0;
	string readLine = "";	
	vector<string> itemCounts;
};

#endif
