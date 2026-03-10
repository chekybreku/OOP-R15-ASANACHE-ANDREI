#include "Canvas.h"
#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    Canvas canvas= Canvas(25,45);
   
    canvas.Clear();
    
    canvas.DrawCircle(5, 10,5,'a');

    canvas.FillCircle(5, 10, 5, 'b'); 
    canvas.Print();
    canvas.Clear();

    canvas.DrawRect(1, 2, 5, 10, 'a');
    
    canvas.FillRect(1, 2, 5, 10, 'b');
    canvas.Print();
    canvas.Clear();
    
    canvas.SetPoint(1, 1, 'a');
    canvas.SetPoint(1,15,'a');

    canvas.DrawLine(1,1,1,15,'b');
    canvas.Print();
    canvas.Clear();
    
    return 0;
}