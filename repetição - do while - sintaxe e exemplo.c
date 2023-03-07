/*	
Setunda forma de estrutura de repeti��o:
-----------------------------------------
COM VERIFICA��O NO FINAL:
  - primeiro executa o c�digo e depois verifica uma condi��o;
  - pode ser executada 1(uma) ou n vezes.
-----------------------------------------	
Sintaxe:
--------

do
{
	<comando(s)>
}while (<condi��o>);
	
	
do           - comando de repeti��o (FA�A)	
{  }         - delimitam um bloco de comandos associados ao WHILE
<comando(s)> - comando ou comandos que ser�o executados ENQUANTO 
               a condi��o for VERDADEIRA		
while <condi��o>   - express�o l�gica, cujo resultado ser� VERDADEIRO ou
                     FALSO. Esta express�o controla a estrutura de repeti��o.
						         ENQUANTO a express�o for VERDADEIRA os comandos s�o
						         executados, quando a condi��o for FALSA, o fluxo de
						         execu��o vai para o proximo comando ap�s o bloco DO							 				 
							 
							 		  	
*/

/*
ESTRUTURA DE REPETI��O
----------------------
Constru��o l�gica que permite que um determinado trecho de
c�digo seja executado repetidas vezes ENQUANTO uma determinada
CONDI��O for VERDADEIRA.
� importante que haja, para esta estrutura l�gica, uma vari�vel
de controle que permite que a repeti��o seja iniciada e finalizada,
caso contr�rio a estrutura pode entrar em LOOP INFINITO.

Exemplo:
--------
Escreva um programa que mostra a tabuada padr�o de um numero inteiro.

entradas de dados:
  n�mero para a tabuada
sa�das de dados:
  tabuada do n�mero informado:
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
	pelos n�meros naturais seguintes at� por 10.		  
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





