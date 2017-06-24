#include <simplecpp>
#include <iostream>
#include <cmath>
#include <vector>
#include <iomanip>
#include <string>

using namespace std;

void printGrid(vector<vector<int>> & sudokuGrid);
bool solveSudoku(vector<vector<int>> & sudokuGrid);
bool findUnassignedLocation(vector<vector<int>> & sudokuGrid, int & row, int & col);
bool NoConflicts(vector<vector<int>> & sudokuGrid, int row, int col, int num);
bool usedInRow(vector<vector<int>> & sudokuGrid, int row, int num);
bool usedInCol(vector<vector<int>> & sudokuGrid, int col, int num);
bool usedInBox(vector<vector<int>> & sudokuGrid, int row1, int col1, int num);
void graphicDisplay(vector<vector<int>> & sudokuGrid);

int main() {
    initCanvas("Sudoku Display", 450, 450);
    for (int i = 0; i < 450; i += 50) {
        for (int j = 0; j < 450; j += 50) {
            Line l0(i, 0, i, 450);
            l0.imprint();
            Line l1(0, i, 450, i);
            l1.imprint();
        }
    }
	vector<vector<int>> sudokuGrid(9, vector<int>(9));
	cout << "Enter the number of given digits :" << endl;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cout << "Enter the two integers corresponding to the position, followed by the hint: " << endl;
		int x, y;
		cin >> x >> y;
		int hint;
		cin >> hint;
		sudokuGrid[x - 1][y - 1] = hint;
	}
	cout << endl << endl << "The grid provided by you is :" << endl << endl;
	printGrid(sudokuGrid);
	graphicDisplay(sudokuGrid);
	cout << endl << endl << "The solved grid is :" << endl << endl;

	solveSudoku(sudokuGrid);
	cout << endl;

	getClick();

	return 0;
}

void printGrid(vector<vector<int>> & sudokuGrid) {
	for (int i = 0; i < 9; i++) {
		cout << "+---";
	}
	cout << "+" << endl;
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			if (sudokuGrid[i][j] == 0) {
				cout << "|" << "   ";
			}
			else {
				cout << "|" << right << setw(2) << sudokuGrid[i][j] << " ";
			}
		}
		cout << "|" << endl;
		for (int j = 0; j < 9; j++) {
			cout << "+---";
		}
		cout << "+" << endl;
	}
}

bool solveSudoku(vector<vector<int>> & sudokuGrid) {
	int row;
	int col;

	if (!findUnassignedLocation(sudokuGrid, row, col)) {
		printGrid(sudokuGrid);
		// graphicDisplay(sudokuGrid);
		return true;
	}

	for (int num = 1; num <= 9; num++) {
		if (NoConflicts(sudokuGrid, row, col, num)) {
			sudokuGrid[row][col] = num;
			Text t1(col*50 + 25, row*50 + 25, num);
			t1.imprint();
			// graphicDisplay(sudokuGrid);
			if (solveSudoku(sudokuGrid)) return true;
			sudokuGrid[row][col] = 0;
			// t1(col*50 + 25, row*50 + 25, blank);
			// t1.imprint();
			// graphicDisplay(sudokuGrid);
		}
	}
	return false;
}

bool findUnassignedLocation(vector<vector<int>> & sudokuGrid, int & row, int & col) {
	for (row = 0; row < 9; row++) {
		for (col = 0; col < 9; col++) {
			if (sudokuGrid[row][col] == 0) {
				return true;
			}
		}
	}
	return false;
}

bool NoConflicts(vector<vector<int>> & sudokuGrid, int row, int col, int num) {
	return !usedInRow(sudokuGrid, row, num) && !usedInCol(sudokuGrid, col, num) && !usedInBox(sudokuGrid, row - row % 3, col - col % 3, num);
}

bool usedInRow(vector<vector<int>> & sudokuGrid, int row, int num) {
	for (int col = 0; col < 9; col++) {
		if (sudokuGrid[row][col] == num) return true;
	}
	return false;
}

bool usedInCol(vector<vector<int>> & sudokuGrid, int col, int num) {
	for (int row = 0; row < 9; row++) {
		if (sudokuGrid[row][col] == num) return true;
	}
	return false;
}

bool usedInBox(vector<vector<int>> & sudokuGrid, int row1, int col1, int num) {
	for (int row = 0; row < 3; row++) {
		for (int col = 0; col < 3; col++) {
			if (sudokuGrid[row + row1][col + col1] == num) return true;
		}
	}
	return false;
}

void graphicDisplay(vector<vector<int>> & sudokuGrid) {
    for (int i = 0; i < 9; i += 1) {
        for (int j = 0; j < 9; j += 1) {
            if (sudokuGrid[i][j] != 0) {
                Text t1(j*50 + 25, i*50 + 25, sudokuGrid[i][j]);
                t1.setFill(true);
                t1.setColor(COLOR("red"));
                t1.imprint();
            }
        }
    }
}
