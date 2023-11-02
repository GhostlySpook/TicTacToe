// Primer programa en C++.

#include<iostream> //Librería de entrada y salida de datos.
#include<stdlib.h>

using namespace std;
char tablero[3][3] = {{'1','2','3'},{'4','5','6'},{'7','8','9'}}; 
char turno = 'X';
int cursor; //guarda la posición que eligue el usuario.
bool onGoing = true; //mantiene el juego andando.

void mostrarTablero() { // Grafica el tablero del juego.
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (j == 2) {
				cout << tablero[i][j] << endl;
			}
			else {
				cout << tablero[i][j] << " | ";
			}
			
		}
		if (i < 2) {
			cout << "---------" << endl;
		}
	}
}

char posicionMatriz(int numero) { //devuelve el valor que hay en una posición del tablero
	switch (numero) {
		case 1: return tablero[0][0];
		case 2: return tablero[0][1];
		case 3: return tablero[0][2];
		case 4: return tablero[1][0];
		case 5: return tablero[1][1];
		case 6: return tablero[1][2];
		case 7: return tablero[2][0];
		case 8: return tablero[2][1];
		case 9: return tablero[2][2];
	}
}

void cambiarTurno() { //cambia el turno
	if (turno == 'X') {
		turno = 'O';
	}
	else {
		turno = 'X';
	}
}

bool yaEscrito() { //Verifica si la posición donde se escribe está vacia.
	if (posicionMatriz(cursor) == 'X' || posicionMatriz(cursor) == 'O') {
		return true;
	}
	else {
		return false;
	}
}

void escribirMatriz(int cursor) { //Escribe en la posición que se indica en la matriz.
	switch (cursor) {
		case 1: tablero[0][0] = turno;
			break;
		case 2: tablero[0][1] = turno;
			break;
		case 3: tablero[0][2] = turno;
			break;
		case 4: tablero[1][0] = turno;
			break;
		case 5: tablero[1][1] = turno;
			break;
		case 6: tablero[1][2] = turno;
			break;
		case 7: tablero[2][0] = turno;
			break;
		case 8: tablero[2][1] = turno;
			break;
		case 9: tablero[2][2] = turno;
			break;
	}
	
}

bool verificarGanador() { //Busca si hay ganador.
	if ((posicionMatriz(1) == turno && posicionMatriz(2) == turno && posicionMatriz(3) == turno) ||  //chequea fila 1
		(posicionMatriz(4) == turno && posicionMatriz(5) == turno && posicionMatriz(6) == turno) ||  //chequea fila 2
		(posicionMatriz(7) == turno && posicionMatriz(8) == turno && posicionMatriz(9) == turno) ||  //chequea fila 3

		(posicionMatriz(1) == turno && posicionMatriz(4) == turno && posicionMatriz(7) == turno) ||  //chequea columna 1
		(posicionMatriz(2) == turno && posicionMatriz(5) == turno && posicionMatriz(8) == turno) ||  //chequea columna 2
		(posicionMatriz(3) == turno && posicionMatriz(6) == turno && posicionMatriz(9) == turno) ||  //chequea columna 3

		(posicionMatriz(1) == turno && posicionMatriz(5) == turno && posicionMatriz(9) == turno) ||  //chequea diagonal izquierda
		(posicionMatriz(3) == turno && posicionMatriz(5) == turno && posicionMatriz(7) == turno))    //chequea diagonal derecha
	{ 
		return true;
	}
	else {
		return false;
	}
}

void pasarTurno() { //Verifica que se cumplan las condiciones para avanzar.

	if (cursor < 1 || cursor > 9 || yaEscrito()) {
		cout << "\n Lugar Invalido! Presiona una tecla para volver a intentarlo ";
		getchar(); //Evita que tome la tecla anterior y no se lea el mensaje.
		getchar();
	}
	else {
		escribirMatriz(cursor);
		if (verificarGanador()) {
			onGoing = false;
		}
		else {
			cambiarTurno();
		}
	}
}

int main() {
	while (onGoing) {
		cout << "TIC TAC TOE: Turno de " << turno << endl;
		mostrarTablero();
		cout << "Escoje un lugar: ";
		cin >> cursor;
		pasarTurno();
		system("cls");
	}
	mostrarTablero();
	cout << "Ganador: " << turno << endl;

	return 0;

}
