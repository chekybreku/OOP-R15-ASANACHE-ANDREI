#include "NumberList.h"
#include <iostream>
#include <cstring>


using namespace std;

void NumberList::Init()
{
	this->count = 0;
}

bool NumberList::Add(int x)
{
	if (this->count == 10) return 0;

	this->numbers[count] = x;
	this->count++;
		
	return 1;
}

void NumberList::Sort()
{
	int i,j;
	for(i=0;i<this->count-1;i++)
		for(j=i+1;j<this->count;j++)
			if (this->numbers[i] > this->numbers[j])
			{
				int aux= this->numbers[i];
				this->numbers[i] = this->numbers[j];
				this->numbers[j] = aux;
			}
}

void NumberList::Print()
{
	for (int i = 0; i < this->count; i++)
		cout << this->numbers[i] << " ";
	cout << endl;
}