#include "Circle.h"
#include <math.h>

Circle::Circle() {}
void Circle::Draw8Points(HDC hdc, int xc, int yc, int a, int b, COLORREF color) {
	SetPixel(hdc, xc, yc, color);
	SetPixel(hdc, xc + a, yc + b, color);
	SetPixel(hdc, xc - a, yc + b, color);
	SetPixel(hdc, xc - a, yc - b, color);
	SetPixel(hdc, xc + a, yc - b, color);
	SetPixel(hdc, xc + b, yc + a, color);
	SetPixel(hdc, xc - b, yc + a, color);
	SetPixel(hdc, xc - b, yc - a, color);
	SetPixel(hdc, xc + b, yc - a, color);
}
double Circle::getR(int xstart, int ystart, int xend, int yend) {
	return sqrt(pow(xend - xstart, 2) + pow(yend - ystart, 2));
}
void Circle::CircleDirect(HDC hdc, int xc, int yc, int xe, int ye, COLORREF color) {
	double R = getR(xc, yc, xe, ye);
	int x = 0, y = R;
	int R2 = R*R;
	Draw8Points(hdc, xc, yc, x, y, color);
	while (x<y)
	{
		x++;
		y = round(sqrt((double)(R2 - x*x)));
		Draw8Points(hdc, xc, yc, x, y, color);
	}
}
void Circle::CirclePolar(HDC hdc, int xc, int yc, int xe, int ye, COLORREF color) {
	double R = getR(xc, yc, xe, ye);
	int x = R, y = 0;
	double theta = 0, dtheta = 1.0 / R;
	Draw8Points(hdc, xc, yc, x, y, color);
	while (x>y)
	{
		theta += dtheta;
		x = round(R*cos(theta));
		y = round(R*sin(theta));
		Draw8Points(hdc, xc, yc, x, y, color);
	}
}
void Circle::CircleIterativePolar(HDC hdc, int xc, int yc, int xe, int ye, COLORREF color) {
	double R = getR(xc, yc, xe, ye);
	double x = R, y = 0;
	double dtheta = 1.0 / R;
	double cdtheta = cos(dtheta), sdtheta = sin(dtheta);
	Draw8Points(hdc, xc, yc, R, 0, color);
	while (x>y)
	{
		double x1 = x*cdtheta - y*sdtheta;
		y = x*sdtheta + y*cdtheta;
		x = x1;
		Draw8Points(hdc, xc, yc, round(x), round(y), color);
	}
}
void Circle::CircleFasterBresenham(HDC hdc, int xc, int yc, int xe, int ye, COLORREF color) {
	double R = getR(xc, yc, xe, ye);
	int x = 0, y = R;
	int d = 1 - R;
	int c1 = 3, c2 = 5 - 2 * R;
	Draw8Points(hdc, xc, yc, x, y, color);
	while (x<y)
	{
		if (d<0)
		{
			d += c1;
			c2 += 2;
		}
		else
		{
			d += c2;
			c2 += 4;
			y--;
		}
		c1 += 2;
		x++;
		Draw8Points(hdc, xc, yc, x, y, color);
	}
}
