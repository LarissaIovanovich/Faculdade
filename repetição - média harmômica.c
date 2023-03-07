/*
https://www.infoescola.com/matematica/medias-aritmetica-geometrica-harmonica/

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
*/          
#include <stdio.h>
#include <locale.h>
int main()
{
	setlocale(LC_ALL,"Portuguese");
	float numero, soma;
	int contador, controle;

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
	
	return 0;	
}

