//https://www.inf.ufpr.br/roberto/ci067/14_alocmat.html

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define LIN 4
#define COL 4
/*

Com a alocação única, os elementos da matriz são alocados em um único vetor, linearmente. 
Os elementos da matriz são acessados explicitamente através de aritmética de ponteiros.

	mat
	+---+				+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+
	| . | ---> 	| 0 | 0 | 0 | 0 | 1 | 1 | 1 | 1 | 2 | 2 | 2 | 2 | 3 | 3 | 3 | 3 |
	+---+       +---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+

*/
int main() {
	int *mat ;
	int i, j ;
	
	srand(time(NULL));

// aloca um vetor com todos os elementos da matriz
	mat = malloc (LIN * COL * sizeof (int)) ;

// percorre a matriz
	for (i=0; i < LIN; i++)
		for (j=0; j < COL; j++)
			mat[(i*COL) + j] = i;  // calcula a posição de cada elemento

// libera a memória alocada para a matriz

	for (i=0; i < LIN; i++)
	{
		for (j=0; j < COL; j++)
			printf("%5d",mat[(i*COL) + j]);
		printf("\n");
	}

	free (mat) ;

	return 0;
}
