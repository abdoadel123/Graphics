#include <windows.h>
#include "resource.h"
#include <tchar.h>
#include <wchar.h>
#include "commdlg.h"
#include <string>
#include <math.h>
#include <stdio.h>
#include "Resource.h"
#include "Line.h"
#include "Circle.h"
#include "Curve.h"
#include "Clipping.h"
#include "File.h"
#include "Filling.h"
#include <vector>

using namespace std;

int counter1 = 0,algo = 0;
double x11 = 0, x22 = 0,x33=0,x44=0, y11 = 0, y22 = 0,y33=0,y44=0;
int yT,xR, xL, yB;
point poi;
vector <point> poin;
vector <int> file;
COLORREF color = RGB(0, 0, 255);

LRESULT WINAPI MyWindowProc(HWND hwnd, UINT m, WPARAM wp, LPARAM lp)
{
	Line line;
	Circle circle;
	Vector2 P0, P1, T0, T1;
	PAINTSTRUCT p;
	switch (m)
	{
	case WM_PAINT:
		if (counter1 == 4)
		{
			BeginPaint(hwnd, &p);
			if (algo == 2) {
				poi.algo = 2;
				poi.x1 = x11;
				poi.x2 = x22;
				poi.x3 = x33;
				poi.x4 = x44;
				poi.y1 = y11;
				poi.y2 = y22;
				poi.y3 = y33;
				poi.y4 = y44;
				poin.push_back(poi);
				file.push_back(1);
				line.parametric_line(p.hdc, x11, y11, x22, y22, color);
			}
			else if (algo == 1) {
				poi.algo = 1;
				poi.x1 = x11;
				poi.x2 = x22;
				poi.x3 = x33;
				poi.x4 = x44;
				poi.y1 = y11;
				poi.y2 = y22;
				poi.y3 = y33;
				poi.y4 = y44;
				poin.push_back(poi);
				file.push_back(1);
				line.DirectLine(p.hdc, x11, y11, x22, y22, color);
			}
			else if (algo == 3) {
				poi.algo = 3;
				poi.x1 = x11;
				poi.x2 = x22;
				poi.x3 = x33;
				poi.x4 = x44;
				poi.y1 = y11;
				poi.y2 = y22;
				poi.y3 = y33;
				poi.y4 = y44;
				poin.push_back(poi);
				file.push_back(1);
				line.SimpleDDA(p.hdc, x11, y11, x22, y22, color);
			}
			else if (algo == 4) {
				poi.algo = 4;
				poi.x1 = x11;
				poi.x2 = x22;
				poi.x3 = x33;
				poi.x4 = x44;
				poi.y1 = y11;
				poi.y2 = y22;
				poi.y3 = y33;
				poi.y4 = y44;
				poin.push_back(poi);
				file.push_back(1);
				line.midpoint(p.hdc, x11, y11, x22, y22, color);
			}
			else if (algo == 5) {
				poi.algo = 5;
				poi.x1 = x11;
				poi.x2 = x22;
				poi.x3 = x33;
				poi.x4 = x44;
				poi.y1 = y11;
				poi.y2 = y22;
				poi.y3 = y33;
				poi.y4 = y44;
				poin.push_back(poi);
				file.push_back(2);
				circle.CircleDirect(p.hdc, x11, y11, x22, y22, color);
			}
			else if (algo == 6) {
				poi.algo = 6;
				poi.x1 = x11;
				poi.x2 = x22;
				poi.x3 = x33;
				poi.x4 = x44;
				poi.y1 = y11;
				poi.y2 = y22;
				poi.y3 = y33;
				poi.y4 = y44;
				poin.push_back(poi);
				file.push_back(2);
				circle.CirclePolar(p.hdc, x11, y11, x22, y22, color);
			}
			else if (algo == 7) {
				poi.algo = 7;
				poi.x1 = x11;
				poi.x2 = x22;
				poi.x3 = x33;
				poi.x4 = x44;
				poi.y1 = y11;
				poi.y2 = y22;
				poi.y3 = y33;
				poi.y4 = y44;
				poin.push_back(poi);
				file.push_back(2);
				circle.CircleIterativePolar(p.hdc, x11, y11, x22, y22, color);
			}
			else if (algo == 8) {
				poi.algo = 8;
				poi.x1 = x11;
				poi.x2 = x22;
				poi.x3 = x33;
				poi.x4 = x44;
				poi.y1 = y11;
				poi.y2 = y22;
				poi.y3 = y33;
				poi.y4 = y44;
				poin.push_back(poi);
				file.push_back(2);
				circle.CircleFasterBresenham(p.hdc, x11, y11, x22, y22, color);
			}
			else if (algo == 9) {
				poi.algo = 9;
				poi.x1 = x11;
				poi.x2 = x22;
				poi.y1 = y11;
				poi.y2 = y22;
				poin.push_back(poi);
				file.push_back(3);
				FirstDegree(p.hdc, x11, y11, x22, y22, color);
			}
			else if (algo == 10) {
				poi.algo = 10;
				poi.x1 = x11;
				poi.x2 = x22;
				poi.y1 = y11;
				poi.y2 = y22;
				poi.x3 = x33;
				poi.y3 = y33;
				poin.push_back(poi);
				file.push_back(3);
				drawSecondDegreeCurveUsingMiddlePoint(p.hdc,x11,y11,x22,y22,x33,y33,color);
			}
			else if (algo == 11) {
				P0.x = x11;
				P0.y = y11;
				T0.x = x22;
				T0.y = y22;
				P1.x = x33;
				P1.y = y33;
				T1.x = x44;
				T1.y = y44;
				poi.algo = 11;
				poi.x1 = x11;
				poi.x2 = x22;
				poi.x3 = x33;
				poi.x4 = x44;
				poi.y1 = y11;
				poi.y2 = y22;
				poi.y3 = y33;
				poi.y4 = y44;
				poin.push_back(poi);
				file.push_back(3);
				DrawHermiteCurve(p.hdc, P0, T0, P1, T1, 1400,color);
			}
			else if (algo == 12) {
				P0.x = x11;
				P0.y = y11;
				T0.x = x22;
				T0.y = y22;
				P1.x = x33;
				P1.y = y33;
				T1.x = x44;
				T1.y = y44;
				poi.algo = 12;
				poi.x1 = x11;
				poi.x2 = x22;
				poi.x3 = x33;
				poi.x4 = x44;
				poi.y1 = y11;
				poi.y2 = y22;
				poi.y3 = y33;
				poi.y4 = y44;
				poin.push_back(poi);
				file.push_back(3);
				DrawBezierCurve(p.hdc, P0, T0, P1, T1, 1400, color);
			}
			else if (algo == 13) {
				line.DirectLine(p.hdc, x11, y11, x22, y11, color);//--
				line.DirectLine(p.hdc, x11, y11, x11, y22, color);//|__
				line.DirectLine(p.hdc, x11, y22, x22, y22, color);//__
				line.DirectLine(p.hdc, x22, y11, x22, y22, color);
				yT = y11;
				xR = x22;
				xL = x11;
				yB = y22;
				poi.algo = 13;
				poi.x1 = x11;
				poi.x2 = x22;
				poi.x3 = xL;
				poi.x4 = xR;
				poi.y1 = y11;
				poi.y2 = y22;
				poi.y3 = yT;
				poi.y4 = yB;
				poin.push_back(poi);
				file.push_back(4);
				CohenSuth(p.hdc, x33, y33, x44, y44, xL, yT, xR, yB, color);
			}
			else if (algo == 14) {
				poi.algo = 14;
				poi.x1 = x11;
				poi.x3 = xL;
				poi.x4 = xR;
				poi.y1 = y11;
				poi.y3 = yT;
				poi.y4 = yB;
				poin.push_back(poi);
				file.push_back(4);
				PointClipping(p.hdc, x11, y11, xL, yT, xR, yB, color);
			}
			else if (algo == 15) {
				POINT pi[4];
				pi[0].x = x11;
				pi[1].x = x22;
				pi[2].x = x33;
				pi[3].x = x44;
				pi[0].y = y11;
				pi[1].y = y22;
				pi[2].y = y33;
				pi[3].y = y44;
				poi.algo = 15;
				poi.x1 = x11;
				poi.x2 = x22;
				poi.y1 = y11;
				poi.y2 = y22;
				poi.x3 = x33;
				poi.x4 = x44;
				poi.y3 = y33;
				poi.y4 = y44;
				poin.push_back(poi);
				file.push_back(5);
				ConvexFill(p.hdc,pi,4,color);
			}
			else if (algo == 16) {
				Vector2 vec[4];
				vec[0].x = x11;
				vec[1].x = x22;
				vec[2].x = x33;
				vec[3].x = x44;
				vec[0].y = y11;
				vec[1].y = y22;
				vec[2].y = y33;
				vec[3].y = y44;
				poi.algo = 16;
				poi.x1 = x11;
				poi.x2 = x22;
				poi.x3 = x33;
				poi.x4 = x44;
				poi.y1 = y11;
				poi.y2 = y22;
				poi.y3 = y33;
				poi.y4 = y44;
				poin.push_back(poi);
				file.push_back(3);
				DrawCardinalSpline(p.hdc,vec,4,.1, 10000, color);
			}
			counter1 = 0;
			EndPaint(hwnd, &p);
		}
		break;
	case WM_LBUTTONDOWN:
		if (counter1 == 0) {
			x11 = LOWORD(lp);
			y11 = HIWORD(lp);
			counter1++;
			if (algo == 14) {
				counter1 += 3;
				EndPaint(hwnd, &p);
				InvalidateRect(hwnd, NULL, false);
			}
		}
		else if (counter1 == 1) {
			x22 = LOWORD(lp);
			y22 = HIWORD(lp);
			counter1++;
			if (algo <= 9) {
				counter1 += 2;
				EndPaint(hwnd, &p);
				InvalidateRect(hwnd, NULL, false);
			}
		}
		else if (counter1 == 2) {
			x33 = LOWORD(lp);
			y33 = HIWORD(lp);
			counter1++;
			if (algo ==10) {
				counter1 += 1;
				EndPaint(hwnd, &p);
				InvalidateRect(hwnd, NULL, false);
			}
		}
		else if (counter1 == 3) {
			x44 = LOWORD(lp);
			y44 = HIWORD(lp);
			counter1++;
			//EndPaint(hwnd, &p);
			InvalidateRect(hwnd, NULL, false);
		}
		break;
	case WM_CREATE:
	{
		HMENU hMenubar = CreateMenu();
		HMENU hFile = CreateMenu();
		HMENU hLine = CreateMenu();
		HMENU hCircle = CreateMenu();
		HMENU hEllipse = CreateMenu();
		HMENU hCurve = CreateMenu();
		HMENU hLineClip = CreateMenu();
		HMENU hPointClip = CreateMenu();
		HMENU hFilling = CreateMenu();
		HMENU hColor = CreateMenu();
		//HMENU hEdit = CreateMenu();

		AppendMenu(hMenubar, MF_POPUP, (UINT_PTR)hFile, "File");
		AppendMenu(hFile, MF_STRING,ID_Load, "Load");
		AppendMenu(hFile, MF_STRING,ID_Save, "Save");
		AppendMenu(hFile, MF_STRING, ID_CLEAR, "Clear");
		AppendMenu(hFile, MF_STRING, ID_EXIT, "Exit");

		AppendMenu(hMenubar, MF_POPUP, (UINT_PTR)hLine, "line");
		AppendMenu(hLine, MF_STRING, ID_LineCar, "Direct");
		AppendMenu(hLine, MF_STRING, ID_LinePara, "parametric");
		AppendMenu(hLine, MF_STRING, ID_LineDDA, "DDA");
		AppendMenu(hLine, MF_STRING, ID_LineMidPoint, "MidPoint");

		AppendMenu(hMenubar, MF_POPUP, (UINT_PTR)hCircle, "Circle");
		AppendMenu(hCircle, MF_STRING, ID_Direct_circle, "Cartesian");
		AppendMenu(hCircle, MF_STRING, ID_Polar_circle, "Polar");
		AppendMenu(hCircle, MF_STRING, ID_IterativePolar_circle, "IterativePolar");
		AppendMenu(hCircle, MF_STRING, ID_FasterBresenham_circle, "FasterBresenham");

		AppendMenu(hMenubar, MF_POPUP, (UINT_PTR)hCurve, "Curve");
		AppendMenu(hCurve, MF_STRING, ID_lenearCurve, "First Degree");
		AppendMenu(hCurve, MF_STRING, ID_SecondCurve, "Second Degree");
		AppendMenu(hCurve, MF_STRING, ID_HermiteCurve, "Hermite");
		AppendMenu(hCurve, MF_STRING, ID_BezierCurve, "Bezier");
		AppendMenu(hCurve, MF_STRING, ID_SplineCurve, "Spline");

		AppendMenu(hMenubar, MF_POPUP, (UINT_PTR)hFilling, "Filling");
		AppendMenu(hFilling, MF_STRING, ID_Filling, "Firest Case");

		AppendMenu(hMenubar, MF_POPUP, (UINT_PTR)hLineClip, "Line Clipping");
		AppendMenu(hLineClip, MF_STRING, ID_LineclipingRecatngle, "Rectangle");

		AppendMenu(hMenubar,MF_POPUP, (UINT_PTR)hPointClip, "Point Clipping");
		AppendMenu(hPointClip, MF_STRING, ID_PointclipingRecatngle, "Rectangle");

		AppendMenu(hMenubar, MF_POPUP,(UINT_PTR)hColor, "Color");
		AppendMenu(hColor, MF_STRING, ID_COLORWin, "Background");
		AppendMenu(hColor, MF_STRING, ID_COLORTEX, "Text");

		SetMenu(hwnd, hMenubar);
		break;
	}
	case WM_COMMAND:
	{
		if (LOWORD(wp) == ID_LineCar)
			algo = 1;
		else if (LOWORD(wp) == ID_LinePara)
			algo = 2;
		else if (LOWORD(wp) == ID_LineDDA)
			algo = 3;
		else if (LOWORD(wp) == ID_LineMidPoint)
			algo = 4;
		else if (LOWORD(wp) == ID_Direct_circle)
			algo = 5;
		else if (LOWORD(wp) == ID_Polar_circle)
			algo = 6;
		else if (LOWORD(wp) == ID_IterativePolar_circle)
			algo = 7;
		else if (LOWORD(wp) == ID_FasterBresenham_circle)
			algo = 8;
		else if (LOWORD(wp) == ID_lenearCurve)
			algo = 9;
		else if (LOWORD(wp) == ID_SecondCurve)
			algo = 10;
		else if (LOWORD(wp) == ID_HermiteCurve)
			algo = 11;
		else if (LOWORD(wp) == ID_BezierCurve)
			algo = 12;
		else if (LOWORD(wp) == ID_SplineCurve)
			algo = 16;
		else if (LOWORD(wp) == ID_LineclipingRecatngle) {
			algo = 13;
		}
		else if (LOWORD(wp) == ID_PointclipingRecatngle) {
			algo = 14;
			BeginPaint(hwnd, &p);
			line.DirectLine(p.hdc, 100, 100, 400, 100, color);//--
			line.DirectLine(p.hdc, 100, 100, 100, 400, color);//|__
			line.DirectLine(p.hdc, 100, 400, 400, 400, color);//__
			line.DirectLine(p.hdc, 400, 100, 400, 400, color);
			yT = 100;
			xR = 400;
			xL = 100;
			yB = 400;
			EndPaint(hwnd, &p);
		}
		else if (LOWORD(wp) == ID_Filling)
			algo = 15;
		else if (LOWORD(wp) == ID_Save) {
			Save(poin);
			poin.clear();
		}
		else if (LOWORD(wp) == ID_Load) {
			Load(poin, file);
			BeginPaint(hwnd, &p);
			for (int i = 0; i < poin.size(); i++) {
				algo = poin[i].algo;
				x11 = poin[i].x1;
				x22 = poin[i].x2;
				x33 = poin[i].x3;
				x44 = poin[i].x4;
				y11 = poin[i].y1;
				y22 = poin[i].y2;
				y33 = poin[i].y3;
				y44 = poin[i].y4;
				if (algo == 2)
					line.parametric_line(p.hdc, x11, y11, x22, y22, color);
				else if (algo == 1)
					line.DirectLine(p.hdc, x11, y11, x22, y22, color);
				else if (algo == 3)
					line.SimpleDDA(p.hdc, x11, y11, x22, y22, color);
				else if (algo == 4)
					line.midpoint(p.hdc, x11, y11, x22, y22, color);
				else if (algo == 5)
					circle.CircleDirect(p.hdc, x11, y11, x22, y22, color);
				else if (algo == 6)
					circle.CirclePolar(p.hdc, x11, y11, x22, y22, color);
				else if (algo == 7)
					circle.CircleIterativePolar(p.hdc, x11, y11, x22, y22, color);
				else if (algo == 8)
					circle.CircleFasterBresenham(p.hdc, x11, y11, x22, y22, color);
				else if (algo == 9)
					FirstDegree(p.hdc, x11, y11, x22, y22, color);
				else if (algo == 10)
					drawSecondDegreeCurveUsingMiddlePoint(p.hdc, x11, y11, x22, y22, x33, y33, color);
				else if (algo == 15) {
					POINT pi[4];
					pi[0].x = x11;
					pi[1].x = x22;
					pi[2].x = x33;
					pi[3].x = x44;
					pi[0].y = y11;
					pi[1].y = y22;
					pi[2].y = y33;
					pi[3].y = y44;
					ConvexFill(p.hdc, pi, 4, color);
				}
				else if (algo == 11) {
					P0.x = x11;
					P0.y = y11;
					T0.x = x22;
					T0.y = y22;
					P1.x = x33;
					P1.y = y33;
					T1.x = x44;
					T1.y = y44;
					DrawHermiteCurve(p.hdc, P0, T0, P1, T1, 1400, color);
				}
				else if (algo == 12) {
					P0.x = x11;
					P0.y = y11;
					T0.x = x22;
					T0.y = y22;
					P1.x = x33;
					P1.y = y33;
					T1.x = x44;
					T1.y = y44;
					DrawBezierCurve(p.hdc, P0, T0, P1, T1, 1400, color);
				}
				else if (algo == 13) {
					line.DirectLine(p.hdc, x11, y11, x22, y11, color);//--
					line.DirectLine(p.hdc, x11, y11, x11, y22, color);//|__
					line.DirectLine(p.hdc, x11, y22, x22, y22, color);//__
					line.DirectLine(p.hdc, x22, y11, x22, y22, color);
					yT = y11;
					xR = x22;
					xL = x11;
					yB = y22;
					CohenSuth(p.hdc, x11, y11, x22, y22, xL, yT, xR, yB, color);
				}
				else if (algo == 14) {
					line.DirectLine(p.hdc, 100, 100, 400, 100, color);//--
					line.DirectLine(p.hdc, 100, 100, 100, 400, color);//|__
					line.DirectLine(p.hdc, 100, 400, 400, 400, color);//__
					line.DirectLine(p.hdc, 400, 100, 400, 400, color);
					yT = 100;
					xR = 400;
					xL = 100;
					yB = 400;
					PointClipping(p.hdc, x11, y11, xL, yT, xR, yB, color);
				}

			}
			EndPaint(hwnd, &p);
		}

		else if (LOWORD(wp) == ID_CLEAR)
			InvalidateRect(hwnd, NULL, true);

		else if (LOWORD(wp) == ID_EXIT)
			PostMessage(hwnd, WM_CLOSE, 0, 0);

		/*else if (LOWORD(wp) == ID_COLORWin) {
			CHOOSECOLOR c;
			COLORREF customColors[16];
			memset(&c, 0, sizeof(c));
			c.lStructSize = sizeof(CHOOSECOLOR);
			c.hwndOwner = hwnd;
			c.lpCustColors = customColors;
			c.Flags = CC_RGBINIT;
			BeginPaint(hwnd, &p);
			SetPixel(p.hdc, 20, 20, RGB(0, 0, 0));
			EndPaint(hwnd, &p);
			if (ChooseColor(&c))
			{
				color = c.rgbResult;
				HBRUSH brush = CreateSolidBrush(color);
				SetClassLongPtr(hwnd, GCLP_HBRBACKGROUND, (LONG)brush);
				InvalidateRect(hwnd, NULL, true);
			}
		}

		else if (LOWORD(wp) == ID_COLORTEX) {


			CHOOSECOLOR c;
			COLORREF customColors[16];
			memset(&c, 0, sizeof(c));
			c.lStructSize = sizeof(CHOOSECOLOR);
			c.hwndOwner = hwnd;
			c.lpCustColors = customColors;
			c.Flags = CC_RGBINIT;
			BeginPaint(hwnd, &p);
			SetPixel(p.hdc, 20, 20, RGB(0, 0, 0));
			EndPaint(hwnd, &p);
			if (ChooseColor(&c))
			{
				color = c.rgbResult;
			}
		}*/
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default: return DefWindowProc(hwnd, m, wp, lp);
	}
	return 0;
	}
}
int APIENTRY WinMain(HINSTANCE h, HINSTANCE, LPSTR, int n)
{
	HWND hwnd;
	WNDCLASS wc;
	wc.cbClsExtra = wc.cbWndExtra = 0;
	wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hIcon = LoadIcon(NULL, IDI_WINLOGO);
	wc.hInstance = h;
	wc.lpfnWndProc = MyWindowProc;
	wc.lpszClassName = "Project";
	wc.lpszMenuName = NULL;
	wc.style = CS_VREDRAW | CS_HREDRAW;
	RegisterClass(&wc);
	hwnd = CreateWindow("Project", "Project", WS_OVERLAPPEDWINDOW, 80, 90,1000, 600, NULL, NULL, h,NULL);
	ShowWindow(hwnd,n);
	MSG m;
	while (GetMessage(&m, NULL, 0, 0)>0)
	{
		TranslateMessage(&m);
		DispatchMessage(&m);
	}
	return 0;
}
