#pragma once
#include <windows.h>
#include <cmath>
#include <fstream>
#include <vector>
using namespace std;
struct point {
	double x1 = 0, x2 = 0, x3 = 0, x4 = 0, algo = 0;
	double y1 = 0, y2 = 0, y3 = 0, y4 = 0;
};

void Save(vector<point>p);
void Load(vector<point>&p,vector<int>file);