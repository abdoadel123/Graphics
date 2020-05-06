#include "File.h"
#include <windows.h>
#include <cmath>
#include <iostream>
#include <fstream>
#include<Commdlg.h>
#include <sstream>

using namespace std;

fstream lineFile,circleFile,curveFile,clippingFile,FillingFile;

void Save(std::vector<point> p)
{
	lineFile.open("Lines.txt", ios::in | ios::out | ios::trunc);
	circleFile.open("Circles.txt", ios::in | ios::out | ios::trunc);
	curveFile.open("Curves.txt", ios::in | ios::out | ios::trunc);
	clippingFile.open("Clliping.txt", ios::in | ios::out | ios::trunc);
	FillingFile.open("Filling.txt", ios::in | ios::out | ios::trunc);
	for (int i = 0; i < p.size(); i++) {
		if (p[i].algo > 0 && p[i].algo <= 4) {

			lineFile << p[i].algo << "\n" << p[i].x1 << "\n" << p[i].y1 << "\n" << p[i].x2 << "\n" << p[i].y2<<"\n";

		}
		else if (p[i].algo > 4 && p[i].algo <= 8) {

			circleFile << p[i].algo << "\n" << p[i].x1 << "\n" << p[i].y1 << "\n" << p[i].x2 << "\n" << p[i].y2 << "\n";

		}
		else if (p[i].algo > 8 && p[i].algo <= 12) {

			curveFile << p[i].algo << "\n" << p[i].x1 << "\n" << p[i].y1 << "\n" << p[i].x2 << "\n" << p[i].y2 << "\n" << p[i].x3 << "\n" << p[i].y3 << "\n"
				<< p[i].x4 << "\n" << p[i].y4 << "\n";

		}
		else if (p[i].algo > 12 && p[i].algo <= 14) {

			clippingFile << p[i].algo << "\n" << p[i].x1 << "\n" << p[i].y1 << "\n" << p[i].x2 << "\n" << p[i].y2 << "\n" << p[i].x3 << "\n" << p[i].y3 << "\n"
				<< p[i].x4 << "\n" << p[i].y4 << "\n";

		}
		else if (p[i].algo == 15) {
			FillingFile << p[i].algo << "\n" << p[i].x1 << "\n" << p[i].y1 << "\n" << p[i].x2 << "\n" << p[i].y2 << "\n" << p[i].x3 << "\n" << p[i].y3 << "\n"
				<< p[i].x4 << "\n" << p[i].y4 << "\n";
		}

	}
	lineFile.close();
	circleFile.close();
	curveFile.close();
	clippingFile.close();
	FillingFile.close();
}

void Load(vector<point> &p,vector<int>fil)
{
	point p1;
	lineFile.open("Lines.txt", ios::in | ios::out);
	circleFile.open("Circles.txt", ios::in | ios::out);
	curveFile.open("Curves.txt", ios::in | ios::out);
	clippingFile.open("Clliping.txt", ios::in | ios::out);
	FillingFile.open("Filling.txt", ios::in | ios::out);

	for (int i = 0; i < fil.size(); i++) {
		if (fil[i] == 1) {
			lineFile >> p1.algo >> p1.x1  >> p1.y1  >> p1.x2  >> p1.y2;
			p.push_back(p1);
		}
		else if (fil[i] == 2) {
			circleFile >> p1.algo >> p1.x1 >> p1.y1 >> p1.x2 >> p1.y2;
			p.push_back(p1);
		}
		else if (fil[i] == 3) {
			curveFile >> p1.algo >> p1.x1 >> p1.y1 >> p1.x2 >> p1.y2 >> p1.x3 >> p1.y3 >> p1.x4 >> p1.y4;
			p.push_back(p1);
		}
		else if (fil[i] == 4) {
			clippingFile >> p1.algo >> p1.x1 >> p1.y1 >> p1.x2 >> p1.y2 >> p1.x3 >> p1.y3 >> p1.x4 >> p1.y4;
			p.push_back(p1);
		}
		else if (fil[i] == 5) {
			FillingFile >> p1.algo >> p1.x1 >> p1.y1 >> p1.x2 >> p1.y2 >> p1.x3 >> p1.y3 >> p1.x4 >> p1.y4;
			p.push_back(p1);
		}
	}
	lineFile.close();
	circleFile.close();
	curveFile.close();
	clippingFile.close();
	FillingFile.close();
}
