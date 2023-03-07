#include <stdio.h>
#include <stdlib.h>

void preenche_vetor(int *, int);
void imprime_vetor(int *, int, char *);
int * aloca_vetor(int);
int * realoca_vetor(int *, int);

int main()
{
	int *vetor;
	int tamanho, mais, i;
	
	printf("\n\nQual a quantidade de elementos para o vetor? ");
	scanf("%d",&tamanho);
	
  vetor = aloca_vetor(tamanho);
  preenche_vetor(vetor, tamanho);
	imprime_vetor(vetor, tamanho,"\nPrimeiro Vetor\n");	
				
	printf("\n\nQuantos elementos serao acrescentados ao vetor? ");
	scanf("%d",&mais);			

  vetor = realoca_vetor(vetor,tamanho+mais);
  preenche_vetor(vetor, tamanho+mais);
	imprime_vetor(vetor, tamanho+mais,"\nSegundo Vetor\n");
	
	vetor = NULL;
	free(vetor);
						
	return 0;
}

void preenche_vetor(int *v, int q)
{
	int i;
	for(i = 0;i < q;i = i + 1)
		v[i] = i + 1 * 2;	
}

void imprime_vetor(int *v, int q, char *texto)
{
	int i;
	printf("%s",texto);
	for(i = 0;i < q;i = i + 1)
		printf("%d ",v[i]);	
}

int * aloca_vetor(int q)
{
	int *v;
	if (malloc(q * sizeof(int)) == NULL)
	{
		printf("\nNao ha memoria suficiente\n");
		exit(0);
	}
	v = malloc(q * sizeof(int));
	return v;
}

int * realoca_vetor(int *v, int q)
{
	if (realloc(v,q * sizeof(int)) == NULL)
	{
		printf("\nNao ha memoria suficiente\n");
		exit(0);
	}
	v = realloc(v,q * sizeof(int));
	return v;	
}

