/*
 * File: SierpinskiTriangle.cpp
 * Code to draw the Sierpinski triangle of the user's choice order
 * Screenshot is of a Sierpinski Triangle of order 7
 */

#include <simplecpp>
#include <iostream>
#include <cmath>

using namespace std;

void sierpinskiLine(double x, double y, double l, double h, double t, int order);

int main() {
    initCanvas("Sierpinski Triangle", 1360, 700);
    double cx = 680;
    double cy = 350;

    double length = 500;
    double height = sqrt(3)*length/2.0;

    int order;
    cout << "Enter the order you want the triangle to be: " << endl;
    cin >> order;

    sierpinskiLine(cx, cy + height/3.0, length, height, 0, order);
    sierpinskiLine(cx + (height/6.0)*sqrt(3), cy - height/6.0, length, height, -2*PI/3.0, order);
    sierpinskiLine(cx - sqrt(3)*(height/6.0), cy - height/6.0, length, height, -PI/3.0, order);

    getClick();
}

void sierpinskiLine(double x, double y, double l, double h, double t, int order) {
    if (order == 0) {
        Line l0(x - l*cos(t)/2, y - l*sin(t)/2, x + l*cos(t)/2, y + l*sin(t)/2);
        l0.imprint();
    }
    else {
        sierpinskiLine(x - cos(t)*l/4, y - sin(t)*l/4, l/2, h/2, t, order - 1);
        sierpinskiLine(x + cos(t)*l/4, y + sin(t)*l/4, l/2, h/2, t, order - 1);
        if (t != -PI/3.0)
            sierpinskiLine(x + sin(t)*h/2, y - cos(t)*h/2, l/2, h/2, t, order - 1);
        else
            sierpinskiLine(x - sin(t)*h/2, y + cos(t)*h/2, l/2, h/2, t, order - 1);
    }
}
