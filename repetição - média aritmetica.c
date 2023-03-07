/*
https://www.infoescola.com/matematica/medias-aritmetica-geometrica-harmonica/

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
*/
#include <stdio.h>
#include <locale.h>
int main()
{
	setlocale(LC_ALL,"Portuguese");
	float numero, soma;
	int contador, controle;

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
	
	return 0;	
}

