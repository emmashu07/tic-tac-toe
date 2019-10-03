#include <iostream>

using namespace std;

void printBoard();
void play();
bool checkWin(int player);
bool checkTie();

int board[3][3];
const int X_TURN = 1;
const int O_TURN = 2;
const int BLANK = 0;
const int X_MOVE = 1;
const int O_MOVE = 2;
int turn = X_TURN;
char input[2];


int main() {
	printBoard();	
	cout << "Welcome to Tic-Tac-Toe, enter a number, 1-3, followed by a letter, a-c, to begin." << endl;
	while (!checkWin(X_MOVE) && !checkWin(O_MOVE) && !checkTie()) {
		cin >> input;
		play();	
	}
	return 0;
}

void printBoard() {
	cout << "\t1\t2\t3" << endl;
	for(int i = 0; i < 3; i++) {	
		cout << (char)('a' + i);	
		for(int j = 0; j < 3; j++) {
			cout << '\t';	
			if(board[i][j] == X_MOVE) {
				cout << 'X';
			}
			else if(board[i][j] == O_MOVE) {
				cout << 'O';
			}
			else {
				cout << ' ';
			}	
		}
		cout << endl;
	}
}

void play() {
	int second = (int)(input[0] - '1');
	int first = (int)(input[1] - 'a');
	if(turn == X_TURN && board[first][second] == BLANK) {	
		board[first][second] = X_MOVE;
	}
	else if (turn == O_TURN && board[first][second] == BLANK) {
		board[first][second] = O_MOVE;
	}
	printBoard();	
	if (turn == X_TURN) {
		turn = O_TURN;
	}
	else {
		turn = X_TURN;
	}
}

bool checkWin(int player) {
	if(board[1][1] == player && board[0][0] == player && board[2][2] == player) {
		return true;
	}
	else if(board[1][1] == player && board[2][0] == player && board[0][2] == player) {
		return true;
	}
	else if(board[1][1] == player && board[0][1] == player && board[2][1] == player) {
		return true;
	}
	else if(board[1][1] == player && board[1][0] == player && board[1][2] == player) {
		return true;
	}
	else if(board[0][0] == player && board[0][1] == player && board[0][2] == player) {
		return true;
	}
	else if(board[0][0] == player && board[1][0] == player && board[2][0] == player) {
		return true;
	}
	else if(board[2][0] == player && board[2][1] == player && board[2][2] == player) {
		return true;
	}
	else if(board[0][2] == player && board[1][2] == player && board[2][2] == player) {
		return true;
	}
	return false;
}

bool checkTie() {
	for(int row = 0; row < 3; row++) {
		for(int column = 0; column < 3; column++) {
		       if(board[row][column] == BLANK) {
		       	return false;
	 		}		
		}
	}
	return true;
}


