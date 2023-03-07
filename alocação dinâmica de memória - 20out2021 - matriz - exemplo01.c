#include <stdio.h>
#include <stdlib.h>
int main()
{
	int linhas, colunas, maislinhas, maiscolunas, i, j;
	int **matriz;

	printf("Informe a quantidade de linhas para a matriz: ");
	scanf("%d",&linhas);
	printf("Informe a quantidade de colunas para a matriz: ");
	scanf("%d",&colunas);

//início da alocação das linhas da matriz
	if(malloc(linhas * sizeof(int)) == NULL)
		{
			printf("\nNao ha memoria suficiente\n");
			exit(0);
		}
	matriz = malloc(linhas * sizeof(int));
//final da alocação das linhas da matriz

//início da alocação das colunas da matriz
	for(i = 0; i < linhas; i = i + 1)
		{
			if(malloc(linhas * sizeof(int)) == NULL)
				{
					printf("\nNao ha memoria suficiente para a linha %d\n",i);
					exit(0);
				}
			matriz[i] = malloc(colunas * sizeof(int));
		}
//final da alocação das colunas da matriz

//preenchimento da matriz
	for(i = 0; i < linhas; i = i + 1)
		for(j = 0; j < colunas; j = j + 1)
			matriz[i][j] = i + j + 1 * 2;

//impressão da matriz
	for(i = 0; i < linhas; i = i + 1)
		{
			for(j = 0; j < colunas; j = j + 1)
				printf("%4d",matriz[i][j]);
      printf("\n");
		}

	printf("Informe quantas linhas serao acrescentadas a matriz: ");
	scanf("%d",&maislinhas);
	printf("Informe quantas colunas serao acrescentadas a matriz: ");
	scanf("%d",&maiscolunas);

//*****************************************************
//ESCREVER O CÓDIGO QUE FAÇA realloc/malloc PARA QUE A
//MATRIZ PASSE A POSSUIR O NOVO TAMANHO
//PREENCHENDO ESTE NOVO ESPAÇO DE MEMÓRIA
//*****************************************************

  free(matriz);		

	return 0;
}
