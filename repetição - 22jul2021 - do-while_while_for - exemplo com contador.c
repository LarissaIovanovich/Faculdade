/*
estrutura de repetição:
-----------------------

permite a execução repetidamente de um grupo de comandos
ENQUANTO uma condição for verdadeira

CONDIÇÃO é uma expressão lógica, que contém uma ou mais
variáveis que permitem o "controle" da estrutura de repetição

Uma variável de controle precisa ter um valor inicial e,
consecutivamente, ser alterada até um valor final

DO ... WHILE (faça ... enquanto):
---------------------------------

DO ... WHILE executa um grupo de comandos, ENQUANTO sua condição
de controle for verdadeira.

Os comandos da estrutura serão executados 1 ou n vezes,
uma vez que o teste da condição de controle(expressão lógica)
é executado no final da estrutura.

sintaxe:
--------

do
{
<comandos>
}while (condição);

do - é o começo da estrutura de repetição
while - é o ponto de verificação da condição da estrutura de repetição
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
3 - imprima o numero, a variável de controle, e o número * variável de controle
4 -	incremente a variável de controle em 1
5 -	enquanto a variável de controle for menor ou igual a 10, 
6 -	volte para o passo 4

*/
#include <stdio.h>
int main()
{
	int num, cont;
	
	printf("\nDigite um numero inteiro para a tabuada: ");
	scanf("%d",&num);
	
//= DO ... WHILE ================================================================	
	printf("\n\ndo ... while \n");
	cont = 1;
	do
	{
		printf("\n%2d X %2d = %2d",num, cont, num * cont);
		cont = cont + 1;	
	}while (cont <= 10);
	
//= WHILE ================================================================	
	printf("\n\nwhile \n");	
	cont = 1;
	while (cont <= 10)
	{
		printf("\n%2d X %2d = %2d",num, cont, num * cont);
		cont = cont + 1;	
	}		
	
//= FOR ================================================================	
	printf("\n\nfor \n");		
	for(cont = 1; cont <= 10; cont = cont + 1)
		{
			printf("\n%2d X %2d = %2d",num, cont, num*cont);
		}
//=================================================================			
				
	return 0;
}