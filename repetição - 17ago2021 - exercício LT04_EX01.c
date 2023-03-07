/*
LT04_EX01: Faça um programa em Linguagem C que peça 5 números reais. 
Depois, o programa deve apresentar o número maior.
*/
#include <stdio.h>
int main()
{
	float numeros[5], maior;
	int i;
	
	i = 0;
	while(i < 5)
	{
		printf("\nDigite um numero para a posicao %d do vetor: ",i);
		scanf("%f",&numeros[i]);
		i = i + 1;		
	}
	
	maior = numeros[0];
	i = 1;
	while(i < 5)
	{
		if(numeros[i] > maior)
		{
			maior = numeros[i];
		}
		i = i + 1;
	}
	
	printf("\nO maior numero e %0.1f",maior);	
	
	return 0;
}
