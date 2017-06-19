/*
 * File: Tree1.cpp
 * This file uses random numbers to draw a tree with varying probability of branches sprouting from a given place
 */
#include <simplecpp>
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

void initRandomSeed() {
    static bool initialized = false;
    if (!initialized)
    {
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

void drawFractalTree(int order, int l, double x, double y, double t) {
    if (order > 0) {
        if (order <= 1) {
            Rectangle r(x + cos(t)*l/2, y + sin(t)*l/2, 1.5, l);
            r.rotate(t + PI/2);
            r.setFill(true);
            r.setColor(COLOR(100, 180, 100));
            r.imprint();
        }
        else {
            Rectangle r1(x + cos(t)*l/2, y + sin(t)*l/2, order/2 + 0.5, l);
            r1.rotate(t + PI/2);
            r1.setFill(true);
            r1.setColor(COLOR("black"));
            r1.imprint();
        }
        if (randomChance(0.8))
            drawFractalTree(order - 1, l*0.75, x + l*cos(t), y + l*sin(t), t - PI/3 );
        if (randomChance(0.7))
            drawFractalTree(order - 1, l*0.75, x + l*cos(t), y + l*sin(t), t - 2*PI/9 );
        if (randomChance(0.6))
            drawFractalTree(order - 1, l*0.75, x + l*cos(t), y + l*sin(t), t - PI/9 );
        if (randomChance(0.9))
            drawFractalTree(order - 1, l*0.75, x + l*cos(t), y + l*sin(t), t );
        if (randomChance(0.8))
            drawFractalTree(order - 1, l*0.75, x + l*cos(t), y + l*sin(t), t + PI/9 );
        if (randomChance(0.7))
            drawFractalTree(order - 1, l*0.75, x + l*cos(t), y + l*sin(t), t + 2*PI/9 );
        if (randomChance(0.6))
            drawFractalTree(order - 1, l*0.75, x + l*cos(t), y + l*sin(t), t + PI/3 );
    }
}


int main() {
    int length = 200;
    initCanvas("Fractal Tree", 1360, 700);
    drawFractalTree(5, length, 680, 650, -PI/2);
    getClick();
}
