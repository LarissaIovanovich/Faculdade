/*
https://www.infoescola.com/matematica/medias-aritmetica-geometrica-harmonica/
=========================================================================================
*****************************	
Média aritmética simples
*****************************	
A média aritmética simples é obtida dividindo a soma de todos os valores que 
temos pela quantidade de valores.

         x1 + x2 + x3 + ... + xn
media = -------------------------
                  n

Calcular a média aritmética para um conjunto de n valores digitados pelo usuário

entradas de dados:
	um conjunto de n valores digitados pelo usuário
saídas de dados:
	média aritmética do conjunto de valores
processamento:
1 - inicializar uma variável soma com 0
2 - inicializar uma variável contador com 0
3 - obter um valor
4 -	adicionar o valor obtido a variavel soma
5 - incrementar o contador em 1
6 - perguntar ao usuário se há outro valor a ser digitado
			caso positivo, retornar ao passo 1
			caso negativo, encerrar o laço/repetição		 
7 - mostrar a soma dividida pelo contador (média aritmética simples)
=========================================================================================
*****************************
Média aritmética ponderada
*****************************
A média ponderada considera “pesos” para cada item, ou seja, em um conjunto de dados, 
cada item recebe uma importância (x1, x2, x3, ..., xn).
Dado um conjunto com n dados (x1, x2, x3, ..., xn), no qual cada dado receberá um peso, 
respectivamente (p1, p2, p3, ..., pn), cada item será multiplicado pelo seu peso. 
A média será dada pela divisão entre esta soma e a soma dos pesos considerados. 

         x1 * p1 + x2 * p2 + x3 * p3 + ... + xn * pn
media = ---------------------------------------------
                p1 + p2 + p3 + ... + pn

Calcular a média ponderada para um conjunto de n valores digitados pelo usuário

entradas de dados:
	um conjunto de n valores digitados pelo usuário, sendo que cada valor possui um peso
saídas de dados:
	média ponderada do conjunto de valores
processamento:
1 - inicializar uma variável somapeso com 0
2 - inicializar uma variável somanota com 0
3 - inicializar uma variável contador com 1
4 - obter um valor
5 - obter um pesso correspondente ao valor
6 -	adicionar o valor obtido multiplicado pelo peso a variavel somanota
7 - adcionar o peso obtido a variável somapeso
8 - incrementar o contador em 1
9 - perguntar ao usuário se há outro valor a ser digitado
			caso positivo, retornar ao passo 1
			caso negativo, encerrar o laço/repetição		 
10 - mostrar a somanota dividida por somapeso (média ponderada)
=========================================================================================
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
=========================================================================================
*****************************
Média harmônica
*****************************                  
A média harmônica de um conjunto de n dados é obtida dividindo a quantidade de 
dados pela soma dos inversos dos dados.
Considerando um conjunto de n dados (x1, x2, x3, ..., xn), a média harmônica 
entre esses dados será:

                     n
media = -----------------------------
          1     1     1           1
         --- + --- + --- + ... + ---
          x1    x2    x3          xn    
   
Calcular a média harmónica para um conjunto de n valores digitados pelo usuário

entradas de dados:
	um conjunto de n valores digitados pelo usuário
saídas de dados:
	média harmônica do conjunto de valores
processamento:
1 - inicializar uma variável soma com 0
2 - inicializar uma variável contador com 0
3 - inicializar uma variável controle com 1
4 - obter um valor
5 -	adicionar 1 dividido pelo valor obtido soma
6 - incrementar o contador em 1
7 - perguntar ao usuário se há outro valor a ser digitado
			caso positivo, retornar ao passo 1
			caso negativo, encerrar o laço/repetição		 
10 - mostrar a media harmônica (contador / soma)  
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
		printf("\nCalcular médias");
		printf("\n---------------");
		printf("\n1 - Média Artimética");
		printf("\n2 - Média Ponderada");
		printf("\n3 - Média Geométrica");
		printf("\n4 - Média Harmônica");
		printf("\n5 - Sair\n");
		scanf("%d",&opt);
		switch (opt)
		{
			case 1:
  			printf("\nForneça entre 4 e 10 valores para calcular a média aritmética\n");
				soma = 0;
				contador = 0;
				controle = 1;
				do
				{
					printf("\nDigite o %dº valor para calcular a média aritmética: ",contador+1);
					scanf("%f",&numero);
					soma = soma + numero;
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
				printf("\nA média aritmética é %f\n",soma/contador);			
				system("pause");	
				break;
			case 2:
  			printf("\nForneça entre 4 e 10 valores com seus pesos para calcular a média ponderada\n");
				somanota = 0;
				somapeso = 0;
				contador = 0;
				controle = 1;
				do
				{
					printf("\nDigite o %dº valor para calcular a média ponderada: ",contador+1);
					scanf("%f",&numero);
					printf("\nDigite o peso do %dº valor: ",contador+1);
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
					  printf("\n\tDeseja digitar outro valor? 1 para SIM ou 2 para NÃO ");
					  scanf("%d",&controle);
				  }
				}while(controle == 1);
				printf("\nA média ponderada é %f\n",somanota/somapeso);		
				system("pause");			
				break;
			case 3:
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
				system("pause");				
			break;
			case 4:
  			printf("\nForneça entre 4 e 10 valores para calcular a média harmônica\n");
				soma = 0;
				contador = 0;
				controle = 1;
				do
				{
					printf("\nDigite o %dº valor para calcular a média harmônica: ",contador+1);
					scanf("%f",&numero);
					soma = soma + 1.0 / numero;
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
				printf("\nA média harmônica é %f\n",contador/soma);				
				system("pause");	
				break;
			case 5:
				system("cls");
			  break;	
			default:
				printf("\nOpção incorreta!\n");
				system("pause");
		}
	}while(opt != 5);
	return 0;
}

