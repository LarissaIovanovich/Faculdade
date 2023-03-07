/*
https://www.infoescola.com/matematica/medias-aritmetica-geometrica-harmonica/

*****************************
M�dia geom�trica
*****************************

A m�dia geom�trica entre um conjunto de n dados � a raiz n-�sima da multiplica��o 
desses dados.

Considere um conjunto de n dados (x1, x2, x3, ..., xn). 
A m�dia geom�trica entre estes dados ser�:

media = raiz n(x1 * x2 * x3 * ... * xn)

OU

          x1 * x2 * x3 * ... * xn
media =  -------------------------
                  1 / n

Calcular a m�dia geom�trica para um conjunto de n valores digitados pelo usu�rio

entradas de dados:
	um conjunto de n valores digitados pelo usu�rio
sa�das de dados:
	m�dia geom�trica do conjunto de valores
processamento:
1 - inicializar uma vari�vel produto com 1
2 - inicializar uma vari�vel contador com 0
3 - obter um valor
4 -	a vari�vel produto recebe ela mesma multiplicada pelo valor lido
5 - incrementar o contador em 1
6 - perguntar ao usu�rio se h� outro valor a ser digitado
			caso positivo, retornar ao passo 1
			caso negativo, encerrar o la�o/repeti��o		 
7 - mostrar a raiz do produto, cujo �ndice ser� o contador
*/
#include <stdio.h>
#include <locale.h>
#include <math.h>
int main()
{
	setlocale(LC_ALL,"Portuguese");
	float numero, produto;
	int contador, controle;

  printf("\nForne�a entre 4 e 10 valores para calcular a m�dia geom�trica\n");
	produto = 1;
	contador = 0;
	controle = 1;
	do
	{
		printf("\nDigite o %d� valor para calcular a m�dia geom�trica: ",contador+1);
		scanf("%f",&numero);
		produto = produto * numero;
		contador = contador + 1;
		if (contador == 10)
    {
		  break;
	  }
		if (contador > 3)
		{
		  printf("\n\tDeseja digitar outro valor? 1 para SIM ou 2 para N�O ");
		  scanf("%d",&controle);
	  }
	}while(controle == 1);
	
	printf("\nA m�dia geom�trica � %f\n",pow(produto,1.0/contador));	
	
	return 0;	
}

