#include <stdio.h>
#include <stdlib.h>

int * alocavetor(int);
void preenche(int *, int);
void imprime(int *, int);

int main()
{
	int *vetor;
	int qtd, i;

	qtd = 10;

	vetor = alocavetor(qtd);
	preenche(vetor, qtd);
	imprime(vetor, qtd);

  free(vetor);

	return 0;
}

int * alocavetor(int q)
{
	int *v;

	if (malloc(q *sizeof(int)) == NULL)
		{
			printf("\nErro de memoria\n");
			exit(0);
		}

	v = (int *) malloc(q * sizeof(int));

	return v;
}

void preenche(int *v, int q)
{
	int i;

	for(i = 0; i < q; i = i + 1)
		{
			printf("Digite um numero para a posicao %d do vetor: ",i);
			scanf("%d",&v[i]);
		}
}

void imprime(int *v, int q)
{
	int i;

	for(i = 0; i < q; i = i + 1)
		printf("%d ",v[i]);
}
