#include "backsubst.h"
#include <stdio.h>
/**
 * Zwraca 0 - wsteczne podstawienie zakonczone sukcesem
 * Zwraca 1 - błąd dzielenia przez 0 (element na diagonali = 0)
 * Zwraca 2 - błąd nieprawidłowych rozmiarów macierzy
 */
int  backsubst(Matrix *x, Matrix *mat, Matrix *b) {

	printToScreen(mat);

	if(mat->r != b->r)
		return 2;

	for(int i=0; i< mat->r; i++)
	{
		if( mat->data[i][i] == 0)
			return 1;
	}
	
	for( int w= mat->c-1; w>=0; w--) // od końca do początku macierzy do wierszach
	{	
		double suma = 0;
		for(int k = w+1; k< mat->c; k++) // od k+1-tego elementu w wierszu
		{
			suma += mat->data[w][k]*x->data[k][0];
		}
		printf("Suma to: %lf\n", suma);
		x->data[w][0] = (b->data[w][0] - suma) / mat->data[w][w];
	}

return 0;
}


