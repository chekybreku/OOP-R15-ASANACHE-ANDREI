#include "Canvas.h"
#include <iostream>
#include <cstring>
#include <cmath>
#include <print>

using namespace std;

Canvas::Canvas(int height, int width) {
	this->linii = height;
	this->coloane = width;
	for (int i = 0; i < this->linii; i++)
	{
		for (int j = 0; j < this->coloane; j++)
			this->matr[i][j] = ' ';
	}
}
void Canvas::DrawCircle(int x_centre, int y_centre, int ray, char ch) {
    int x = ray, y = 0;
    matr[x + x_centre][y + y_centre]=ch;
   
    if (ray > 0)
    {
        matr[x_centre][y_centre - ray] = ch;
        matr[x_centre - ray][y_centre] = ch;
        matr[x + x_centre][-y + y_centre] = ch;
        matr[y + x_centre][x + y_centre] = ch;
        matr[-y + x_centre][x + y_centre] = ch;
    }

    int P = 1 - ray;
    while (x > y)
    {
        y++;

        if (P <= 0)
            P = P + 2 * y + 1;
        else
        {
            x--;
            P = P + 2 * y - 2 * x + 1;
        }

        if (x < y)
            break;

        matr[x + x_centre][y + y_centre] = ch;
        matr[-x + x_centre][y + y_centre] = ch;
        matr[x + x_centre][-y + y_centre] = ch;
        matr[-x + x_centre][-y + y_centre] = ch;

        if (x != y)
        {
            matr[y + x_centre][x + y_centre] = ch;
            matr[-y + x_centre][x + y_centre] = ch;
            matr[y + x_centre][-x + y_centre] = ch;
            matr[-y + x_centre][-x + y_centre] = ch;
        }
    }

}

void Canvas::DrawEllipse(int x, int y, int xray, int yray, char ch) {
    double rad = 0;
    const double rad_rate = 3.14 / 720.0;

    while (rad <= 3.14 * 2.0) {
        double x2d = std::cos(rad);
        double y2d = std::sin(rad);

        int x2 = x2d * xray;
        int y2 = y2d * yray;

        matr[x+x2][y+y2] = ch;

        rad += rad_rate;
    }
}

void Canvas::FillCircle(int x, int y, int ray, char ch) {
    for (double i = ray; i > 0.0; i -= 0.5) {
            DrawEllipse(x, y, i * 2, i, ch);
        }
}

void Canvas::DrawRect(int left, int top, int right, int bottom, char ch) {//1 2 5 10
    for (int i = left; i <=right; i++)
    {
        matr[top][i] = ch;
        matr[bottom][i] = ch;
    }
        
    for (int i = top; i <=bottom; i++)
    {
        matr[i][left] = ch;
        matr[i][right] = ch;
    }
   
}
void Canvas::FillRect(int left, int top, int right, int bottom, char ch) {//
    for(int i=top+1;i<bottom;i++)
        for (int j = left + 1; j <right; j++)
        {
            matr[i][j] = ch;
        }
}
void Canvas::SetPoint(int x, int y, char ch) {
    matr[x][y] = ch;
}
void Canvas::DrawLine(int x1, int y1, int x2, int y2, char ch) {
    if (x1 == x2 && y1 == y2) return;
    if (x1 == x2) {
        if (y1 > y2) swap(y1, y2);
        y2 = min(y2, linii);
        y1 = max(y1, 0);

        for (int y = y1; y < y2; y++) {
            SetPoint(x1, y, ch);
        }
    }
    else if (y1 == y2) {
        if (x1 > x2) swap(x1, x2);
        x2 = min(x2, linii);
        x1 = max(x1, 0);

        for (int x = x1; x < x2; x++) {
            SetPoint(x, y1, ch);
        }
    }
    else {
        int dx = x2 - x1;
        int dy = y2 - y1;
        int x = x1;
        int y = y1;

        if (dx >= dy) {
            double slope = (double)dy / (double)dx;
            double acc = slope - 1;
            while (x < x2 && y <= y2) {
                SetPoint(x, y, ch);
                x++;

                acc += slope;

                if (acc >= 0.5) {
                    y++;
                    acc -= 1.0;
                }
            }
        }
        else {
            double slope = (double)dx / (double)dy;
            double acc = slope - 1;
            while (x <= x2 && y < y2) {
                SetPoint(x, y, ch);
                y++;

                acc += slope;

                if (acc >= 0.5) {
                    x++;
                    acc -= 1.0;
                }
            }
        }


    }
    matr[x2][y2] = ch;
}
void Canvas::Print() // shows what was printed
{
	for (int i = 0; i < this->linii; i++)
	{
		for (int j = 0; j < this->coloane; j++)
			cout<<this->matr[i][j];
		cout << endl;
	}
}
void Canvas::Clear() // clears the canvas
{
	for (int i = 0; i < this->linii; i++)
	{
		for (int j = 0; j < this->coloane; j++)
			this->matr[i][j] = ' ';
	}
}