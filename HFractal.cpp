/*
 * File: HFractal.cpp
 * Program to draw the H fractal
 */

#include <simplecpp>
#include <iostream>
#include <cmath>

using namespace std;

void draw_H_fractal(double x, double y, double w, double h, int order);

int main(){
    double w = 200;
    double h = 200;
    initCanvas("H fractal", 1360, 700);
    draw_H_fractal(680, 350, w, h, 5);
    getClick();
}

void draw_H_fractal(double x, double y, double w, double h, int order){
    if (order == 0){
        Line l0(x - w/2, y, x + w/2, y);
        l0.imprint();
        Line l1(x - w/2, y - h/2, x - w/2, y + h/2);
        l1.imprint();
        Line l2(x + w/2, y - h/2, x + w/2, y + h/2);
        l2.imprint();
    }
    else {
        Line l0(x - w/2, y, x + w/2, y);
        l0.imprint();
        Line l1(x - w/2, y - h/2, x - w/2, y + h/2);
        l1.imprint();
        Line l2(x + w/2, y - h/2, x + w/2, y + h/2);
        l2.imprint();
        draw_H_fractal(x - w/2, y - h/2, w/2, h/2, order - 1);
        draw_H_fractal(x - w/2, y + h/2, w/2, h/2, order - 1);
        draw_H_fractal(x + w/2, y + h/2, w/2, h/2, order - 1);
        draw_H_fractal(x + w/2, y - h/2, w/2, h/2, order - 1);
    }
}
