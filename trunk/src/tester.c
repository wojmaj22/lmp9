#include "gauss.h"
#include "backsubst.h"
#include "mat_io.h"
#include <stdio.h>
#include <stdlib.h>
void test1(Matrix *A, Matrix *b, Matrix *x, char *plik)
{
	FILE *in = fopen( plik, "r");
	eliminate(A,b);
	x = createMatrix(b->r, 1);
	backsubst(x,A,b);
	double wynik;
	for(int i=0;i< b->r; i++)
	{
		fscanf( in, "%lf", &wynik);
		if( x->data[i][0] != wynik)
			printf("Test niepomyślny - zły wynik obliczeń, błąd w linii %i.\n", i);
			break;
	}
	printf("Program działa poprawnie - wyniki zgodne z oczekiwanymi\n");
}
void test2(Matrix *A, Matrix *b, Matrix *x)
{
	int res;
	eliminate(A,b);
	res = backsubst(x, A, b);
	if(res = 2)
		printf("Złe wymiary macierzy - macierz niekwadratowa o wymiarach %ix%i\n", A->r, A->c);
}
void test3( Matrix *A, Matrix *b, Matrix *x)
{
	int res;
	res = eliminate(A,b);
	if( res == 1)
	{
		printf("Błąd - macierz osobliwa,dzielenie przez zero\n");
		exit(1);
	}
	x = createMatrix(b->r, 1);
	res = backsubst(x,A,b);
	if ( res == 1)
	{
		printf("Błąd - dzielenie przez zero, element zerowy na diagonali.\n");
		exit(1);
	}
	printf("Działanie zakończono poprawnie\n");
}

int main(int argc, char **argv)
{
	Matrix *A = readFromFile(argv[2]);	
	Matrix *b = readFromFile(argv[3]);
	Matrix *x;
	int wybor = atoi(argv[1]);

	FILE *in = fopen( argv[2], "r");
	int w,k;
	double buf;
	fscanf( in, "%d %d", &w, &k);
	if( w != A->r || k != A->c)
	{
		printf("Błąd wczytywania rozmiarów\n");
		return 1;
	}
	for( int i=0; i<w; i++)
	{
		for( int j=0; j<k; j++)
		{
			fscanf( in, "%lf", &buf);
			if( buf != A->data[i][j])
			{
				printf("Błąd wczytywania macierzy\n");
				return 1;
			}
		}
	}
	printf("Dane wczytano poprawnie, test działania programu\n");

	switch( wybor )
	{
	case 1:
		test1(A,b,x, argv[4]);
		break;
	case 2:
		test2(A,b,x);
		break;
	case 3:
		test3(A,b,x);
		break;
	}
return 0;
}
