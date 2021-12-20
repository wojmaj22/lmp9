#include "gauss.h"
#include <stdio.h>

/**
 * Zwraca 0 - elimnacja zakonczona sukcesem
 * Zwraca 1 - macierz osobliwa - dzielenie przez 0
 */

int eliminate(Matrix *matrix, Matrix *b){

	int i,j,k;
	double x = 0;

	for(j = 0; j <= mat->c; j++)
		for(i = 0; i <= mat->r; i++)
        		if(i > j) {
            			if(mat->data[j][j] == 0)
                			return 1;

                		x = mat->data[i][j] / mat->data[j][j];
                		b->data[i][0] = b->data[i][0] - x * b->data[j][0]

                		for(k = 0; k <= mat->r; k++)
                    			mat->data[i][k] = mat->data[i][k] - x * mat->data[j][k];
        		}
	return 0;
}
