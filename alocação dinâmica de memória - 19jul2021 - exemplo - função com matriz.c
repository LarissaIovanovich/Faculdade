#include <stdio.h>
#include <stdlib.h>

int ** alocamatriz(int, int);
void preenche(int **, int, int);
void imprime(int **, int, int);

int main()
{
	int **matriz;
	int i, linhas, colunas;

	linhas = 5;
	colunas = 5;

	matriz = alocamatriz(linhas, colunas);
	preenche(matriz, linhas, colunas);
	imprime(matriz, linhas, colunas);

//limpando memória
	for(i = 0; i < linhas; i = i + 1)
		free(matriz[i]);
	free(matriz);
	printf("\nFim.");
	return 0;
}

int ** alocamatriz(int lin, int col)
{
	int **m;
	int i;

	if (malloc(lin *sizeof(int)) == NULL)
		{
			printf("\nErro de memoria\n");
			exit(0);
		}

	m = (int **) malloc(lin * sizeof(int));

	for(i = 0; i < lin; i = i + 1)
		{
			if (malloc(col *sizeof(int)) == NULL)
				{
					printf("\nErro de memoria\n");
					exit(0);
				}
			m[i] = (int *) malloc(col * sizeof(int));
		}

	return m;
}

void preenche(int **m, int lin, int col)
{
	int i, j;

	for(i = 0; i < lin; i = i + 1)
		for(j = 0; j < col; j = j + 1)
			{
				printf("Digite um numero para a matriz[%d][%d]: ",i,j);
				scanf("%d",&m[i][j]);
			}
}

void imprime(int **m, int lin, int col)
{
	int i, j;

	for(i = 0; i < lin; i = i + 1)
		{
			for(j = 0; j < col; j = j + 1)
				printf("%d ",m[i][j]);
			printf("\n");
		}
}