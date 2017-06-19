/*
 * File: VicsekFractal.cpp
 * This program creates a small vikseck fractal. The screenshot is that of a Vicsek Fractal of order 6
 */
#include <simplecpp>
#include <iostream>

using namespace std;

void vicsek(double x, double y, double length, int order){
    if (order == 0){
        Rectangle r1(x, y, length, length);
        r1.setFill(true);
        r1.setColor(COLOR("black"));
        r1.imprint();
    }
    else{
        vicsek(x, y, length/3, order - 1);
        vicsek(x + length/3, y, length/3, order - 1);
        vicsek(x - length/3, y, length/3, order - 1);
        vicsek(x, y - length/3, length/3, order - 1);
        vicsek(x, y + length/3, length/3, order - 1);
    }
}

int main(){

    initCanvas("Vicsek Fractal", 800, 700);
    vicsek(400, 350, 600, 5);

    getClick();

    return 0;
}
