/*
ALOCAÇÃO DINÂMICA DE MEMÓRIA
----------------------------

Quando declaramos uma variável

int n;

Sabemos que n pode armazenar um único valor, do tipo inteiro,
a cada momento da execução de um programa

Se declaramos

int vetor[10];

Sabemos que vetor pode armazenar dez valores do tipo inteiro,
um em cada uma de suas "posições", ou endereços de memória.
Mesmo assim, da forma como vetor foi declarado ele é estático,
ou seja, não podemos alterar seu tamanho para maior ou menor,
durante a execução do programa, mesmo que possamos acessar
seu conteúdo através de um ponteiro (como vimos anteriormente).

A declaração

int matriz[3][3]

Assemelha-se a descrição do vetor que fizemos acima.

Para o caso de ser necessário utilizar um vetor ou
uma matriz cujo tamanho seja determinado durante
a execução do programa (dinamicamente), utilizamos
o recurso de ALOCAÇÃO DINÂMICA DE MEMÓRIA.
*/
#include <stdio.h>
#include <stdlib.h>
int main()
{
	int **matriz;
//os dois asteriscos (**) estão criando um ponteiro
//duplamente referenciado, no caso da matriz
//um ponteiro para as linhas e outro para as colunas
	int lin, col, i, j;

	printf("\nAloca dinamicamente uma matriz de inteiros\n");
	printf("\nInforme a quantidade de linhas da matriz: ");
	scanf("%d",&lin);
	printf("\nInforme a quantidade de colunas da matriz: ");
	scanf("%d",&col);

//primeiro devemos alocar as linhas da matriz
	matriz = malloc(lin * sizeof(int));
	/*
	aloca as linhas da matriz, para o caso de 3 linhas
	temos:
	  +----+
	0 |    |
	  +----+
	1 |    |
	  +----+
	2 |    |
	  +----+
	sendo que cada uma destas "células" da matriz são
	ponteiros que vão apontar para as colunas da matriz
	*/

//devemos alocar as colunas da matriz, utilizando
//uma estrutura de repetição
	for(i = 0; i < lin; i = i + 1)
		matriz[i] = malloc(col * sizeof(int));
	/*
	aloca as colunas da matriz, para o caso de 3 colunas
	temos:           0    1    2
	  +----+      +----+----+----+
	0 |    | -->  |    |    |    |
	  +----+      +----+----+----+
	1 |    | -->  |    |    |    |
	  +----+      +----+----+----+
	2 |    | -->  |    |    |    |
	  +----+      +----+----+----+
	*/

	for(i = 0; i < lin; i = i + 1)
		for(j = 0; j < col; j = j + 1)
			matriz[i][j] = i + j + 4;

	for(i = 0; i < lin; i = i + 1)
		{
			for(j = 0; j < col; j = j + 1)
				printf("%4d ",matriz[i][j]);
			printf("\n");
		}
	return 0;
}