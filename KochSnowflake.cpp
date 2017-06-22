/*
 * File: KochSnowflake.cpp
 * Program to draw a Koch snowflake of user's choice order
 * The screenshot attached is that of a Koch snowflake of order 6 and zero-order length 500
 */

#include <simplecpp>
#include <iostream>
#include <cmath>

using namespace std;

void fractalLine(double x, double y, double length, double theta, int order);

int main() {

    double length;
    cout << "Enter length of 0 order fractal :" << endl;
    cin >> length;

    int order;
    cout << "Enter the order of your choice: " << endl;
    cin >> order;

    initCanvas("Koch Snowflake", 800, 700);
    fractalLine(400 - (length/2.0), 350 - sqrt(3)*(length/6.0), length, 0, order);
    fractalLine(400 + (length/2.0), 350 - sqrt(3)*(length/6.0), length, 2*PI/3.0, order);
    fractalLine(400, 350 + sqrt(3)*(length/3.0), length, -2*PI/3.0, order);

    getClick();
    return 0;
}

void fractalLine(double x, double y, double length, double theta, int order) {
    if (order == 0) {
        Line l(x, y, x + length*cos(theta), y + length*sin(theta));
        l.imprint();
    }
    else {
        double newX = x + (length/3.0)*cos(theta);
        double newY = y + (length/3.0)*sin(theta);
        fractalLine(newX, newY, length/3.0, theta - PI/3.0, order - 1);
        fractalLine(x, y, length/3.0, theta, order - 1);
        fractalLine(newX + (length/3.0)*cos(theta - PI/3.0), newY + (length/3.0)*sin(theta - PI/3.0), length/3.0, theta + PI/3.0, order - 1);
        fractalLine(x + 2*(length/3.0)*cos(theta), y + 2*(length/3.0)*sin(theta), length/3.0, theta, order - 1);
    }
}
