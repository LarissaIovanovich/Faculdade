/*
https://www.infoescola.com/matematica/medias-aritmetica-geometrica-harmonica/

*****************************
Média geométrica
*****************************

A média geométrica entre um conjunto de n dados é a raiz n-ésima da multiplicação 
desses dados.

Considere um conjunto de n dados (x1, x2, x3, ..., xn). 
A média geométrica entre estes dados será:

media = raiz n(x1 * x2 * x3 * ... * xn)

OU

          x1 * x2 * x3 * ... * xn
media =  -------------------------
                  1 / n

Calcular a média geométrica para um conjunto de n valores digitados pelo usuário

entradas de dados:
	um conjunto de n valores digitados pelo usuário
saídas de dados:
	média geométrica do conjunto de valores
processamento:
1 - inicializar uma variável produto com 1
2 - inicializar uma variável contador com 0
3 - obter um valor
4 -	a variável produto recebe ela mesma multiplicada pelo valor lido
5 - incrementar o contador em 1
6 - perguntar ao usuário se há outro valor a ser digitado
			caso positivo, retornar ao passo 1
			caso negativo, encerrar o laço/repetição		 
7 - mostrar a raiz do produto, cujo índice será o contador
*/
#include <stdio.h>
#include <locale.h>
#include <math.h>
int main()
{
	setlocale(LC_ALL,"Portuguese");
	float numero, produto;
	int contador, controle;

  printf("\nForneça entre 4 e 10 valores para calcular a média geométrica\n");
	produto = 1;
	contador = 0;
	controle = 1;
	do
	{
		printf("\nDigite o %dº valor para calcular a média geométrica: ",contador+1);
		scanf("%f",&numero);
		produto = produto * numero;
		contador = contador + 1;
		if (contador == 10)
    {
		  break;
	  }
		if (contador > 3)
		{
		  printf("\n\tDeseja digitar outro valor? 1 para SIM ou 2 para NÃO ");
		  scanf("%d",&controle);
	  }
	}while(controle == 1);
	
	printf("\nA média geométrica é %f\n",pow(produto,1.0/contador));	
	
	return 0;	
}

