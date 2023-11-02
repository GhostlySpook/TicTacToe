#pragma once

class Tictactoe {

private:
	char tablero[3][3] = { {'1','2','3'},{'4','5','6'},{'7','8','9'} };
	char turno = 'X';
	int cursor; //Saves the position that the user inputs.
	bool onGoing = true; //Keeps the game ongoing.
	void mostrarTablero();
	char posicionMatriz(int numero);
	void cambiarTurno();
	bool yaEscrito();
	void escribirMatriz(int cursor);
	bool verificarGanador();
	void pasarTurno();

public:
	void iniciarJuego();

};