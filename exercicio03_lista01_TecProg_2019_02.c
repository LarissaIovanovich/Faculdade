/*
3. Escreva um programa em Linguagem C que:
a) Aloque dinamicamente um vetor de inteiros com dimens�o 10;
b) Obtenha uma sequ�ncia indefinida de n�meros inteiros positivos:
	i. Cada n�mero digitado deve ser armazenado no vetor criado no item a);
	ii. Se o usu�rio digitar mais de 10 n�meros, o programa deve realocar 
		espa�o de mem�ria para o vetor, suficiente para armazenar mais 10 
		n�meros inteiros, e assim sucessivamente at� que a sequ�ncia de 
		n�meros seja finalizada;
	iii. Esta sequ�ncia � finalizada quando o usu�rio digitar 0 (zero) 
		(o valor 0 n�o deve ser armazenado).
c) No final, todos os dados digitados dever�o ser salvos em um arquivo 
	texto, um valor em cada linha.

*/
#include <stdio.h>
#include <stdlib.h>

int main(){
	FILE *arq;
	int *vetor, q, i, num;
	
	vetor = malloc(10 * sizeof(int));
	if(vetor == NULL){
		printf("\nNao ha memoria para alocacao do vetor\n");
		exit(0);
	}
	i = 0;
	q = 0;
	do{
		do{
			printf("\nDigite um numero inteiro positivo (0 para finalizar) ");
			scanf("%d",&num);
		}while(num < 0);
		if(num > 0){
			vetor[i] = num;
			i = i + 1;
			q = q + 1;
			if(q == 10){
				vetor = realloc(vetor, (i + 10) * sizeof(int));
				q = 0;
			}
		}
	}while(num != 0);
	
	arq = fopen("exercicio03.txt","w");
	for(q = 0;q < i;q = q + 1){
		fprintf(arq,"%d\n",vetor[q]);
	}

	fclose(arq);
	free(vetor);	
	
	return 0;
}