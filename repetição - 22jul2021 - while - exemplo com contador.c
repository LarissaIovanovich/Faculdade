/*
estrutura de repetição:
-----------------------

permite a execução repetidamente de um grupo de comandos
ENQUANTO uma condição for verdadeira

CONDIÇÃO é uma expressão lógica, que contém uma ou mais
variáveis que permitem o "controle" da estrutura de repetição

Uma variável de controle precisa ter um valor inicial e,
consecutivamente, ser alterada até um valor final

WHILE (enquanto):
--------------------------

o WHILE executa um grupo de comandos, ENQUANTO sua condição
de controle for verdadeira.

Os comandos da estrutura serão executados 0 ou n vezes,
uma vez que o teste da condição de controle(expressão lógica)
é executado no início da estrutura.

sintaxe:
--------

while (condição)
{
<comandos>
}

while - é a estrutura de repetição
condição - é expressão lógica que controla o início e o final
					 da estrutura de repetição. 
<comandos> - são os comandos que serão executados, repetidamente,
						 pela estrutura, ENQUANTO a condição for VERDADEIRA. 
						 Estão aninhados em um bloco delimitado por chaves {  }. 
						 São executados sempre após a verificação da condição.

*/
//=============================================
/*
Obter um número inteiro do usuário e mostrar a tabuada padrão
deste número na tela

entradas de dados:
------------------
	um número inteiro
	
saídas de dados:
----------------
	tabuada do número lido:
		2 x 1 = 2
		2 x 2 = 4
		2 x 3 = 6
		...
		2 x 10 = 20
		
processamento:
--------------
1 - obter um número inteiro
2 -	inicializar a variável de controle em 1			
3 -	enquanto a variável de controle for menor ou igual a 10
4 -	  imprima o numero, a variável de controle, e o número * variável de controle
5 -	  incremente a variável de controle em 1
6 -	  volte para o passo 3

*/
#include <stdio.h>
int main()
{
	int num, cont;
	
	printf("\nDigite um numero inteiro para a tabuada: ");
	scanf("%d",&num);

	cont = 11;
	while (cont <= 10)
	{
		printf("\n%2d X %2d = %2d",num, cont, num * cont);
		cont = cont + 1;	
	}
		
	return 0;
}
