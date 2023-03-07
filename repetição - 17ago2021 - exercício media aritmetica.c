/*
calcular a média artimética simples para um grupo entre
4 e 10 valores digitados pelo usuário.
*/
#include <stdio.h>
int main()
{
	float soma, numero, media;
	int contador, opcao;
	
	soma = 0;
	contador = 0;
	opcao = 1;
	
	while(opcao == 1)
	{
		printf("\nDigite um numero para calcular a media: ");
		scanf("%f",&numero);
		soma = soma + numero;
		contador = contador + 1;
		if((contador >= 4) && (contador < 10))
		{
			printf("\nDeseja digitar mais um numero? 1 para SIM ou 2 para NAO: ");
			scanf("%d",&opcao);		
		}	
		if(contador == 10)
		{
			opcao = 2;
		}		
	}
	media = soma / contador;
	printf("\nA media aritmetica e %0.2f",media);
	
	return 0;
}