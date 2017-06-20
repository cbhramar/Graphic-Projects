/*
 * File: HilbertCurve.cpp
 * The program draws the hilbert curve of user specified order and reach
 * The program is heavily influenced by the Wikipedia entry for Hilbert Curve
 */

#include <simplecpp>
#include <iostream>

using namespace std;

void lineRel(int & x, int & y, int deltaX, int deltaY);
void HilbertA(int level, double dist, int & x, int & y);
void HilbertB(int level, double dist, int & x, int & y);
void HilbertC(int level, double dist, int & x, int & y);
void HilbertD(int level, double dist, int & x, int & y);

int main(int argc, char const *argv[]) {
	
	initCanvas("The Hilbert Curve", 700, 700);

	int level;
	cout << "Enter the level: " << endl;
	cin >> level;

	double dist;
	cout << "Enter the square distance you want to span: " << endl;
	cin >> dist;
	
	for (int i = level; i > 0; --i) {
		dist /= 2;
	}
	
	int x = dist/2;
	int y = dist/2;
	
	HilbertA(level, dist, x, y);

	getClick();
	return 0;
}

void lineRel(int & x, int & y, int deltaX, int deltaY) {
	Line l(x, y, x + deltaX, y + deltaY);
	x += deltaX;
	y += deltaY;
	l.imprint();
}

void HilbertA(int level, double dist, int & x, int & y) {
	if (level > 0) {
		HilbertB(level - 1, dist, x, y);    lineRel(x, y, 0, dist);
		
		HilbertA(level - 1, dist, x, y);    lineRel(x, y, dist, 0);
		
		HilbertA(level - 1, dist, x, y);    lineRel(x, y, 0, -dist);
		
		HilbertC(level - 1, dist, x, y);
	}
}

void HilbertB(int level, double dist, int & x, int & y) {
	if (level > 0) {
		HilbertA(level - 1, dist, x, y);    lineRel(x, y, dist, 0);
		
		HilbertB(level - 1, dist, x, y);    lineRel(x, y, 0, dist);
		
		HilbertB(level - 1, dist, x, y);    lineRel(x, y, -dist, 0);
		
		HilbertD(level - 1, dist, x, y);
	}
}

void HilbertC(int level, double dist, int & x, int & y) {
	if (level > 0) {
		HilbertD(level - 1, dist, x, y);    lineRel(x, y, -dist, 0);
		
		HilbertC(level - 1, dist, x, y);    lineRel(x, y, 0, -dist);
		
		HilbertC(level - 1, dist, x, y);    lineRel(x, y, dist, 0);
		
		HilbertA(level - 1, dist, x, y);
	}
}

void HilbertD(int level, double dist, int & x, int & y) {
	if (level > 0) {
		HilbertC(level - 1, dist, x, y);    lineRel(x, y, 0, -dist);
		
		HilbertD(level - 1, dist, x, y);    lineRel(x, y, -dist, 0);
		
		HilbertD(level - 1, dist, x, y);    lineRel(x, y, 0, dist);
		
		HilbertB(level - 1, dist, x, y);
	}
}
