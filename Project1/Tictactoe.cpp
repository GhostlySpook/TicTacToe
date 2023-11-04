// First Program on C++.

#include<iostream>
#include<stdlib.h>
#include<conio.h>

using namespace std;

class Tictactoe {

private:
	char board[3][3] = { {'1','2','3'},{'4','5','6'},{'7','8','9'} };
	char turn = 'X';
	int cursor; //Saves the position that the user inputs.
	bool onGoing = true; //Keeps the game ongoing.
	bool thereIsWinner = false;
	void showBoard();
	char matrixPosition(int number);
	void passTurn();
	bool checkFullMatrix();
	bool alreadyWritten();
	void writeOnMatrix(int cursor);
	bool checkWinner();
	void checkPosition();
	
public:
	void launchGame();

};

void Tictactoe::launchGame() {
	while (onGoing) {
		cout << "TIC TAC TOE: Turno de " << turn << endl;
		showBoard();
		cout << "Escoje un lugar: ";
		cin >> cursor;
		checkPosition();
		system("cls");
	}
	showBoard();
	if (thereIsWinner) {
		cout << "Ganador: " << turn << endl;
	}
	else {
		cout << "Empate";
	}

}

void Tictactoe::showBoard() {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (j == 2) {
				cout << board[i][j] << endl;
			}
			else {
				cout << board[i][j] << " | ";
			}

		}
		if (i < 2) {
			cout << "---------" << endl;
		}
	}
}

char Tictactoe::matrixPosition(int number) {
	switch (number) {
	case 1: return board[0][0];
	case 2: return board[0][1];
	case 3: return board[0][2];
	case 4: return board[1][0];
	case 5: return board[1][1];
	case 6: return board[1][2];
	case 7: return board[2][0];
	case 8: return board[2][1];
	case 9: return board[2][2];
	default: return board[0][0];
	}
}

void Tictactoe::passTurn() {
	if (turn == 'X') {
		turn = 'O';
	}
	else {
		turn = 'X';
	}
}

bool Tictactoe::alreadyWritten() {
	if (matrixPosition(cursor) == 'X' || matrixPosition(cursor) == 'O') {
		return true;
	}
	else {
		return false;
	}
}

void Tictactoe::writeOnMatrix(int cursor) {
	switch (cursor) {
	case 1: board[0][0] = turn;
		break;
	case 2: board[0][1] = turn;
		break;
	case 3: board[0][2] = turn;
		break;
	case 4: board[1][0] = turn;
		break;
	case 5: board[1][1] = turn;
		break;
	case 6: board[1][2] = turn;
		break;
	case 7: board[2][0] = turn;
		break;
	case 8: board[2][1] = turn;
		break;
	case 9: board[2][2] = turn;
		break;
	}

}

bool Tictactoe::checkFullMatrix() {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (board[i][j] != 'X' && board[i][j] != 'O') {
				return false;
			}
		}
	}
	return true;
}

bool Tictactoe::checkWinner() {
	if ((matrixPosition(1) == turn && matrixPosition(2) == turn && matrixPosition(3) == turn) || 
		(matrixPosition(4) == turn && matrixPosition(5) == turn && matrixPosition(6) == turn) || 
		(matrixPosition(7) == turn && matrixPosition(8) == turn && matrixPosition(9) == turn) ||  

		(matrixPosition(1) == turn && matrixPosition(4) == turn && matrixPosition(7) == turn) ||  
		(matrixPosition(2) == turn && matrixPosition(5) == turn && matrixPosition(8) == turn) ||  
		(matrixPosition(3) == turn && matrixPosition(6) == turn && matrixPosition(9) == turn) ||  

		(matrixPosition(1) == turn && matrixPosition(5) == turn && matrixPosition(9) == turn) ||  
		(matrixPosition(3) == turn && matrixPosition(5) == turn && matrixPosition(7) == turn))    
	{
		thereIsWinner = true;
		return true;
	}
	else if (checkFullMatrix()) {
		return true;
	}
	else {
		return false;
	}
}

void Tictactoe::checkPosition() {

	if (cursor < 1 || cursor > 9 || alreadyWritten()) {
		cout << "\n Invalid position. Please press a key to continue. ";
		getchar(); 
		getchar();
	}
	else {
		writeOnMatrix(cursor);
		if (checkWinner()) {
			onGoing = false;
		}
		else {
			passTurn();
		}
	}
}

