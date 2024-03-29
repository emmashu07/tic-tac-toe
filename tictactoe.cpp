#include <iostream>
#include <cstring>

using namespace std;

//Emma Shu, 10/3/2019: Console game of Tic-Tac-Toe, played against yourself.

void printBoard(int board[3][3]);
void play(int board[3][3], char input[2], int &turn);
bool checkWin(int player, int board[3][3]);
bool checkTie(int board[3][3]);
bool wins(int &xWins, int &oWins, int board[3][3]);
void clearBoard(int board[3][3]);

const int X_TURN = 1;
const int O_TURN = 2;
const int BLANK = 0;
const int X_MOVE = 1;
const int O_MOVE = 2;

int main() {
	int turn = X_TURN;
	int xWins = 0;
	int oWins = 0;
	char input[5];
	bool stillPlaying = true;
	char status[5];
	bool stop = false;
	int board[3][3];

    clearBoard(board);
	printBoard(board);    
	cout << "Welcome to Tic-Tac-Toe, enter a number, 1-3, followed by a letter, a-c, to begin." << endl;
	while(stillPlaying) {
		while (!stop) {
			cin >> input;	
			while (strlen(input) > 2 || input[0] > '3' || input[0] < '1' || input[1] > 'c' || input[1] < 'a' || !isalpha(input[1]) || !isdigit(input[0])) {
				cout << "Please enter a number, 1-3, followed by a letter, a-c (e.g. 1a)" << endl; // Rejected conditions.
                cin >> input;
			}
			play(board, input, turn);
			stop = wins(xWins, oWins, board); // Once a win or tie occurs, move on.
		}
		cout << "Keep playing? Y/N" << endl;
		cin >> status;
		if(status[0] != 'n' && status[0] != 'N' && status[0] != 'y' && status[0] != 'Y' && strlen(status) > 1) {
            cout << "Please enter Y/N" << endl;
            cin >> status;
        }
		if(status[0] == 'n' || status[0] == 'N') {
			stillPlaying = false;
		}	
		clearBoard(board);
		printBoard(board);
		stop = false;
	}
	return 0;
}

void printBoard(int board[3][3]) {
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

void play(int board[3][3], char input[2], int &turn) { // A turn.
	int second = (int)(input[0] - '1');
	int first = (int)(input[1] - 'a');
	if(board[first][second] == BLANK) { // Check if move is legal.
		if(turn == X_TURN) {	
			board[first][second] = X_MOVE;
			turn = O_TURN;
		}
		else if (turn == O_TURN) {
			board[first][second] = O_MOVE;
			turn = X_TURN;
		}
	}	
	else {
		cout << "There's a piece already there." << endl;
	}
	printBoard(board);	
	
}

bool checkWin(int player, int board[3][3]) {
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

bool checkTie(int board[3][3]) {
	for(int row = 0; row < 3; row++) {
		for(int column = 0; column < 3; column++) {
		       if(board[row][column] == BLANK) {
		       	return false;
	 		}		
		}
	}
	return true;
}

bool wins(int &xWins, int &oWins, int board[3][3]) { // Check if someone has won or the game has ended through tie.
	if(checkWin(X_MOVE, board)) {
		cout << "X wins!" << endl;
		xWins++;
		cout << "X has won " << xWins << " times." << endl;
		return true;
	}
	else if(checkWin(O_MOVE, board)) {
		cout << "O wins!" << endl;
		oWins++;
		cout << "O has won " << oWins << " times." << endl;
		return true;
	}
	else if(checkTie(board)) {
		cout << "Tie!" << endl;
		return true;
	}
	return false;
}
		
void clearBoard(int board[3][3]) {
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            board[i][j] = BLANK;
        }
    }
}

