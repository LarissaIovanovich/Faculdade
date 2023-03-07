/*
6) Obter vários grupos de dois números quaisquer, 
e informar (para cada grupo):
a) a soma destes números;
b) a subtração destes números;

entradas de dados:
------------------
	vários grupos de dois números quaisquer

saídas de dados:
----------------
	para cada grupo de dois números:
		soma
		subtração

processamento:
--------------
1 - inicializar a variável de controle em 1
2 - enquanto a variável de controle for igual a 1
3 - obtenha dois números quaisquer
4 - mostre a soma destes números
5 - mostre a subtração destes números
6 - pergunte ao usuário se ele deseja digitar mais um conjunto
			1 para continuar ou 0 para encerrar 
7 - obtenha a resposta do usuário na variável de controle
8 - volte para o passo 2	
*/
#include <stdio.h>
#include <stdlib.h>
int main()
{
	float n1, n2;
	int F; //flag
	
	F = 1;
	while(F == 1)
	{
		printf("\nDigite o primeiro numero: ");
		scanf("%f",&n1);
		printf("\nDigite o segundo numero: ");
		scanf("%f",&n2);
		printf("\nA soma e %0.2f e a subtracao e %0.2f",n1+n2,n1-n2);
		printf("\n\tDeseja continuar? 1 para SIM ou 0 para NAO ");
		scanf("%d",&F);
		system("cls");
	}
	return 0;
}
