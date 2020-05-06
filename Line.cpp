#include "Line.h"
#include <Windows.h>
#include <math.h>

Line::Line() {}
void Line::swap(double &x1, double &x2, double &y1, double &y2) {
	double temp = x1,temp2=y1;
	x1 = x2;
	x2 = temp;
	y1 = y2;
	y2 = temp2;
}
void Line::parametric_line(HDC hdc, double x1, double y1, double x2, double y2, COLORREF color) {
	double x = x1;
	double y = y1;
	double ro = 0;
	double dx = (x2 - x1);
	double dy = (y2 - y1);
	double delta = 1.0 / (max(abs((int)dx), abs((int)dy)));
	do
	{
		SetPixel(hdc, (int)(x), (int)(y), color);
		ro += delta;
		x = (x1 + (ro*dx));
		y = (y1 + (ro*dy));
	} while (ro <= 1);
}
void Line::DirectLine(HDC hdc, double x1, double y1, double x2, double y2, COLORREF color) {
	double dx = x2 - x1;
	double dy = y2 - y1;
	if (abs((int)dy) <= abs((int)dx))
	{
		double slope = (double)dy / dx;
		if (x1>x2)
		{
			swap(x1, x2, y1, y2);
		}
		for (double x = x1; x <= x2; x++)
		{
			double y = round(y1 + (x - x1)*slope);
			SetPixel(hdc,(int)x,(int)y, color);
		}
	}
	else
	{
		double islope = (double)dx / dy;
		if (y1>y2)
		{
			swap(x1, y1, x2, y2);
		}
		for (double y = y1; y <= y2; y++)
		{
			double x = round(x1 + (y - y1)*islope);
			SetPixel(hdc, (int)x, (int)y, color);
		}
	}
}
void Line::SimpleDDA(HDC hdc, double xs, double ys, double xe, double ye, COLORREF color) {
	int dx = xe - xs;
	int dy = ye - ys;
	SetPixel(hdc, xs, ys, color);
	if (abs(dx) >= abs(dy))
	{
		int x = xs, xinc = dx>0 ? 1 : -1;
		double y = ys, yinc = (double)dy / dx*xinc;
		while (x != xe)
		{
			x += xinc;
			y += yinc;
			SetPixel(hdc, x, round(y), color);
		}
	}
	else
	{
		int y = ys, yinc = dy>0 ? 1 : -1;
		double x = xs, xinc = (double)dx / dy*yinc;
		while (y != ye)
		{
			x += xinc;
			y += yinc;
			SetPixel(hdc, round(x), y, color);
		}
	}
}
void Line::midpoint(HDC hdc, double x1, double y1, double x2, double y2, COLORREF color) {
	int dx = x2 - x1;
	int dy = y2 - y1;
	int d = 0;
	int change1 = 0, change2 = 0, incx = 0, incy = 0;
	int x = 0;
	int y = 0;
	if (abs(dy) <= abs(dx))
	{
		if (dx < 0)
		{
			swap(x1, x2, y1, y2);
			dx = -dx;
			dy = -dy;
		}
		d = dx - (2 * abs(dy));
		change1 = 2 * (dx - abs(dy));
		change2 = -2 * (abs(dy));
		incy = dy >= 0 ? 1 : -1;
		x = x1;
		y = y1;
		SetPixel(hdc, x, y, color);
		while (x < x2)
		{
			if (d < 0)
			{
				d = d + change1;
				y = y + incy;
			}
			else
				d = d + change2;
			x++;
			SetPixel(hdc, x, y, color);
		}
	}
	else
	{
		if (dy < 0)
		{
			swap(x1, y1, x2, y2);
			dx = -dx;
			dy = -dy;
		}
		d = (2 * abs(dx)) - dy;
		change1 = 2 * (abs(dx) - dy);
		change2 = 2 * abs(dx);
		incx = dx > 0 ? 1 : -1;
		x = x1;
		y = y1;
		SetPixel(hdc, x, y, color);
		while (y < y2)
		{
			if (d > 0)
			{
				d = d + change1;
				x = x + incx;
			}
			else
				d = d + change2;
			y++;
			SetPixel(hdc, x, y, color);
		}
	}
}
