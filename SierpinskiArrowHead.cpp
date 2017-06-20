/*
 * File: SierpinskiArrowhead.cpp
 * Code to recursively create the Sierpinski Arrow head of the user's choice order
 * Screenshot is of a Sierpinski Arrowhead of order 8
 */

#include <simplecpp>

void arrowHead(int order, double x, double y, double theta, double length){
    if (order == 1){
        Line l0(x, y, x + cos(theta - PI/3)*length, y + sin(theta - PI/3)*length);
        l0.imprint();
        Line l1(x + cos(theta - PI/3)*length, y + sin(theta - PI/3)*length, x + cos(theta - PI/3)*length + cos(theta)*length, y + sin(theta - PI/3)*length + sin(theta)*length);
        l1.imprint();
        Line l2(x + cos(theta - PI/3)*length + cos(theta)*length, y + sin(theta - PI/3)*length + sin(theta)*length, x + cos(theta - PI/3)*length + cos(theta)*length + cos(theta + PI/3)*length, y + sin(theta - PI/3)*length + sin(theta)*length + sin(theta + PI/3)*length);
        l2.imprint();
    }
    else{
        arrowHead(order - 1, x + cos(theta - PI/3)*length, y + sin(theta - PI/3)*length, theta + 2*PI/3, length/2);
        arrowHead(order - 1, x + cos(theta - PI/3)*length, y + sin(theta - PI/3)*length, theta, length/2);
        arrowHead(order - 1, x + cos(theta - PI/3)*length + cos(theta)*length + cos(theta + PI/3)*length, y + sin(theta - PI/3)*length + sin(theta)*length + sin(theta + PI/3)*length, theta - 2*PI/3, length/2);
    }
}

main_program{
    initCanvas("Sierpinski Arrow Head", 1360, 700);
/*    arrowHead(1, 420, 550, 0, 300);
    arrowHead(2, 420, 550, 0, 300);
    arrowHead(3, 420, 550, 0, 300);
    arrowHead(4, 420, 550, 0, 300);
    arrowHead(5, 420, 550, 0, 300);*/
    int order;
    cout << "Enter the order you would like: " << endl;
    cin >> order;
    arrowHead(order, 420, 550, 0, 300);
    getClick();
}
