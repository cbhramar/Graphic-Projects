/*
 * File: Mondrian.cpp
 * This program uses the simplecpp package 
 * The purpose of the program is to create a painting simulate Piet Mondrian's works of art.
 * The program, when run, opens a canvas and starts painting.
 * This file is heavily influenced by the Stanford Course CS106B and its associated reader.
 */

#include <iostream>
#include <cmath>
#include <simplecpp>
#include <cstdlib>
#include <ctime>

using namespace std;

const double MIN_AREA = 10000;
const double MIN_EDGE = 20;

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


void createAMondrian(double x, double y, double width, double height) {
    if (width*height >= MIN_AREA) {
        if (width > height) {
            double mid = randomReal(MIN_EDGE, width - MIN_EDGE);
            Rectangle r1(x + mid/2, y + height/2, mid, height);
            r1.setFill(true);
            r1.setColor(COLOR(randomInteger(0, 253),randomInteger(0, 253), randomInteger(0, 253)));
            r1.imprint();
            createAMondrian(x, y, mid, height);
            createAMondrian(x + mid, y, width - mid, height);
            Line l(x + mid, y, x + mid, y + height);
            l.imprint();
        }
        else {
            double mid = randomReal(MIN_EDGE, height - MIN_EDGE);
            Rectangle r1(x + width/2, y + mid/2, width, mid);
            r1.setFill(true);
            r1.setColor(COLOR(randomInteger(0, 253),randomInteger(0, 253), randomInteger(0, 253)));
            r1.imprint();
            createAMondrian(x, y, width, mid);
            createAMondrian(x, y + mid, width, height - mid);
            Line l(x, y + mid, x + width, y + mid);
            l.imprint();

        }
    }
}

int main() {
    initCanvas("Mondrian", 1000, 700);
    createAMondrian(0, 0, 1000, 700);
    getClick();

    return 0;
}
