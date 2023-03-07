/*
5. Escreva um programa em Linguagem C que contenha funções para:
a) Alocar dinamicamente uma matriz (de inteiros) de dimensões
   definidas pelo usuário;
b) Preencher a matriz criada com números randômicos;
c) Receber um valor e retornar 1 caso o valor esteja na matriz
   ou retorne 0 caso não esteja na matriz;
d) Liberar a memória antes de encerrar o programa.

*/
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int **matriz(int, int);
void preenche(int **, int, int);
int procura(int **, int, int, int);
void imprime(int **, int, int);
int **liberarmemoria(int **, int, int);

int main(){
	int num, lin, col, **mat;
	printf("\nInforme a quantidade de linhas para a matriz: ");
	scanf("%d", &lin);
	printf("\nInforme a quantidade de colunas para a matriz: ");
	scanf("%d", &col);
	mat = matriz(lin, col);
	preenche(mat, lin, col);
	imprime(mat, lin, col);
	printf("\nDigite um numero inteiro para verificar se o mesmo esta na matriz: ");
	scanf("%d", &num);
	if(procura(mat, lin, col, num) == 0)
		printf("\nO valor procurado nao esta na matriz\n");
	  else
		  printf("\nO valor procurado esta na matriz\n");
	mat = liberarmemoria(mat, lin, col);
	return 0;
}
int **matriz(int l, int c){
	int **m, i;
	if ((l < 1) || (c < 1)){
		printf ("** Erro: Parametros invalidos **\n");
		return (NULL);
	}
	m = malloc (l * sizeof(int));
	if (m == NULL){
		printf ("** Erro: Memoria Insuficiente **");
		return (NULL);
	}
	for (i = 0; i < l; i = i + 1){
		m[i] = malloc(c * sizeof(int));
		if (m[i] == NULL){
			printf ("** Erro: Memoria Insuficiente **");
			return (NULL);
		}
	}
	return(m);
}
void preenche(int **m, int l, int c){
	int i, j;
	srand(time(NULL));
	for(i = 0; i < l; i = i + 1)
		for(j = 0; j < c; j = j + 1)
			m[i][j] = rand() / 200;
}
int procura(int **m, int l, int c, int n){
	int i, j;
	for(i = 0; i < l; i = i + 1)
		for(j = 0; j < c; j = j + 1)
			if(m[i][j] == n)
				return 1;
	return 0;
}
void imprime(int **m, int l, int c){
	int i, j;
	srand(time(NULL));
	for(i = 0; i < l; i = i + 1) {
		for(j = 0; j < c; j = j + 1)
			printf("%4d",m[i][j]);
		printf("\n");
	}
}
int **liberarmemoria(int **m, int l, int c){
	int  i;
	if (m == NULL)
		return (NULL);
	if ((l < 1) || (c < 1)) {
		printf ("** Erro: Parametros invalidos **\n");
		return (m);
	}
	for (i = 0; i < c; i = i + 1)
		free(m[i]);
	free(m);
	return(m);
}

