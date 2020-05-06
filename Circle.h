#pragma once
#include <Windows.h>

class Circle {
public:
	Circle();
	void Draw8Points(HDC hdc, int xc, int yc, int a, int b, COLORREF color);
	double getR(int xstart, int ystart, int xend, int yend);
	void CircleDirect(HDC hdc, int xc, int yc, int xe, int ye, COLORREF color);
	void CirclePolar(HDC hdc, int xc, int yc, int xe, int ye, COLORREF color);
	void CircleIterativePolar(HDC hdc, int xc, int yc, int xe, int ye, COLORREF color);
	void CircleFasterBresenham(HDC hdc, int xc, int yc, int xe, int ye, COLORREF color);
};