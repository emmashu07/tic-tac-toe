#include <iostream>

using namespace std;

int** clearBoard(int grid[3][3]);

int board[3][3];
int x = 1;
int o = 2;
int blank = 0;

int main() {
	board = clearBoard(board);
	
	return 0;
}

int** clearBoard(int grid[3][3]) {
	for(int i = 0; i < 3; i++) {
	       for(int j = 0; j < 3; j++) {
	       		grid[i][j] = blank;
	       }
	}
	return grid;	
}
