#pragma once
#include <iostream>
#include <cstring>

using namespace std;

class Number
{
private:
	char* value;
	int base;
	// add data members
public:
	Number(const char* value, int base) {
		this->value = new char[30];
		strcpy_s(this->value, strlen(value)+1, value);
		this->base = base;
		cout << value << " " << base << endl;
	} // where base is between 2 and 16
	~Number() {
		delete[] this->value;
	}

	// add operators and copy/move constructor

	void SwitchBase(int newBase);
	void Print();
	int  GetDigitsCount(); // returns the number of digits for the current number
	int  GetBase(); // returns the current base
};
