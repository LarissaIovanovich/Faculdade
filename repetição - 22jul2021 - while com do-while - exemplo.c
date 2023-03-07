/*
obtenha 10 numeros inteiros positivos e pares maiores do que 10
e mostre a soma destes números

entradas de dados:
------------------
	conjunto de 10 números numeros inteiros positivos e pares maiores do que 10

saídas de dados:
----------------
	soma dos números lidos
	
processamento:
--------------
1 -	inicializar o contador em 1, e a soma em 0
2 -	enquanto o contador for menor ou igual a 10
3 - 	faça
4 -		  obter um número
5 -		enquanto o número for ímpar OU número for menor do que 10
6 - 	volte para o passo 3
7 - 	a soma recebe ela mesma mais o número lido
8 - 	contador é incrementado em 1
9 - 	volte para o passo 2		

*/
#include <stdio.h>
int main()
{
	int num, soma, cont;
	
	soma = 0;
	cont = 1;	
	
	while(cont <= 10)
	{
		do
		{
			printf("\nDigite um numero PAR maior que 10: ");
			scanf("%d",&num);		
		}while((num % 2 != 0) || (num <= 10));
		soma = soma + num;
		cont = cont + 1;
	}
	printf("\nA soma e %d",soma);
	
	return 0;
}






