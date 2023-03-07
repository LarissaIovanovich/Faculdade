/*
LT04_EX01: Faça um programa em Linguagem C que peça 5 números reais. 
Depois, o programa deve apresentar o número maior.
*/
#include <stdio.h>
int main()
{
	float numeros[5], maior;
	int i;
	
	for(i = 0;i < 5;i = i + 1)
	{
		printf("\nDigite um numero para a posicao %d do vetor: ",i);
		scanf("%f",&numeros[i]);
	}
	
	for(maior = numeros[0], i = 1;i < 5;i = i + 1)
	{
		if(numeros[i] > maior)
		{
			maior = numeros[i];
		}
	}
	
	printf("\nO maior numero e %0.1f",maior);	
	
	return 0;
}
