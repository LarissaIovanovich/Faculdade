#include <stdio.h>
#include <stdlib.h>

int * aloca_vetor(int); //recebe a dimensão tamanho do vetor
//que será alocado e retorna
//um ponteiro com o endereço
//deste vetor
int ** aloca_matriz(int, int); //recebe as dimensões da matriz
//que será alocada e retorna
//um ponteiro com o endereço
//deste matriz
void preenche_vetor(int *, int);
void imprime_vetor(int *, int);
void preenche_matriz(int **, int, int);
void imprime_matriz(int **, int, int);

int main()
{
	int *meuvetor;
	int **matriz;
	int lin, col, i, j;

	printf("\nQual a dimensao do vetor que sera alocado: ");
	scanf("%d",&i);
	meuvetor = aloca_vetor(i);
	preenche_vetor(meuvetor, i);
	printf("\nVetor\n");
	imprime_vetor(meuvetor,i);

	printf("\n\nQual a dimensao das linhas da matriz que sera alocada: ");
	scanf("%d",&lin);
	printf("\nQual a dimensao das coluna da matriz que sera alocada: ");
	scanf("%d",&col);	
	matriz = aloca_matriz(lin,col);
	preenche_matriz(matriz,lin,col);
	printf("\nMatriz\n");
	imprime_matriz(matriz,lin,col);

	return 0;
}

int * aloca_vetor(int dim)
{
	int *vetor;

	vetor = malloc(dim * sizeof(int));
	return vetor;
}

void preenche_vetor(int *vet, int dim)
{
	int i;
	for(i = 0; i < dim; i = i + 1)
		vet[i] = 3 + i;
}

void imprime_vetor(int *vet, int dim)
{
	int i;
	for(i = 0; i < dim; i = i + 1)
		printf("%4d",vet[i]);
}

int ** aloca_matriz(int lin, int col)
{
	int **matriz;
	int i;

	matriz = malloc(lin * sizeof(int));

	for(i = 0; i < lin; i = i + 1)
		matriz[i] = malloc(col * sizeof(int));

	return matriz;
}

void preenche_matriz(int **mat, int lin, int col)
{
	int i, j;
	for(i = 0; i < lin; i = i + 1)
		for(j = 0; j < col; j = j + 1)
			mat[i][j] = i + j + 3;
}

void imprime_matriz(int **mat, int lin, int col)
{
	int i, j;
	for(i = 0; i < lin; i = i + 1)
		{
			for(j = 0; j < col; j = j + 1)
				printf("%4d",mat[i][j]);
			printf("\n");
		}
}


