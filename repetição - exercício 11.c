/*
11) Obter um valor qualquer e perguntar ao usu�rio 
se este valor � em d�lares ou em reais. Caso sejam
d�lares, convert�-los para reais. Se forem reais, 
convert�-los para d�lares. 
Repetir a opera��o at� que a soma dos valores informados
seja maior do que 10.000,00.

entradas de dados:
	valor que ser� convertido
	cota��o do d�lar
	tipo de moeda do valor
sa�das de dados:
	valor convertido para reais, se o tipo lido for d�lar
	valor convertido para d�lares, se o tipo lido dor real	
processamento:
1 - obter o valor que ser� convertido
2 - somar o valor lido em uma vari�vel de controle
3 - obter a cota��o do d�lar
4 - obter o tipo do valor que ser� convertido
			real ou d�lar
5 - se o tipo for d�lar ent�o
			mostrar o valor lido em reais
		  sen�o
				mostrar o valor lido em d�lares
6 - verificar se a soma na vari�vel de controle	� maior que
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
  while((somareal <= 10000) || (somadolar <= 10000))  // || ou l�gico
   {
  	printf("\nDigite o valor para ser convertido ");
  	scanf("%f",&valor);
  	printf("\nEste valor est� em 1 para D�LAR ou 2 para REAL ");
  	scanf("%d",&tipo);
  	printf("\nDigite a cota��o do d�lar ");
  	scanf("%f",&cotacao);
  	if(tipo == 1)
  	{
  		printf("\n%0.2f D�lares convertidos para Reais � %0.2f",valor, valor*cotacao);
  	  somadolar = somadolar + valor;
    }
			else
			{
  			printf("\n%0.2f Reais convertidos para D�lares � %0.2f",valor, valor/cotacao);
	      somareal = somareal + valor;
	    }
	}

	return 0;
}

