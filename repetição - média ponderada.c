/*
https://www.infoescola.com/matematica/medias-aritmetica-geometrica-harmonica/

*****************************
M�dia aritm�tica ponderada
*****************************

A m�dia ponderada considera �pesos� para cada item, ou seja, em um conjunto de dados, 
cada item recebe uma import�ncia (x1, x2, x3, ..., xn).
Dado um conjunto com n dados (x1, x2, x3, ..., xn), no qual cada dado receber� um peso, 
respectivamente (p1, p2, p3, ..., pn), cada item ser� multiplicado pelo seu peso. 
A m�dia ser� dada pela divis�o entre esta soma e a soma dos pesos considerados. 

         x1 * p1 + x2 * p2 + x3 * p3 + ... + xn * pn
media = ---------------------------------------------
                p1 + p2 + p3 + ... + pn

Calcular a m�dia ponderada para um conjunto de n valores digitados pelo usu�rio

entradas de dados:
	um conjunto de n valores digitados pelo usu�rio, sendo que cada valor possui um peso
sa�das de dados:
	m�dia ponderada do conjunto de valores
processamento:
1 - inicializar uma vari�vel somapeso com 0
2 - inicializar uma vari�vel somanota com 0
3 - inicializar uma vari�vel contador com 1
4 - obter um valor
5 - obter um pesso correspondente ao valor
6 -	adicionar o valor obtido multiplicado pelo peso a variavel somanota
7 - adcionar o peso obtido a vari�vel somapeso
8 - incrementar o contador em 1
9 - perguntar ao usu�rio se h� outro valor a ser digitado
			caso positivo, retornar ao passo 1
			caso negativo, encerrar o la�o/repeti��o		 
10 - mostrar a somanota dividida por somapeso (m�dia ponderada)
*/
#include <stdio.h>
#include <locale.h>
int main()
{
	setlocale(LC_ALL,"Portuguese");
	float numero, somapeso, somanota, peso;
	int contador, controle;

  printf("\nForne�a entre 4 e 10 valores com seus pesos para calcular a m�dia ponderada\n");
	somanota = 0;
	somapeso = 0;
	contador = 0;
	controle = 1;
	do
	{
		printf("\nDigite o %d� valor para calcular a m�dia ponderada: ",contador+1);
		scanf("%f",&numero);
		printf("\nDigite o peso do %d� valor: ",contador+1);
		scanf("%f",&peso);
		somanota = somanota + numero * peso;
		somapeso = somapeso +peso;
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
	
	printf("\nA m�dia ponderada � %f\n",somanota/somapeso);	
	
	return 0;	
}

