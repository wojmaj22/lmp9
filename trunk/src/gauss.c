#include "gauss.h"
#include <stdio.h>

/**
 * Zwraca 0 - elimnacja zakonczona sukcesem
 * Zwraca 1 - macierz osobliwa - dzielenie przez 0
 */
int eliminate(Matrix *matrix, Matrix *b){
	int wiersze = matrix -> r;
	int kolumny = matrix -> c;
	double **A = matrix->data;

	for( int k=0; k < kolumny-1; k++)
	{
		for( int w=k+1; w < wiersze; w++)
		{
			printf("Zmiana eletentu [%i][%i]\n", w, k);
			double wsp = A[w][k] / A[0][k];
			printf("WSP = %lf", wsp);
			for( int i=0; i< kolumny; i++)
			{
				A[w][i] -= wsp*A[0][i];
			}
			b->data[w][0] -= wsp*b->data[0][0];
		}
	}

	printToScreen(matrix);
	printf("Koniec Gaussa\n");

return 0;
}

