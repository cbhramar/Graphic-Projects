/*
 * File: DragonCurve.cpp
 * The program creates the dragon curve as described in the Michael Crichton book 'Jurassic Park'
 */

#include <simplecpp>
#include <iostream>

using namespace std;

void dragon(int n, Turtle & t);
void reverseDragon(int n, Turtle & t);

int main() {
    initCanvas("The Dragon Curve", 1360, 700);
    
    Turtle t1;
    t1.hide();
    t1.right(180);
    dragon(12, t1);
    
    // Uncommenting the following lines will output the diagram shown in DragonCurve-Screenshot2
    // Turtle t2;
    // t2.hide();
    // dragon(12, t2);
    
    // Turtle t3;
    // t3.hide();
    // t3.right(90);
    // dragon(12, t3);
    
    // Turtle t4;
    // t4.hide();
    // t4.right(270);
    // dragon(12, t4);

    getClick();

    return 0;
}

void dragon(int n, Turtle & t) {
    if (n == 0) {
        t.forward(4);
    }
    else {
        dragon(n - 1, t);
        t.left(90);
        reverseDragon(n - 1, t);
    }
}

void reverseDragon(int n, Turtle & t) {
    if (n == 0) {
        t.forward(4);
    }
    else {
        dragon(n - 1, t);
        t.right(90);
        reverseDragon(n - 1, t);
    }
}
