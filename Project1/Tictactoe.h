#pragma once
#include<iostream>
#include<stdlib.h>
#include<conio.h>

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