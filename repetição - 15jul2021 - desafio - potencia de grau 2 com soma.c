/*
A potêncio de grau 2 de um número pode ser definida como
a soma de todos os números inteiros positivos ímpares, começando em
1, na mesma quantidade do número cuja potência se deseja saber.

Exemplo:
--------
5^2 (5 ao quadrado) 1 + 3 + 5 + 7 + 9 = 25
3^2 (3 ao quadrado) 1 + 3 + 5 = 9

Escreva um programa que receba um número do usuário e mostre
sua potência de grau 2 e a soma dos números correspondentes:

5 ao quadrado = 1 + 3 + 5 + 7 + 9 = 25

entradas de dados:
------------------
	um número inteiro

saídas de dados:
----------------
	a potência de grau 2 deste número

processamento:
--------------
	obter um número inteiro
	iniciar uma variável de controle em 1
	iniciar uma variável de soma1 em 1
	iniciar uma variável de somatotal em 1;
	mostre na tela o valor da variável número + " ao quadrado = "
	enquanto a variável de controle for menor ou igual ao número lido
		mostre na tela o valor da variável soma1 + " + "
		a variável soma1 é incrementada em 2
		a variável somatotal recebe ela mesma mais a variável soma1
		a variável de controle é incrementada em 1
  mostre na tela o valor da variável somatotal
*/
#include <stdio.h>
int main()
{
	int num, cont, soma1, somatotal;
	soma1 = 1;
	somatotal = 1;

	printf("\nDigite um numero para calcular sua potencia de grau 2: ");
	scanf("%d",&num);

  printf("%d ao quadrado = ",num);
	for(cont = 1; cont < num;cont = cont + 1)
		{
			printf("%d",soma1);
			if(cont < num-1)
				printf(" + ");
			soma1 = soma1 + 2;
			somatotal = somatotal + soma1;
		}
	printf(" = %d",somatotal);
	return 0;
}
