#pragma once
#include <windows.h>

class Line {
public:
	Line();
	void swap(double &x1, double &x2, double &y1, double &y2);
	void parametric_line(HDC hdc, double x1, double y1, double x2, double y2, COLORREF color);
	void DirectLine(HDC hdc, double x1, double y1, double x2, double y2, COLORREF color);
	void SimpleDDA(HDC hdc, double xs, double ys, double xe, double ye, COLORREF color);
	void midpoint(HDC hdc, double x1, double y1, double x2, double y2, COLORREF color);
};