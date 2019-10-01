#include <iostream>

using namespace std;

//int** clearBoard(int grid[3][3]);
void printBoard(int grid[3][3]);
void play(char in[2], int grid[3][3]);

int board[3][3];
int x = 1;
int o = 2;
int blank = 0;
int player = 1;
char input[2];
bool xWin = false;
bool oWin = false;
bool tie = false;

int main() {
	printBoard(board);	
	cout << "Welcome to Tic-Tac-Toe, enter a number, 1-3, followed by a letter, a-c, to begin." << endl;
	while (!xWin && !oWin && !tie) {
		cin >> input;
		play(input, board);
		printBoard(board);
		//checkWin(player);
		if (player == x) {
			player = o;
		}
		else {
			player = x;
		}
	}
	return 0;
}

void printBoard(int grid[3][3]) {
	cout << "\t1\t2\t3" << endl;
	for(int i = 0; i < 3; i++) {	
		cout << (char)('a' + i);	
		for(int j = 0; j < 3; j++) {
			cout << '\t';	
			if(grid[i][j] == x) {
				cout << 'X';
			}
			else if(grid[i][j] == o) {
				cout << 'O';
			}
			else {
				cout << ' ';
			}	
		}
		cout << endl;
	}
}

void play(char in[2], int grid[3][3]) {
	int first = in[0] - 1;
	int second = (int)(in[1] - 'a');
	if(player == x && grid[first][second] == blank) {	
		grid[first][second] = x;
	}
	else if (player == o && grid[first][second] == blank) {
		grid[first][second] = o;
	}
	printBoard(grid);
}

/*int** clearBoard(int grid[3][3]) {
	for(int i = 0; i < 3; i++) {
	       for(int j = 0; j < 3; j++) {
	       		grid[i][j] = blank;
	       }
	}
	return grid;	
}*/
