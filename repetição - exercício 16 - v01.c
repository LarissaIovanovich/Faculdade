/*
16 - Escreva um programa que calcule e escreva o valor de S:
      1      2      3      4     5       6        -10   (este � X)
s = ---- - ---- + ---- - ---- + ---- - ---- ... + ----
      1      4      9     16     25      36        100  (este � X^2)
      
entradas de dados:
	n�o h�
sa�das de dados:
	valor de S - resultado da s�rie
processamento
	inicializar x em 1
	inicializar soma em 0
	inicializar sinal em 1 (quando sinal for 1 - adi��o
													quando sinal for 2 - subtra��o)					
	enquanto x for menor ou igual a 9
		se sinal for igual a 1 ent�o
			soma = soma + x / (x * x)
			sinal = 2 (alterar o valor da vari�vel sinal para 2)
			sen�o
				soma = soma - x / (x * x)
				sinal = 1 (alterar o valor da vari�vel sinal para 1)
		incrementar x em 1
	soma = soma + -x / (x * x)	
	mostrar o valor da soma
*/
#include <stdio.h>
#include <locale.h>
int main()
{
	setlocale(LC_ALL,"Portuguese");
	float soma, x;
	int sinal;
	
	x = 1;
	soma = 0;
	sinal = 1;
	
	while(x <= 9)
	{
		if(sinal == 1)
		{
			soma = soma + x / (x * x);
			sinal = 2;
		}
		else
		{
			soma = soma - x / (x * x);
			sinal = 1;
		}
		x = x + 1;
	}
	soma = soma + -x / (x * x);

  printf("\n16 - Escreva um programa que calcule e escreva o valor de S:");
  printf("\n      1      2      3      4     5       6        -10   (este � X)");
  printf("\ns = ---- - ---- + ---- - ---- + ---- - ---- ... + ----");
  printf("\n      1      4      9     16     25      36        100  (este � X^2)");
  printf("\n\nA soma � %f",soma);

	return 0;
}

