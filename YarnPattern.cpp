/*
 * File: YarnPattern.cpp
 * This program uses the simplecpp package
 * This program simulates what a pattern might look like if it was made by tracing the path of a yarn
 * starting from the top left corner given a number of spaces to skip as the landing point of the yarn. 
 * An example would explain this better: The screenshot attached is achieved by setting the ITERATIONS 
 * variable to 1200 as a response to the first prompt and setting the DELTA variable to 1789 as a response
 * to the second prompt.
 * This file is heavily influenced by the Stanford Course CS106B and its associated reader.
 */
#include <iostream>
#include <simplecpp>
#include <vector>

using namespace std;

const int N_ACCROSS = 1360;
const int N_DOWN = 700;

class Point {
public:
    Point(int xc = 0, int yc = 0) {
        x = xc;
        y = yc;
    }
    int getX() {
        return x;
    }
    int getY() {
        return y;
    }
private:
    int x;
    int y;
};

void createPattern(vector<Point> & stops, int DELTA, int ITERATIONS);

int main() {
    
    int ITERATIONS;
    cout << "Enter the number of iterations you would like:" << endl;
    cin >> ITERATIONS;
    int DELTA;
    cout << "Enter a number and watch the fun!" << endl; 
    cin >> DELTA;

    initCanvas("Yarn Pattern", N_ACCROSS, N_DOWN);

    Point centre(N_ACCROSS/2, N_DOWN/2);
    vector<Point> stops;

    for (int i = 0; i < N_ACCROSS; i++) {
        stops.push_back(Point(centre.getX() - N_ACCROSS/2 + i, centre.getY() - N_DOWN/2));
    }
    for (int i = 0; i < N_DOWN; i++) {
        stops.push_back(Point(centre.getX() + N_ACCROSS/2, centre.getY() - N_DOWN/2 + i));
    }
    for (int i = 0; i < N_ACCROSS; i++) {
        stops.push_back(Point(centre.getX() + N_ACCROSS/2 - i, centre.getY() + N_DOWN/2));
    }
    for (int i = 0; i < N_DOWN; i++) {
        stops.push_back(Point(centre.getX() - N_ACCROSS/2, centre.getY() + N_DOWN/2 - i));
    }

    createPattern(stops, DELTA, ITERATIONS);

    getClick();
}

void createPattern(vector<Point> & stops, int DELTA, int ITERATIONS) {
    int cp = 0;
    for (int i = 0; i < ITERATIONS; i++) {
        Line l(stops[cp].getX(), stops[cp].getY(), stops[(cp + DELTA)%stops.size()].getX(), stops[(cp + DELTA)%stops.size()].getY());
        l.imprint();
        cp = (cp + DELTA)%stops.size();
    }
}
