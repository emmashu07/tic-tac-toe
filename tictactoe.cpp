#include <iostream>

using namespace std;

//int** clearBoard(int grid[3][3]);
void printBoard(int grid[3][3]);

int board[3][3];
int x = 1;
int o = 2;
int blank = 0;

int main() {
	printBoard(board);	
	cout << "Welcome to Tic-Tac-Toe, enter a letter number followed by a letter to begin.";
	
	return 0;
}

void printBoard(int grid[3][3]) {
	cout << "\t1\t2\t3" << endl;
	for(int i = 0; i < 3; i++) {
		char str[10];
		int counter = 0;
		str[counter] = (char)('a' + i);
		counter++;
		for(int j = 0; j < 3; j++) {
			str[counter] = '\t';
			counter++;
			if(grid[i][j] == 1) {
				str[counter] = 'X';
			}
			else if(grid[i][j] == 2) {
				str[counter] = 'O';
			}
			else {
				str[counter] = ' ';
			}	
			counter++;
		}
		cout << str << endl;
	}
}

/*int** clearBoard(int grid[3][3]) {
	for(int i = 0; i < 3; i++) {
	       for(int j = 0; j < 3; j++) {
	       		grid[i][j] = blank;
	       }
	}
	return grid;	
}*/
