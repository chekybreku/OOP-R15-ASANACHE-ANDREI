#include <iostream>
#include <cstring>
#include "Number.h"

using namespace std;

int Number::GetBase()
{
	return this->base;
}
int Number::GetDigitsCount()
{
	return strlen(this->value);
}
void Number::Print()
{
	cout << "Base: " << base << endl << "Value: " << value << endl << "Nr of digits: " << GetDigitsCount() << endl;
}
void Number::SwitchBase(int newbase)
{	
	//to base 10
	int i, n = GetDigitsCount()-1,m=0,ok=0;
	int j = 1;//power of the base

	// nr base 10 = digit n * current_base^n + ... + digit n * current_base^0

	for (i = n; i >= 0; i--)
	{
		int x;
		if (value[i] >= '0' && value[i] <= '9')
			x = value[i] - '0';
		else if (value[i] >= 'A' && value[i] <= 'F')
			x = value[i]-'A'+10;
		else {
			ok = 1;
			cout << "Invalid number\n";
			break;
		}
		
		m = m + x*j;
		j = j * this->base;
	}
	

	//from base 10 to base newbase
	
	//It's a repeated division of m by new base till it's m=0
	//the number m in new base is the vector of remainders of the above division inversed
	//I will just pass thru this vector from back to front
	if (ok == 0)
	{
		int v[30];
		for (i = 0; m != 0; i++)
		{
			v[i] = m % newbase;
			m /= newbase;
		}
		n = i;

		delete[] this->value;
		this->value = new char[n + 1];

		this->base = newbase;

		for (i = n - 1; i >= 0; i--)
		{
			if (v[i] >= 0 && v[i] < 10)
				this->value[n - 1 - i] = '0' + v[i];
			else if (v[i] >= 10 && v[i] <= 15)
				this->value[n - 1 - i] = 'A' + v[i] - 10;
		}
		this->value[n] = '\0';
	}
}