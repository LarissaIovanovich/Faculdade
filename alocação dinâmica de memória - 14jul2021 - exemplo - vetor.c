#include <stdio.h>
#include <stdlib.h>

int * aloca_vetor(int); //recebe a quantidade de elementos para a alocaço dinâmica do vetor
												//devolve, como retorno,o endereço do vetor alocado
												
int * realoca_vetor(int *, int);//recebe o endereço do vetor original 
																//recebe a quantidade de elementos para a realocação, o novo tamanho do vetor
																//devolve, como retorno,o endereço do vetor realocado
																													
int main()
{
	int *vetor;
	int i, Q;
/*
*vetor - indica que a variável vetor é um ponteiro para o tipo inteiro, ou seja ela armazena
				 um endereço de memória, e não um valor explicitamente inteiro
*/	

  printf("\nQuantos elementos tera o vetor? ");
  scanf("%d",&Q);
    
  vetor = aloca_vetor(Q);
	
	for(i = 0;i < Q;i = i + 1)
		vetor[i] = i + 2;
	
	printf("\nPrimeiro vetor\n");
	
	for(i = 0;i < Q;i = i + 1)
		printf("%d ",vetor[i]);

  printf("\nQuantos elementos tera o novo vetor? ");
  scanf("%d",&Q);

	vetor = realoca_vetor(vetor,Q);
	
	for(;i < Q;i = i + 1)
		vetor[i] = i + 3;
	
	printf("\nSegundo vetor\n");
	for(i = 0;i < Q;i = i + 1)
		printf("%d ",vetor[i]);
		
	free(vetor);	
		
	return 0;
}

int * aloca_vetor(int qtd)
{
	int *v;
	
  if (malloc(qtd * sizeof(int)) == NULL)
  {
  	printf("\nNao ha memoria suficiente\n");
  	exit(0);
	}		
	
	v = malloc(qtd * sizeof(int));
	 
	return v; 
}

int * realoca_vetor(int * v, int qtd)
{
  if (realloc(v, qtd * sizeof(int)) == NULL)
  {
  	printf("\nNao ha memoria suficiente para realloc\n");
    return NULL;
	}		
	
	v = realloc(v, qtd *  sizeof(int));
	
	return v;	
}
