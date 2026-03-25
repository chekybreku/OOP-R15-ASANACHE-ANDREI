#include <iostream>
#include "Number.h"

using namespace std;
int main()
{
    Number num1("ACA", 16);

    num1.Print();

    num1.SwitchBase(10);
    num1.Print();
    return 0;
}
