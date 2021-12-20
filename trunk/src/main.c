#include "gauss.h"
#include "backsubst.h"
#include "mat_io.h"
#include <stdlib.h>
#include <stdio.h>


int main(int argc, char ** argv) {
	int res;
	Matrix * A = readFromFile(argv[1]); // wczytanie macierzy współczynników - lewa strona równania liniowego
	Matrix * b = readFromFile(argv[2]); // wczytanie macierzy wyrazów wolnych - po prawej stronie równania
	Matrix * x;

	if (A == NULL) // sprawdzanie czy dobrze wczytało macierze
		fprintf(stderr, "Błąd wczytywania macierzy A\n");
		return -1;
	if (b == NULL) 
		fprintf(stderr, "Błąd wczytywania maczierzy B\n");
		return -2;
	printToScreen(A);
	printToScreen(b);

	if( eliminate(A,b) == 1)
		fprintf(stderr,"Błąd! Macierz współczynnik jest osobliwa");
	x = createMatrix(b->r, 1);
	if (x != NULL) 
	{
		res = backsubst(x,A,b);
		if ( res == 1)
			fprintf(stderr,"Błąd! Jeden z elementów na diagonalii wynosi 0");
		else if ( res == 2)
			fprintf(stderr,"Błąd! Nieprawidłowe wymiary macierzy");
		printToScreen(x);
		freeMatrix(x);
	}
       	else 
	{
		fprintf(stderr,"Błąd! Nie mogłem utworzyć wektora wynikowego x.\n");
	}

	freeMatrix(A);
	freeMatrix(b);

	return 0;
}
