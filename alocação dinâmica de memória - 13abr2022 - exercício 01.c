/*
1 - Escreva um programa em Linguagem C que:
a) Aloque dinamicamente um vetor de inteiros com dimensão 10;
b) Obtenha uma sequência indefinida de números inteiros positivos:
	  i. Cada número digitado deve ser armazenado no vetor criado no item a);
	 ii. Se o usuário digitar mais de 10 números, o programa deve realocar
		 	 espaço de memória para o vetor, suficiente para armazenar mais 10 números
			 inteiros, e assim sucessivamente até que a sequência de números seja finalizada;
	iii. Esta sequência é finalizada quando o usuário digitar 0 (zero)
			 (o valor 0 não deve ser armazenado).
c) No final, todos os dados digitados deverão ser mostrados na tela,
	 com o uso de uma função para imprimir o vetor.

*/
#include <stdio.h>
#include <stdlib.h>
void imprime_vetor(int *, int);
int main()
{
	int *vetor, qtd, i, num;
	vetor = malloc(10 * sizeof(int));
	i = 0;
	do
		{
			do
				{
					printf("\ndigite um numero inteiro positivo (0 para finalizar): ");
					scanf("%d",&num);
				}
			while(num < 0);
			if(num != 0)
				{
					vetor[i] = num;
					i = i + 1;
					if(i % 10 == 0)
						vetor = realloc(vetor,(i+10)*sizeof(int));
				}
		}
	while(num != 0);
	if(i!=0)
		{
			printf("\nos numeros que foram digitados sao:\n");
			imprime_vetor(vetor,i);
		}
	free(vetor);	
	return 0;
}
void imprime_vetor(int *v, int q)
{
	int i;
	for(i = 0; i < q; i = i + 1)
		printf("%d ",v[i]);
}