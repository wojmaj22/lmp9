#include "gauss.h"
#include "backsubst.h"
#include "mat_io.h"
#include <stdlib.h>
#include <stdio.h>


int main(int argc, char ** argv) {
	int res; // co to za zmienna?
	Matrix * A = readFromFile(argv[1]); // wczytanie macierzy współczynników - lewa strona równania liniowego
	Matrix * b = readFromFile(argv[2]); // wczytanie macierzy wyrazów wolnych - po prawej stronie równania
	Matrix * x;

	if (A == NULL) // sprawdzanie czy dobrze wczytało macierze
		return -1;
	if (b == NULL) 
		return -2;
	printToScreen(A);
	printToScreen(b);

	res = eliminate(A,b);
	x = createMatrix(b->r, 1);
	if (x != NULL) 
	{
		res = backsubst(x,A,b);
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
