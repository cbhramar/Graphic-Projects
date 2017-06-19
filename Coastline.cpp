/*
 * File: Coastline.cpp
 * Program to simulate a coastline. Coastlines are fractal in nature, so fractals are used to simulate them
 */
#include <simplecpp>
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

void initRandomSeed() {
    static bool initialized = false;
    if (!initialized) {
        srand(int(time(NULL)));
        initialized = true;
    }
}

int randomInteger(int low, int high) {
    initRandomSeed();
    double d = rand() / (double(RAND_MAX) + 1);
    double s = d * (double(high) - low + 1);
    return int(floor(low + s));
}

double randomReal(double low, double high) {
    initRandomSeed();
    double d = rand() / (double(RAND_MAX) + 1);
    double s = d * (double(high) - low);
    return low + s;
}

bool randomChance(double p) {
    initRandomSeed();
    return randomReal(0, 1) < p;
}

void setRandomSeed(int seed) {
    initRandomSeed();
    srand(seed);
}

void fractalLine(double x, double y, double length, double theta, int order){
    if (order == 0) {
        // Rectangle r0(x + length*cos(theta)/2, (y + length*sin(theta))/2, length, y);
        // r0.setFill(true);
        // r0.setColor(COLOR("blue"));
        // r0.imprint();
        // Rectangle r1(x + length*cos(theta)/2, (700 + y - length*sin(theta))/2, length, 700 - y);
        // r1.setFill(true);
        // r1.setColor(COLOR("green"));
        // r1.imprint();
        Line l(x, y, x + length*cos(theta), y + length*sin(theta));
        l.imprint();
    }
    else {
        double newX = x + (length/3.0)*cos(theta);
        double newY = y + (length/3.0)*sin(theta);
        fractalLine(x, y, length/3, theta, order - 1);
        if (randomInteger(0, 1)) {
            fractalLine(newX, newY, length/3.0, theta - PI/3.0, order - 1);
            fractalLine(newX + (length/3.0)*cos(theta - PI/3.0), newY + (length/3.0)*sin(theta - PI/3.0), length/3.0, theta + PI/3.0, order - 1);
        }
        else {
            fractalLine(newX, newY, length/3.0, theta + PI/3.0, order - 1);
            fractalLine(newX + (length/3.0)*cos(theta + PI/3.0), newY + (length/3.0)*sin(theta + PI/3.0), length/3.0, theta - PI/3.0, order - 1);
        }
        fractalLine(x + 2*(length/3.0)*cos(theta), y + 2*(length/3.0)*sin(theta), length/3, theta, order - 1);
    }
}

int main() {
    initCanvas("Random Coastline", 1360, 700);
    fractalLine(0, 350, 320, 0, 4);
    fractalLine(320, 350, 720, 0, 5);
    fractalLine(1040, 350, 320, 0, 4);
    getClick();
}
