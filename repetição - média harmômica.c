/*
https://www.infoescola.com/matematica/medias-aritmetica-geometrica-harmonica/

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
*/          
#include <stdio.h>
#include <locale.h>
int main()
{
	setlocale(LC_ALL,"Portuguese");
	float numero, soma;
	int contador, controle;

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
	
	return 0;	
}

