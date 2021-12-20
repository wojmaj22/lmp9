#include "gauss.h"
#include <math.h>
#include <stdio.h>

/**
 * Zwraca 0 - elimnacja zakonczona sukcesem
 * Zwraca 1 - macierz osobliwa - dzielenie przez 0
 */

int eliminate(Matrix *mat, Matrix *b){

        int i, j, k, l, m, rzad = -1;
        double x = 0, tmp1 = 0, tmp2 = 0;

        for(j = 0; j < mat->c; j++) {

                for(l = j; l < mat->r - 1; l++)
                        if(fabs(mat->data[l + 1][j]) > fabs(mat->data[l][j]))
                                rzad = l + 1;

                if(rzad != -1) {
                        for(m = 0; m < mat->c; m++) {
                                tmp1 = mat->data[j][m];
                                mat->data[j][m] = mat->data[rzad][m];
                                mat->data[rzad][m] = tmp1;
                        }
                        tmp2 = b->data[j][0];
                        b->data[j][0] = b->data[rzad][0];
                        b->data[rzad][0] = tmp2;

                        rzad = -1;
                }

                if(mat->data[j][j] == 0) {
                        printf("Macierz osobliwa - element [%.0d, %.0d], dzielenie przez 0\n", j + 1, j + 1);
                        return 1;
                }

                for(i = j + 1; i < mat->r; i++) {
                        x = mat->data[i][j] / mat->data[j][j];
                        b->data[i][0] = b->data[i][0] - x * b->data[j][0];

                        for(k = 0; k < mat->r; k++)
                                mat->data[i][k] = mat->data[i][k] - x * mat->data[j][k];
                }
        }

        return 0;
}
