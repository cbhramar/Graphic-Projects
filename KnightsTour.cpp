/*
 * File: KnightsTour.cpp
 */

#include <simplecpp>
#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <cmath>
#include <iomanip>

using namespace std;

const vector<int> xMoves = { 2, 1, -1, -2, -2, -1, 1, 2 };
const vector<int> yMoves = { 1, 2, 2, 1, -1, -2, -2, -1 };
const int N = 4;

bool tour(vector<vector<int>> & board, int x, int y, int & n, Line & l);
bool hasZeroes(vector<vector<int>> & board);
void printBoard(vector<vector<int>> & board);
bool isValid(vector<vector<int>> & board, int x, int y);
void placeKnight(vector<vector<int>> & board, int x, int y, int & n, int xold, int yold, Line & l);
void removeKnight(vector<vector<int>> & board, int x, int y, int & n, int xold, int yold, Line & l);

int main() {
	vector<vector<int>> board(N, vector<int>(N));
	int pos = 1;
	cout << "Welcome to the Knight's Tour!" << endl;
	initCanvas("Knight's Tour", N*40, N*40);
	for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            Line l0(i*40, 0, i*40, N*40);
            l0.imprint();
            Line l1(0, j*40, N*40, j*40);
            l1.imprint();
        }
	}
	Line l(0, 0, 0, 0);
    board[0][0] = 1;
    Text t0(20, 20, 1);
    t0.imprint();
	if (tour(board, 0, 0, pos, l))
		cout << endl;
	cout << endl;

	getClick();

	return 0;
}

bool tour(vector<vector<int>> & board, int x, int y, int & n, Line & l) {
	if (n == N*N) {
        getClick();
		printBoard(board);
		return true;
	}
	for (int i = 0; i < N; i++) {
		if (isValid(board, x + xMoves[i], y + yMoves[i])) {
            int nextX = x + xMoves[i];
            int nextY = y + yMoves[i];
			placeKnight(board, nextX, nextY, n, x, y, l);
			if (tour(board, nextX, nextY, n, l)) return true;
			removeKnight(board, nextX, nextY, n, x, y, l);
		}
	}
	return false;
}

bool hasZeroes(vector<vector<int>> & board) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (board[i][j] == 0)
				return true;
		}
	}
	return false;
}

void printBoard(vector<vector<int>> & board) {
	for (int i = 0; i < N; i++) {
		cout << "+---";
	}
	cout << "+" << endl;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
            if (board[i][j] >= 10)
                cout << "|" << right << setw(3) << board[i][j];
            else
                cout << "|" << right << " 0" << board[i][j];
		}
		cout << "|" << endl;
		for (int j = 0; j < N; j++) {
			cout << "+---";
		}
		cout << "+" << endl;
	}
}

bool isValid(vector<vector<int>> & board, int x, int y) {
	return (x < N && x >= 0 && y < N && y >= 0 && board[x][y] == 0);
}

void placeKnight(vector<vector<int>> & board, int x, int y, int & n, int xold, int yold, Line & l) {
	++n;
	board[x][y] = n;
    Text t(40*y + 20, 40*x + 20, n);
    t.imprint();
   // l.reset(40*xold + 20, 40*yold + 20, 40*x + 20, 40*y + 20);
   // l.imprint();
}

void removeKnight(vector<vector<int>> & board, int x, int y, int & n, int xold, int yold, Line & l) {
	n--;
	Text t(40*y + 20, 40*x + 20, "    ");
    t.imprint();
   // l.reset(xold, yold, 0, yold);
   // l.imprint();
	board[x][y] = 0;
}
