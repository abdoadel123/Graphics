#pragma once
#include <Windows.h>
#include <math.h>
struct Vector2
{
	double x, y;
	Vector2(double a = 0, double b = 0)
	{
		x = a;
		y = b;
	}
};
class Vector4
{
	double v[4];
public:
	Vector4(double a = 0, double b = 0, double c = 0, double d = 0);
	Vector4(double a[]);
	double& operator[](int i);
	
};
class Matrix4
{
	Vector4 M[4];
public:
	Matrix4(double A[]);
	Vector4& operator[](int i);
};
Vector4 operator*(Matrix4 M, Vector4& b); // right multiplication of M by b

double DotProduct(Vector4& a, Vector4& b); //multiplying a raw vector by a column vector

Vector4 GetHermiteCoeff(double x0, double s0, double x1, double s1);

void DrawHermiteCurve(HDC hdc, Vector2& P0, Vector2& T0, Vector2& P1, Vector2& T1, int numpoints,COLORREF color);

void DrawBezierCurve(HDC hdc, Vector2& P0, Vector2& P1, Vector2& P2, Vector2& P3, int numpoints, COLORREF color);

void FirstDegree(HDC hdc, int xs, int ys, int xe, int ye, COLORREF color);

void drawSecondDegreeCurveUsingMiddlePoint(HDC hdc, int xs, int ys, int xm, int ym, int xe, int ye, COLORREF color);

void DrawCardinalSpline(HDC hdc, Vector2 P[], int n, double c, int numpix, COLORREF color);
