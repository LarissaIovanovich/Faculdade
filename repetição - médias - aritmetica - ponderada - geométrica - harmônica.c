/*
https://www.infoescola.com/matematica/medias-aritmetica-geometrica-harmonica/
=========================================================================================
*****************************	
M�dia aritm�tica simples
*****************************	
A m�dia aritm�tica simples � obtida dividindo a soma de todos os valores que 
temos pela quantidade de valores.

         x1 + x2 + x3 + ... + xn
media = -------------------------
                  n

Calcular a m�dia aritm�tica para um conjunto de n valores digitados pelo usu�rio

entradas de dados:
	um conjunto de n valores digitados pelo usu�rio
sa�das de dados:
	m�dia aritm�tica do conjunto de valores
processamento:
1 - inicializar uma vari�vel soma com 0
2 - inicializar uma vari�vel contador com 0
3 - obter um valor
4 -	adicionar o valor obtido a variavel soma
5 - incrementar o contador em 1
6 - perguntar ao usu�rio se h� outro valor a ser digitado
			caso positivo, retornar ao passo 1
			caso negativo, encerrar o la�o/repeti��o		 
7 - mostrar a soma dividida pelo contador (m�dia aritm�tica simples)
=========================================================================================
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
=========================================================================================
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
=========================================================================================
*****************************
M�dia harm�nica
*****************************                  
A m�dia harm�nica de um conjunto de n dados � obtida dividindo a quantidade de 
dados pela soma dos inversos dos dados.
Considerando um conjunto de n dados (x1, x2, x3, ..., xn), a m�dia harm�nica 
entre esses dados ser�:

                     n
media = -----------------------------
          1     1     1           1
         --- + --- + --- + ... + ---
          x1    x2    x3          xn    
   
Calcular a m�dia harm�nica para um conjunto de n valores digitados pelo usu�rio

entradas de dados:
	um conjunto de n valores digitados pelo usu�rio
sa�das de dados:
	m�dia harm�nica do conjunto de valores
processamento:
1 - inicializar uma vari�vel soma com 0
2 - inicializar uma vari�vel contador com 0
3 - inicializar uma vari�vel controle com 1
4 - obter um valor
5 -	adicionar 1 dividido pelo valor obtido soma
6 - incrementar o contador em 1
7 - perguntar ao usu�rio se h� outro valor a ser digitado
			caso positivo, retornar ao passo 1
			caso negativo, encerrar o la�o/repeti��o		 
10 - mostrar a media harm�nica (contador / soma)  
=========================================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>
int main()
{
	setlocale(LC_ALL,"Portuguese");
	
	float numero, soma, produto, somapeso, somanota, peso;
	int contador, controle, opt;

	do
	{
		system("cls");
		printf("\nCalcular m�dias");
		printf("\n---------------");
		printf("\n1 - M�dia Artim�tica");
		printf("\n2 - M�dia Ponderada");
		printf("\n3 - M�dia Geom�trica");
		printf("\n4 - M�dia Harm�nica");
		printf("\n5 - Sair\n");
		scanf("%d",&opt);
		switch (opt)
		{
			case 1:
  			printf("\nForne�a entre 4 e 10 valores para calcular a m�dia aritm�tica\n");
				soma = 0;
				contador = 0;
				controle = 1;
				do
				{
					printf("\nDigite o %d� valor para calcular a m�dia aritm�tica: ",contador+1);
					scanf("%f",&numero);
					soma = soma + numero;
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
				printf("\nA m�dia aritm�tica � %f\n",soma/contador);			
				system("pause");	
				break;
			case 2:
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
				system("pause");			
				break;
			case 3:
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
				system("pause");				
			break;
			case 4:
  			printf("\nForne�a entre 4 e 10 valores para calcular a m�dia harm�nica\n");
				soma = 0;
				contador = 0;
				controle = 1;
				do
				{
					printf("\nDigite o %d� valor para calcular a m�dia harm�nica: ",contador+1);
					scanf("%f",&numero);
					soma = soma + 1.0 / numero;
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
				printf("\nA m�dia harm�nica � %f\n",contador/soma);				
				system("pause");	
				break;
			case 5:
				system("cls");
			  break;	
			default:
				printf("\nOp��o incorreta!\n");
				system("pause");
		}
	}while(opt != 5);
	return 0;
}

