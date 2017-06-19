/*
 * File: CesaroTear.cpp
 * Program to create a Cesaro Tear
 */

#include <simplecpp>
#include <iostream>
#include <cmath>

using namespace std;

void cesaroTear(double x, double y, double t, double l, double order, double theta);

int main() {
    initCanvas("Cesaro Tear", 1360, 700);
    int order = 4;
    double t = PI/20;
    double l = 400;
    cesaroTear(480, 150, t, l, order, 0);
    cesaroTear(880, 150, t, l, order, PI/2);
    cesaroTear(880, 550, t, l, order, PI);
    cesaroTear(480, 550, t, l, order, -PI/2);
    getClick();

    return 0;
}

void cesaroTear(double x, double y, double t, double l, double order, double theta) {
    if (order == 0) {
        Line l0(x, y, x + cos(theta)*l, y + sin(theta)*l);
        l0.imprint();
    }
    else {
        double d = sin(t/2)*l/2;
        cesaroTear(x, y, t, l/2 - d, order - 1, theta);
        cesaroTear(x + cos(theta)*(l/2 + d), y + sin(theta)*(l/2 + d), t, l/2 - d, order - 1, theta);
        cesaroTear(x + cos(theta)*(l/2 - d), y + sin(theta)*(l/2 - d), t, l/2, order - 1, theta + PI/2 - t/2);
        cesaroTear(x + cos(theta)*(l/2 - d) + d*cos(theta) - sin(theta)*l/2, y + sin(theta)*(l/2 - d) + cos(theta)*l/2 +d*sin(theta), t, l/2, order - 1, theta - PI/2 + t/2);
    }
}
