/*
13 - Escreva um programa que calcule e escreva o valor de S:
      1      3      5      7           99   (este é X)
s = ---- + ---- + ---- + ---- + ... + ----
      1      2      3      4           50   (este é Y)

entradas de dados:
	não há
saídas de dados:
	valor de S - soma da série
processamento:
	inicializar x em 1
	inicializar y em 1
	inicializar soma em 0
	enquanto y for menor ou igual a 50
		soma = soma + x / y
		incrementar x em 2
		incrementar y em 1
	mostrar o valor da soma	
*/
#include <stdio.h>
#include <locale.h>
int main()
{
	setlocale(LC_ALL,"Portuguese");
	
	float soma, x, y;
	
	x = 1;
	y = 1;
	soma = 0;
	
	while(y <= 50)
	{
		soma = soma + x / y;
		x = x + 2;
		y = y + 1;
	}
	printf("\nA soma é %f",soma);

	return 0;
}
