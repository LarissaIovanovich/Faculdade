//https://www.inf.ufpr.br/roberto/ci067/14_alocmat.html

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define LIN 4
#define COL 4
/*
Com a alocação de um vetor de ponteiros de linhas separadas, a matriz é vista e alocada 
como um vetor de ponteiros para linhas, que são vetores de elementos. 
O vetor de ponteiros de linhas e os vetores de cada linha devem ser alocados separadamente.

A vantagem deste método é que o acesso aos elementos da matriz usa a mesma 
sintaxe do acesso a uma matriz estática, o que torna a programação mais simples.

                        					 +---+---+---+---+
								+----------------> | 0 | 0 | 0 | 0 |
								|									 +---+---+---+---+
								|									 +---+---+---+---+
								|		+------------> | 1 | 1 | 1 | 1 |
								|		|							 +---+---+---+---+
								|		|							 +---+---+---+---+
								|		|		+--------> | 2 | 2 | 2 | 2 |
								|		| 	|					 +---+---+---+---+
								|		|		|		       +---+---+---+---+
								|		|		|		+----> | 3 | 3 | 3 | 3 | 			
	mat						|   |   |   |      +---+---+---+---+
	+---+       +---+---+---+---+	
	| . | --->  | . | . | . | . | 
	+---+       +---+---+---+---+

*/

int main() {
	int **mat ;
	int i, j ;

// aloca um vetor de LIN ponteiros para linhas
	mat = malloc (LIN * sizeof (int*)) ;

// aloca cada uma das linhas (vetores de COL inteiros)
	for(i = 0;i < LIN; i++)
		mat[i] = malloc (COL * sizeof (int)) ;

// percorre a matriz
	for (i = 0; i< LIN; i++)
		for (j = 0;j < COL; j++)
			mat[i][j] = i;        // acesso com sintaxe mais simples

	for (i = 0;i < LIN; i++) {
		for (j = 0;j < COL; j++)
			printf("%5d",mat[i][j]);
		printf("\n");
	}

// libera a memória da matriz
	for (i = 0; i < LIN; i++)
		free (mat[i]) ;
	free (mat) ;
	return 0;
}
