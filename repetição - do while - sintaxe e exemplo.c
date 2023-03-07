/*	
Setunda forma de estrutura de repetição:
-----------------------------------------
COM VERIFICAÇÃO NO FINAL:
  - primeiro executa o código e depois verifica uma condição;
  - pode ser executada 1(uma) ou n vezes.
-----------------------------------------	
Sintaxe:
--------

do
{
	<comando(s)>
}while (<condição>);
	
	
do           - comando de repetição (FAÇA)	
{  }         - delimitam um bloco de comandos associados ao WHILE
<comando(s)> - comando ou comandos que serão executados ENQUANTO 
               a condição for VERDADEIRA		
while <condição>   - expressão lógica, cujo resultado será VERDADEIRO ou
                     FALSO. Esta expressão controla a estrutura de repetição.
						         ENQUANTO a expressão for VERDADEIRA os comandos são
						         executados, quando a condição for FALSA, o fluxo de
						         execução vai para o proximo comando após o bloco DO							 				 
							 
							 		  	
*/

/*
ESTRUTURA DE REPETIÇÃO
----------------------
Construção lógica que permite que um determinado trecho de
código seja executado repetidas vezes ENQUANTO uma determinada
CONDIÇÃO for VERDADEIRA.
É importante que haja, para esta estrutura lógica, uma variável
de controle que permite que a repetição seja iniciada e finalizada,
caso contrário a estrutura pode entrar em LOOP INFINITO.

Exemplo:
--------
Escreva um programa que mostra a tabuada padrão de um numero inteiro.

entradas de dados:
  número para a tabuada
saídas de dados:
  tabuada do número informado:
	  2 x 1 = 2
		2 x 2 = 4
		2 x 3 = 6
	  2 x 4 = 8
		2 x 5 = 10
		2 x 6 = 12
	  2 x 7 = 14
		2 x 8 = 16
		2 x 9 = 18
		2 x 10 = 20
processamento:
  mostrar a multiplicacao do numero lido por 1, e sucessivamente
	pelos números naturais seguintes até por 10.		  
*/
#include <stdio.h>
int main(){
	int numero, contador;
	
	printf("\nMostra a tabuada de um numero inteiro: ");
	printf("\nDigite o numero para a tabuada: ");
	scanf("%d",&numero);
	
  contador = 1;
  do{
		printf("\n%d X %d = %d",numero, contador, numero * contador); //	2 x 1 = 2  	
		contador = contador + 1; //incremento do contador
	}while (contador <= 10);
	
	return 0;
}





