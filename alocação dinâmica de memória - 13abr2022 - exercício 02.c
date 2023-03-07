/*
2 - Escreva um programa em Linguagem C que contenha funções para:
	a) Alocar dinamicamente uma matriz (de inteiros) de dimensões definidas pelo usuário;
	b) Preencher a matriz criada com números randômicos;
	c) Receber um valor e retornar 1 caso o valor esteja na matriz
	 	 ou retorne 0 caso não esteja na matriz;
	d) Liberar a memória antes de encerrar o programa.
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int ** aloca_matriz(int, int); //linhas e colunas para alocar a matriz
void imprime_matriz(int **, int, int);
void preenche_matriz(int **, int, int); //matriz, linhas e colunas para preencher a matriz
int procura(int **, int, int, int); //matriz, linhas e colunas, valor que será procurado na matriz

int **Liberar_matriz(int **, int, int);

int main()
{
	srand(time(NULL));
	int **mat;
	int linhas, colunas, p;
	printf("\nPreenche uma matriz alocada dinamicamente, com inteiros gerados randomicamente\n");
	printf("\nQual a quantidade de linhas para a matriz? ");
	scanf("%d",&linhas);
	printf("\nQual a quantidade de colunas para a matriz? ");
	scanf("%d",&colunas);
	mat = aloca_matriz(linhas, colunas);
	preenche_matriz(mat, linhas, colunas);
	imprime_matriz(mat, linhas, colunas);
	printf("\nInforme um numero para ser procurado na matriz: ");
	scanf("%d",&p);
	if(procura(mat, linhas, colunas, p))
		printf("\nO numero procurado esta na matriz\n");
	else
		printf("\nO numero procurado nao esta na matriz\n");

  printf("\nconteudo de mat %x",mat);
			
	mat = Liberar_matriz(mat,linhas,colunas);

  printf("\nconteudo de mat %x",mat);
			
	return 0;
}
int ** aloca_matriz(int lin, int col) //linhas e colunas para alocar a matriz
{
	int **matriz;
	int i;
	matriz = malloc(lin * sizeof(int));
	for(i = 0; i < lin; i = i + 1)
		matriz[i] = malloc(col * sizeof(int));
	return matriz;
}
void imprime_matriz(int **matriz, int lin, int col)
{
	int i, j;
	for(i = 0; i < lin; i = i + 1)
		{
			for(j = 0; j < col; j = j + 1)
				printf("%3d ",matriz[i][j]);
			printf("\n");	
		}
}
void preenche_matriz(int **matriz, int lin, int col) //matriz, linhas e colunas para preencher a matriz
{
	int i, j;
	for(i = 0; i < lin; i = i + 1)
		for(j = 0; j < col; j = j + 1)
			matriz[i][j] = rand()/100;
}
int procura(int **matriz, int lin, int col, int p) //matriz, linhas e colunas, valor que será procurado na matriz
{
	int i, j;
	for(i = 0; i < lin; i = i + 1)
		for(j = 0; j < col; j = j + 1)
			if(matriz[i][j] == p)
				return 1;
	return 0;
}

//*********************************************************
//Função para liberar linhas e colunas da matriz
//*********************************************************
int **Liberar_matriz(int **mat, int lin, int col)
{
	int  i;  /* variavel auxiliar */
	
	if(mat == NULL)
		return(NULL);
	
	if ((lin < 1) || (col < 1)) {  /* verifica parametros recebidos */
		printf("** Erro: Parametros incorretos **\n");
		return(mat);
	}
	
	for(i = 0; i < lin; i = i + 1)
		free(mat[i]); /* libera as linhas da matriz */
	
	free(mat);       /* libera a matriz */
	
	return(NULL); /* retorna um ponteiro nulo */
}

