#include <iostream>
#include "NumberList.h"

using namespace std;

NumberList a;

int main()
{
    int n, x;
    
    a.Init();

    cout << "Introdu 10 nr" << endl;

    for (int i = 0; i < 10; i++)
    {
        cin >> x;
        a.Add(x);
    }

    a.Sort();

    a.Print();

    return 0;
}
