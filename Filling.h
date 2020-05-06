#pragma
#include <Windows.h>

#define MAXENTRIES 600;
struct Entry
{
	int xmin, xmax;
};
void Swap(POINT &v1, POINT &v2);

void InitEntries(Entry table[]);

void ScanEdge(POINT v1, POINT v2, Entry table[]);

void DrawSanLines(HDC hdc, Entry table[], COLORREF color);

void ConvexFill(HDC hdc, POINT p[], int n, COLORREF color);
