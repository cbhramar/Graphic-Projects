/*
 * File: Tree2.cpp
 * This program creates a tree in the canvas window
 */
#include <iostream>
#include <simplecpp>

using namespace std;

void botanicalTree(int order, double length, double theta, double x, double y);

int main(){
    initCanvas("Botanical Tree", 1360, 700);
    botanicalTree(7, 300, -PI/2, 680, 700);
    getClick();
}

void botanicalTree(int order, double length, double theta, double x, double y){
    if (order == 0) {
        Line l0(x, y, x + length*cos(theta), y + length*sin(theta));
        l0.setColor(COLOR(100, 180, 100));
        l0.imprint();
    }
    else {
        Rectangle r1(x + cos(theta)*length/2, y + sin(theta)*length/2, order/2 + 0.5, length);
        r1.rotate(theta + PI/2);
        r1.setFill(true);
        r1.setColor(COLOR("black"));
        r1.imprint();
        botanicalTree(order - 1, length*0.5, theta - PI/4, x + 0.6*length*cos(theta), y + 0.6*length*sin(theta));
        botanicalTree(order - 1, length*0.5, theta + PI/6, x + 0.7*length*cos(theta), y + 0.7*length*sin(theta));
        botanicalTree(order - 1, length*0.5, theta + PI/4, x + 0.7*length*cos(theta), y + 0.7*length*sin(theta));
        botanicalTree(order - 1, length*0.5, theta - PI/6, x + 0.6*length*cos(theta), y + 0.6*length*sin(theta));
        botanicalTree(order - 1, length*0.5, theta, x + 0.65*length*cos(theta), y + 0.65*length*sin(theta));
    }
}
