#include <iostream>
#include "Math.h"

using namespace std;

int main()
{
    int x=1, y=2, z=3;
    double a = 1.2, b = 2.3, c = 3.4;
    const char* s1 = "Andrei";
    const char* s2 = "Ardei";


    cout << Math::Add(x, y) << endl;
    cout << Math::Add(x,y,z)<<endl;
    

    cout<< Math::Add(a,b)<<endl;
    cout << Math::Add(a,b,c) << endl;

    cout << Math::Mul(x,y) << endl;
    cout << Math::Mul(x, y, z) << endl;

    cout << Math::Mul(a, b) << endl;
    cout << Math::Mul(a, b, c) << endl;

    cout << Math::Mul(a, b, c) << endl;
    cout << Math::Mul(a, b) << endl;


    cout << Math::Add(3,x,y,z) << endl;
    cout << Math::Add(s1, s2) << endl;
  

    return 0;
}
