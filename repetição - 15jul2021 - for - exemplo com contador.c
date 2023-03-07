/*
estrutura de repetição:
-----------------------

permite a execução repetidamente de um grupo de comandos
ENQUANTO uma condição for verdadeira

CONDIÇÃO é uma expressão lógica, que contém uma ou mais
variáveis que permitem o "controle" da estrutura de repetição

Uma variável de controle precisa ter um valor inicial e,
consecutivamente, ser alterada até um valor final

laço contado - FOR (PARA):
--------------------------

o FOR executa um grupo de comandos, enquanto sua condição
de controle for verdadeira.

sintaxe:
--------

for(inicialização ; condição ; incremento/decremento)
{
<comandos>
}

for - é a estrutura de repetição
inicialização - "área" na qual uma ou mais variáveis podem
								ser inicializadas. Os comandos nesta área
								são os primeiros a serem executados no FOR,
								e são executados apenas uma vez.
condição - é expressão lógica que controla o início e o final
					 da estrutura de repetição. É verificada logo
					 após a inicialização, e sempre após o incremento
					 e/ou decremento de variáveis.
inc/dec - neste local é realizado o incremento e/ou o decremento
					do valor da(s) variável(is) de controle da estrutura.
					É executado sempre após a finalização dos <comandos>.
<comados> - são os comandos que serão executados, repetidamente,
						pela estrutura. Estão aninhados em um bloco delimitado
						por chaves {  }. São executados sempre após a verificação
						da condição.

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
	int numero, contador;

	printf("\nDigite um numero inteiro para a tabuada: ");
	scanf("%d",&numero);

	for(contador = 1; contador <= 10; contador = contador + 1)
		{
			printf("\n %d X %d = %d",numero, contador, numero*contador);
		}

	return 0;
}
