/*
11) Obter um valor qualquer e perguntar ao usuário 
se este valor é em dólares ou em reais. Caso sejam
dólares, convertê-los para reais. Se forem reais, 
convertê-los para dólares. 
Repetir a operação até que a soma dos valores informados
seja maior do que 10.000,00.

entradas de dados:
	valor que será convertido
	cotação do dólar
	tipo de moeda do valor
saídas de dados:
	valor convertido para reais, se o tipo lido for dólar
	valor convertido para dólares, se o tipo lido dor real	
processamento:
1 - obter o valor que será convertido
2 - somar o valor lido em uma variável de controle
3 - obter a cotação do dólar
4 - obter o tipo do valor que será convertido
			real ou dólar
5 - se o tipo for dólar então
			mostrar o valor lido em reais
		  senão
				mostrar o valor lido em dólares
6 - verificar se a soma na variável de controle	é maior que
			10.000,00
			caso negativo, repetir os passos 1, 2, 3, 4, 5, 6
			caso positivo, encerrar a estrutura							

*/
#include <stdio.h>
#include <locale.h>
int main()
{
	setlocale(LC_ALL,"Portuguese");
  float valor, somareal, somadolar, cotacao;
  int tipo;
  somareal = 0;
  somadolar = 0;
  while((somareal <= 10000) || (somadolar <= 10000))  // || ou lógico
   {
  	printf("\nDigite o valor para ser convertido ");
  	scanf("%f",&valor);
  	printf("\nEste valor está em 1 para DÓLAR ou 2 para REAL ");
  	scanf("%d",&tipo);
  	printf("\nDigite a cotação do dólar ");
  	scanf("%f",&cotacao);
  	if(tipo == 1)
  	{
  		printf("\n%0.2f Dólares convertidos para Reais é %0.2f",valor, valor*cotacao);
  	  somadolar = somadolar + valor;
    }
			else
			{
  			printf("\n%0.2f Reais convertidos para Dólares é %0.2f",valor, valor/cotacao);
	      somareal = somareal + valor;
	    }
	}

	return 0;
}

