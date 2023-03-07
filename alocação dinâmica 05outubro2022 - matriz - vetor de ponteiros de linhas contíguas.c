//https://www.inf.ufpr.br/roberto/ci067/14_alocmat.html

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define LIN 4
#define COL 4
/*
Com a alocação de um vetor de ponteiros de linhas contíguas, a matriz é vista e alocada 
como um vetor de ponteiros para linhas, mas as linhas são alocadas como um único vetor de elementos.
 O vetor de ponteiros de linhas e o vetor de elementos são alocados separadamente.

Além de usar a mesma sintaxe do acesso que o método anterior (mesma que uma matriz estática), 
este método tem mais duas vantagens: 
(i) somente precisa de duas operações de alocação de memória, e 
(ii) todos os elementos da matriz estão alocados sequencialmente na memória, 
o que facilita operações de cópia de matrizes (usando ''memcpy'') 
ou de leitura/escrita da matriz para um arquivo (usando ''fread'' ou ''fwrite'').
                        					 
								+--------------------------------------------------------------------+
								|		+------------------------------------------------+               |
								|		|		+----------------------------+							 |               |
								|		|		|    +-------+ 							 |	             |               |
								|		| 	|	  |			   v							 v	             v               v
								|		|		|		|      +---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+
								|		|		|		|      | 0 | 0 | 0 | 0 | 1 | 1 | 1 | 1 | 2 | 2 | 2 | 2 | 3 | 3 | 3 | 3 | 			
	mat						|   |   |   |      +---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+
	+---+       +---+---+---+---+	
	| . | --->  | . | . | . | . | 
	+---+       +---+---+---+---+


*/


int main()
{
	int **mat ;
	int i, j ;

	srand(time(NULL));

// aloca um vetor de LIN ponteiros para linhas
	mat = malloc (LIN * sizeof (int*)) ;

// aloca um vetor com todos os elementos da matriz
	mat[0] = malloc (LIN * COL * sizeof (int)) ;

// ajusta os demais ponteiros de linhas (i > 0)
	for (i=1; i < LIN; i++)
		mat[i] = mat[0] + i * COL ;

// percorre a matriz
	for (i=0; i < LIN; i++)
		for (j=0; j < COL; j++)
			mat[i][j] = i;

	for (i = 0; i < LIN; i++)
		{
			for (j = 0; j < COL; j++)
				printf("%5d",mat[i][j]);
			printf("\n");
		}

// libera a memória da matriz
	free (mat[0]) ;
	free (mat) ;

	return 0;
}
