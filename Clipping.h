#pragma once
#include "Line.h"
union OutCode
{
	unsigned All : 4;
	struct { unsigned left : 1, top : 1, right : 1, bottom : 1; };
};
OutCode GetOutCode(double x, double y, int xleft, int ytop, int xright, int ybottom);

void VIntersect(double xs, double ys, double xe, double ye, int x, double *xi, double *yi);

void HIntersect(double xs, double ys, double xe, double ye, int y, double *xi, double *yi);

void PointClipping(HDC hdc, int x, int y, int xleft, int ytop, int xright, int ybottom, COLORREF color);

void CohenSuth(HDC hdc, int xs, int ys, int xe, int ye, int xleft, int ytop, int xright, int ybottom, COLORREF color);