#include "Curve.h"
#include <Windows.h>
#include <math.h>
Vector4::Vector4(double a, double b, double c, double d)
{
	v[0] = a;
	v[1] = b;
	v[2] = c;
	v[3] = d;
}

Vector4::Vector4(double a[])
{
	memcpy(v, a, 4 * sizeof(double));
}

double & Vector4::operator[](int i)
{
	return v[i];
}

Matrix4::Matrix4(double A[])
{
	memcpy(M, A, 16 * sizeof(double));
}

Vector4 & Matrix4::operator[](int i)
{
	return M[i];
}

Vector4 operator*(Matrix4 M, Vector4 & b)
{
	Vector4 res;
	for (int i = 0; i<4; i++) for (int j = 0; j<4; j++) res[i] += M[i][j] * b[j];
	return res;
}

double DotProduct(Vector4 & a, Vector4 & b)
{
	return a[0] * b[0] + a[1] * b[1] + a[2] * b[2] + a[3] * b[3];
}

Vector4 GetHermiteCoeff(double x0, double s0, double x1, double s1)
{
	static double H[16] = { 2,1,-2,1,-3,-2,3,-1,0,1,0,0,1,0,0,0 };
	static Matrix4 basis(H);
	Vector4 v(x0, s0, x1, s1);
	return basis*v;
}

void DrawHermiteCurve(HDC hdc, Vector2 & P0, Vector2 & T0, Vector2 & P1, Vector2 & T1, int numpoints, COLORREF color)
{
	Vector4 xcoeff = GetHermiteCoeff(P0.x, T0.x, P1.x, T1.x);
	Vector4 ycoeff = GetHermiteCoeff(P0.y, T0.y, P1.y, T1.y);
	if (numpoints<2)return;
	double dt = 1.0 / (numpoints - 1);
	for (double t = 0; t <= 1; t += dt)
	{
		Vector4 vt;
		vt[3] = 1;
		for (int i = 2; i >= 0; i--)vt[i] = vt[i + 1] * t;
		int x = round(DotProduct(xcoeff, vt));
		int y = round(DotProduct(ycoeff, vt));
		SetPixel(hdc, x, y, color);
	}
}

void DrawBezierCurve(HDC hdc, Vector2 & P0, Vector2 & P1, Vector2 & P2, Vector2 & P3, int numpoints, COLORREF color)
{
	Vector2 T0(3 * (P1.x - P0.x), 3 * (P1.y - P0.y));
	Vector2 T1(3 * (P3.x - P2.x), 3 * (P3.y - P2.y));
	DrawHermiteCurve(hdc, P0, T0, P3, T1, numpoints, color);
}

void FirstDegree(HDC hdc, int xs, int ys, int xe, int ye, COLORREF color) {
	double dt = 0.0001;
	for (double t = 0; t <= 1; t += dt) {
		double x = (xe - xs)* t + xs;
		double y = (ye - ys) * t + ys;
		SetPixel(hdc, round(x), round(y), color);

	}

}

void drawSecondDegreeCurveUsingMiddlePoint(HDC hdc, int xs, int ys, int xm, int ym, int xe, int ye, COLORREF color) {
	double alpha1 = 2 * xe - 4 * xm + 2 * xs;
	double alpha2 = 2 * ye - 4 * ym + 2 * ys;
	double beta1 = 4 * xm - xe - 3 * xs;
	double beta2 = 4 * ym - ye - 3 * ys;
	double gamma1 = xs;
	double gamma2 = ys;
	double x, y;
	for (double t = 0; t < 1; t += 0.001) {
		x = alpha1 * pow(t, 2) + beta1 * t + gamma1;
		y = alpha2 * pow(t, 2) + beta2 * t + gamma2;
		SetPixel(hdc, round(x), round(y), color);
	}
}

void DrawCardinalSpline(HDC hdc, Vector2 P[], int n, double c, int numpix,COLORREF color)
{
	double c1 = 1 - c;
	Vector2 T0(c1*(P[2].x - P[0].x), c1*(P[2].y - P[0].y));
	for (int i = 2; i<n - 1; i++)
	{
		Vector2 T1(c1*(P[i + 1].x - P[i - 1].x), c1*(P[i + 1].y - P[i - 1].y));
		DrawHermiteCurve(hdc, P[i - 1], T0, P[i], T1, numpix,color);
		T0 = T1;
	}
}
