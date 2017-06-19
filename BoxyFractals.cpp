/*
 * File: BoxyFractals.cpp
 * Program to create Boxy Fractals. Not particularly efficient
 */
#include <simplecpp>
#include <iostream>
#include <cmath>

using namespace std;

void boxyFractals(double x, double y, double length, int order);

int main() {
    initCanvas("Boxy Fractal", 700, 700);
    boxyFractals(350, 350, 300, 6);
    getClick();

    return 0;
}

void boxyFractals(double x, double y, double length, int order) {
    if (order == 0) {
        Rectangle r(x, y, length, length);
        r.setFill(true);
        r.setColor(COLOR("blue"));
        r.imprint();
        r.imprint();
    }
    else {
        Rectangle r1(x, y, length, length);
        r1.setFill(true);
        r1.setColor(COLOR("blue"));
        r1.imprint();
        boxyFractals(x + (length/2.0), y + (length/2.0), length/2.0, order - 1);
        boxyFractals(x + (length/2.0), y - (length/2.0), length/2.0, order - 1);
        boxyFractals(x - (length/2.0), y + (length/2.0), length/2.0, order - 1);
        boxyFractals(x - (length/2.0), y - (length/2.0), length/2.0, order - 1);
    }
}
