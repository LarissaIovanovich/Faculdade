/*
https://www.infoescola.com/matematica/medias-aritmetica-geometrica-harmonica/

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
*/
#include <stdio.h>
#include <locale.h>
int main()
{
	setlocale(LC_ALL,"Portuguese");
	float numero, somapeso, somanota, peso;
	int contador, controle;

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
	
	return 0;	
}

