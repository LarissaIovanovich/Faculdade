/*
01 - Escreva um programa em Linguagem C que:
	a) Faça a alocação dinâmica de memória para duas matrizes de números
		 inteiros com dimensão 4 linhas por 4 colunas (Matriz A e Matriz B);
	b) Preencha as duas matrizes com números inteiros positivos entre 2 e 20;
	c) Escreva uma função que receba as duas matrizes definidas no item a),
		 e que retorne uma terceira matriz (Resultante) com o resultado da multiplicação delas;
	d) Mostre na tela as matrizes A, B e a Resultante.

 Devem existir funções para:

	* Alocar dinamicamente a memória para uma matriz;
	* Limpar a memória do conteúdo alocado dinamicamente, antes de encerrar o programa;
	* Preencher uma matriz;
	* Mostrar o conteúdo de uma matriz na tela.
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int ** alocar_matriz(int, int);
int ** liberar_matriz(int **, int, int);
void preencher_matriz(int **, int, int);
void imprimir_matriz(int **, int, int);
int ** multiplica_matriz(int **, int **, int);

int main()
{
	int **A, **B, **Resultante;

	srand(time(NULL));

	A = alocar_matriz(4,4);
	B = alocar_matriz(4,4);
	preencher_matriz(A,4,4);
	preencher_matriz(B,4,4);
	Resultante = multiplica_matriz(A,B,4);
	printf("\nMatriz A\n");
	imprimir_matriz(B,4,4);
	printf("\nMatriz B\n");
	imprimir_matriz(A,4,4);
	printf("\nMatriz Resultante\n");	
	imprimir_matriz(Resultante,4,4);
	A = liberar_matriz(A,4,4);
	B = liberar_matriz(B,4,4);
	Resultante = liberar_matriz(Resultante,4,4);

	return 0;
}

int ** alocar_matriz(int linhas, int colunas)
{
	int ** matriz;
	int i, j;

	if (malloc(linhas * sizeof(int)) == NULL)
		{
			printf("\nNao ha memoria suficiente para as linhas da matriz\n");
			exit(0);
		}
	matriz = malloc(linhas * sizeof(int));
	for(i = 0; i < linhas; i = i + 1)
		{
			if (malloc(colunas * sizeof(int)) == NULL)
				{
					printf("\nNao ha memoria suficiente para as linhas da matriz\n");
					exit(0);
				}
			matriz[i] = malloc(colunas * sizeof(int));
		}
	return matriz;
}

int ** liberar_matriz(int **matriz, int linhas, int colunas)
{
	int i;

	if(*matriz==NULL)
		return NULL;

	if((linhas < 1) || (colunas < 1))
		return matriz;
			
	for(i = 0; i < linhas; i = i + 1)
		{
			free(matriz[i]);
		}
	free(matriz);
	return NULL;
}

void preencher_matriz(int **matriz, int linhas, int colunas)
{
	int i, j;
	for(i = 0; i < linhas; i = i + 1)
		for(j = 0; j < colunas; j = j + 1)
			do
				{
					matriz[i][j] = rand()/1000;
				}
			while((matriz[i][j] < 2) || (matriz[i][j] > 20));
}

void imprimir_matriz(int **matriz, int linhas, int colunas)
{
	int i, j;
	for(i = 0; i < linhas; i = i + 1)
		{
			for(j = 0; j < colunas; j = j + 1)
				printf("%4d",matriz[i][j]);
			printf("\n");
		}
}

int ** multiplica_matriz(int **A, int **B, int D)
{
	int **R;
	int i, j, k;

  R = alocar_matriz(D,D);

	for(i = 0; i < D; i = i + 1)
		for(j = 0; j < D; j = j + 1)
			{
				R[i][j] = 0;
				for(k = 0; k < D; k = k + 1)
					R[i][j] = R[i][j] + A[i][k] * B[k][j];
			}

	return R;
}
