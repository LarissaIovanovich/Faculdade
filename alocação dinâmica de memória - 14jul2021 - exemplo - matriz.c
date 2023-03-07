#include <stdio.h>
#include <stdlib.h>

int ** alocamatriz(int, int); //parâmetros - linha e coluna
void imprimematriz(int**, int, int); //parâmetros - matriz, linhas, colunas

int main()
{
	int **matriz;
//**matriz - significa que esta variável é duplamente referenciada,
//					 ou seja, há um ponteiro para as linhas e outro
//					 para as colunas
//				   Desta forma, primeiro alocamos as linhas da matriz,
//					 e depois em uma estrutura de repetição, suas colunas;

	int linhas, colunas, i, j;

	printf("\nInforme a quantidade de linhas para a matriz: ");
	scanf("%d", &linhas);
	printf("\nInforme a quantidade de colunas para a matriz: ");
	scanf("%d", &colunas);

	matriz = alocamatriz(linhas, colunas);

	for(i = 0; i < linhas; i = i + 1)
		for(j = 0; j < colunas; j = j + 1)
			matriz[i][j] = i + j + 3;

  imprimematriz(matriz, linhas, colunas);

	for(i = 0; i < linhas; i = i + 1)
		free(matriz[i]);

	free(matriz);

	return 0;
}

int ** alocamatriz(int lin, int col)
{
	int **m;
	int i;

	if (malloc(lin * sizeof(int)) == NULL)
		{
			printf("\nNao ha memoria suficiente para as linhas da matriz\n");
			exit(0);
		}

	m = malloc(lin * sizeof(int));

	for(i = 0; i < lin; i = i + 1)
		{
			if (malloc(col * sizeof(int)) == NULL)
				{
					printf("\nNao ha memoria suficiente para as linhas da matriz\n");
					exit(0);
				}
			m[i] = malloc(col * sizeof(int));
		}

	return m;
}

void imprimematriz(int **m, int lin, int col)
{
	int i, j;
	for(i = 0; i < lin; i = i + 1)
		{
			for(j = 0; j < col; j = j + 1)
				printf("%3d",m[i][j]);
			printf("\n");
		}
}


