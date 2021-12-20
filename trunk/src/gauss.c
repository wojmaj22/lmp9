#include "gauss.h"
#include <stdio.h>

/**
 * Zwraca 0 - elimnacja zakonczona sukcesem
 * Zwraca 1 - macierz osobliwa - dzielenie przez 0
 */
int eliminate(Matrix *matrix, Matrix *b){

	int i,j,k;
	double x = 0;

	for(j = 0; j < mat->c; j++)
		for(i = 0; i < mat->r; i++)
        		if(i > j) {
            			if(mat->data[j][j] == 0)
                			return 1;
        		}
	return 0;
}
