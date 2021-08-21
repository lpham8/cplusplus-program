/*
* CS-210 project 3
* Author: Long Pham
* date: 8/14/21
*/

#include <Python.h>
#include <iostream>
#include <iomanip>
#include <Windows.h>
#include <cmath>
#include <string>
#include <fstream>
#include <sstream>
#include "UserInputs.h"
#include "ItemsPurchased.h"

using namespace std;



/*
Description:
	To call this function, simply pass the function name in Python that you wish to call.
Example:
	callProcedure("printsomething");
Output:
	Python will print on the screen: Hello from python!
Return:
	None
*/
void CallProcedure(string pName)
{
	char* procname = new char[pName.length() + 1];
	std::strcpy(procname, pName.c_str());

	Py_Initialize();
	PyObject* my_module = PyImport_ImportModule("PythonCode");
	PyErr_Print();
	PyObject* my_function = PyObject_GetAttrString(my_module, procname);
	PyObject* my_result = PyObject_CallObject(my_function, NULL);
	Py_Finalize();

	delete[] procname;
}

/*
Description:
	To call this function, pass the name of the Python functino you wish to call and the string parameter you want to send
Example:
	int x = callIntFunc("PrintMe","Test");
Output:
	Python will print on the screen:
		You sent me: Test
Return:
	100 is returned to the C++
*/
int callIntFunc(string proc, string param)
{
	char* procname = new char[proc.length() + 1];
	std::strcpy(procname, proc.c_str());

	char* paramval = new char[param.length() + 1];
	std::strcpy(paramval, param.c_str());


	PyObject* pName, * pModule, * pDict, * pFunc, * pValue = nullptr, * presult = nullptr;
	// Initialize the Python Interpreter
	Py_Initialize();
	// Build the name object
	pName = PyUnicode_FromString((char*)"PythonCode");
	// Load the module object
	pModule = PyImport_Import(pName);
	// pDict is a borrowed reference 
	pDict = PyModule_GetDict(pModule);
	// pFunc is also a borrowed reference 
	pFunc = PyDict_GetItemString(pDict, procname);
	if (PyCallable_Check(pFunc))
	{
		pValue = Py_BuildValue("(z)", paramval);
		PyErr_Print();
		presult = PyObject_CallObject(pFunc, pValue);
		PyErr_Print();
	}
	else
	{
		PyErr_Print();
	}
	//printf("Result is %d\n", _PyLong_AsInt(presult));
	Py_DECREF(pValue);
	// Clean up
	Py_DECREF(pModule);
	Py_DECREF(pName);
	// Finish the Python Interpreter
	Py_Finalize();

	// clean 
	delete[] procname;
	delete[] paramval;


	return _PyLong_AsInt(presult);
}

/*
Description:
	To call this function, pass the name of the Python functino you wish to call and the string parameter you want to send
Example:
	int x = callIntFunc("doublevalue",5);
Return:
	25 is returned to the C++
*/
int callIntFunc(string proc, int param)
{
	char* procname = new char[proc.length() + 1];
	std::strcpy(procname, proc.c_str());

	PyObject* pName, * pModule, * pDict, * pFunc, * pValue = nullptr, * presult = nullptr;
	// Initialize the Python Interpreter
	Py_Initialize();
	// Build the name object
	pName = PyUnicode_FromString((char*)"PythonCode");
	// Load the module object
	pModule = PyImport_Import(pName);
	// pDict is a borrowed reference 
	pDict = PyModule_GetDict(pModule);
	// pFunc is also a borrowed reference 
	pFunc = PyDict_GetItemString(pDict, procname);
	if (PyCallable_Check(pFunc))
	{
		pValue = Py_BuildValue("(i)", param);
		PyErr_Print();
		presult = PyObject_CallObject(pFunc, pValue);
		PyErr_Print();
	}
	else
	{
		PyErr_Print();
	}
	//printf("Result is %d\n", _PyLong_AsInt(presult));
	Py_DECREF(pValue);
	// Clean up
	Py_DECREF(pModule);
	Py_DECREF(pName);
	// Finish the Python Interpreter
	Py_Finalize();

	// clean 
	delete[] procname;

	return _PyLong_AsInt(presult);
}


int main() {
	// variales 
	bool notDigit = true;
	bool programExit = false;
	int i = 0;
	int count = 0;
	int menuSelect = 0;
	string line = "";
	string itemInput = "";

	// objects for userinputs and itemspurchased
	UserInputs uInputs;
	ItemsPurchased iPurchased;

	// do while loop for looping menu
	do {
		try { // try catch for catching errors and invalid inputs.
			uInputs.DisplayMenu();
			cin >> menuSelect;
			cout << endl;

			switch (menuSelect) { // switch case for menu selection
			case 1:
				cin.clear(); // clear inputs to avoid infinite loop
				cin.ignore(10000, '\n');

				CallProcedure("ItemsPurchased");
				break;

			case 2:
				cin.clear();
				cin.ignore(10000, '\n');

				iPurchased.ReadFile();
				itemInput = uInputs.Option2Input();

				count = callIntFunc("ItemPurchased", itemInput);
				cout << setfill('.') << setw(39) << left << itemInput << count << endl << endl;
				setfill(' ');

				system("pause");
							
				break;

			case 3: { // using brackets to create scope inside case for opening files.
				cin.clear();
				cin.ignore(10000, '\n');

				CallProcedure("Histogram");
				system("pause");

				cout << endl << endl;
				ifstream myFile;
				myFile.open("frequency.dat");
				cout << "Reading from Frequency.dat" << endl << endl;

				// reading from frequency.dat
				if (myFile.is_open()) {

					// loop to iterrate through each character in a line then output
					while (getline(myFile, line)) {
						string word = "";
						for (auto i : line) {
							if (i == ' ') { // after itterating through chars, if space is found print word.
								cout << word << " ";
								word = "";
							}
							else if (isdigit(i)) { // if it is a digit, convert to int and use it for *
								int j = i - 48;
								cout << string(j, '*');
							}
							else {
								word = word + i;
							}
						}
						cout << word << endl;
					}
					cout << endl << endl;
				}

				break;
			}
			case 4: // exit program
				programExit = true;
				break;

			default:
				cin.clear();
				cin.ignore(10000, '\n');

				cout << "Invalid input, please input a number from 1-4." << endl << endl;
				break;

			}
		}
		catch (int myNum) {
			cout << "Invalid input, please input a number from 1-4." << endl << endl;
		}
		catch (runtime_error excpt) {
			cout << "Something went wrong: " << excpt.what() << endl << endl;
		}
	} while (!programExit);

	system("pause");
	exit(0);

	cout << endl << endl;

	system("pause");

	return 0;
}