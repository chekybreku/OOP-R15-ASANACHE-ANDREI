#include <iostream>
#include "Math.h"
#include <cstring>
#include <cstdlib>
#include <cstdarg>
using namespace std;

 int Math::Add(int x, int y) {
	return x+y;
}

 int Math::Add(int x, int y, int z) {
	return x+y+z;
}

int Math::Add(double a, double b) {
	return (int)(a+b);
}

int Math::Add(double a, double b, double c) {
	return (int)(a+b+c);
}

int Math::Mul(int x, int y) {
	return (x*y);
}

int Math::Mul(int x, int y, int z) {
	return (x*y*z);
}

int Math::Mul(double a, double b) {
	return (int)(a*b);
}

int Math::Mul(double a, double b, double c) {
	return (int)(a * b * c);
}

int Math::Add(int count, ...) // sums up a list of integers
{
	va_list args;
	va_start(args,count);

	int sum = 0;
	for (int i = 0; i < count; i++)
		sum += va_arg(args,int);
	return sum;
}

char* Math::Add(const char* s1, const char* s2) {

	if (s1 == nullptr || s2 == nullptr)
		return nullptr;

	int len1 = strlen(s1);
	int len2 = strlen(s2);

	int len3 = len1 + len2;
	char* rez = new char[len3 + 1];

	rez[len3] = '\0';

	for (int i = 0; i < len1; i++)
		rez[i] = s1[i];
	for (int i = 0; i < len2; i++)
		rez[i+len1] = s2[i];
	
	return rez;
}
