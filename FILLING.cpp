#include "Filling.h"
#include <math.h>
#include <Windows.h>

void Swap(POINT &v1, POINT &v2) {
	POINT temp = v1;
	v1 = v2;
	v2 = temp;
}
double ceil(int x) {
	return x+.05;
}
double floor(int x) {
	return x-.05;
}
void InitEntries(Entry table[])
{
	for (int i = 0; i<600; i++)
	{
		table[i].xmin = 100000000000000;
		table[i].xmax = -100000000000000;
	}
}

void ScanEdge(POINT v1, POINT v2, Entry table[])
{
	if (v1.y == v2.y)return;
	if (v1.y>v2.y)
		Swap(v1, v2);
	double minv = (double)(v2.x - v1.x) / (v2.y - v1.y);
	double x = v1.x;
	int y = v1.y;
	while (y<v2.y)
	{
		if (x<table[y].xmin)table[y].xmin = (int)ceil(x);
		if (x>table[y].xmax)table[y].xmax = (int)floor(x);
		y++;
		x += minv;
	}
}

void DrawSanLines(HDC hdc, Entry table[], COLORREF color)
{
	for (int y = 0; y<600; y++)
		if (table[y].xmin<table[y].xmax)
			for (int x = table[y].xmin; x <= table[y].xmax; x++)
				SetPixel(hdc, x, y, color);
}

void ConvexFill(HDC hdc, POINT p[], int n, COLORREF color)
{
	Entry *table = new Entry[600];
	InitEntries(table);
	POINT v1 = p[n - 1];
	for (int i = 0; i<n; i++)
	{
		POINT v2 = p[i];
		ScanEdge(v1, v2, table);
		v1 = p[i];
	}
	DrawSanLines(hdc, table, color);
	delete table;
}
