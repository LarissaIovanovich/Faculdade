/*
https://www.infoescola.com/matematica/medias-aritmetica-geometrica-harmonica/

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
*/
#include <stdio.h>
#include <locale.h>
int main()
{
	setlocale(LC_ALL,"Portuguese");
	float numero, soma;
	int contador, controle;

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
	
	return 0;	
}

