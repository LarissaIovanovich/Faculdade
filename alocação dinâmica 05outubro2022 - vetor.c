#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
	int *vetor, dimensao, i;

	srand(time(NULL));
	
	printf("\nQual a dimensao do vetor? ");
	scanf("%d",&dimensao);
	
	vetor = malloc(dimensao * sizeof(int));
	
	for(i = 0;i < dimensao;i = i + 1)
	  vetor[i] = rand()/100+1;
	  
	for(i = 0;i < dimensao;i = i + 1)
	  printf("%d ",vetor[i]);  
	
	vetor = realloc(vetor, dimensao * 2 * sizeof(int));
	
	printf("\n\n");
	
	for(;i < dimensao*2;i = i + 1)
	  vetor[i] = rand()/100+1;
	
	for(i = 0;i < dimensao*2;i = i + 1)
	  printf("%d ",vetor[i]);  

	free(vetor);	
	
	return 0;
}