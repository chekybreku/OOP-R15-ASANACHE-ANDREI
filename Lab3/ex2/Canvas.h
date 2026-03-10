#pragma once

class Canvas
{
private:    
    int coloane, linii;
    char matr[1001][1001];
public:
    void DrawEllipse(int x, int y, int xray, int yray, char ch);
    Canvas(int width, int height);
    void DrawCircle(int x, int y, int ray, char ch);
    void FillCircle(int x, int y, int ray, char ch);
    void DrawRect(int left, int top, int right, int bottom, char ch);
    void FillRect(int left, int top, int right, int bottom, char ch);
    void SetPoint(int x, int y, char ch);
    void DrawLine(int x1, int y1, int x2, int y2, char ch);
    void Print(); // shows what was printed
    void Clear(); // clears the canvas
};