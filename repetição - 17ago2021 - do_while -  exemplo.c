/*
Estrutura de repetição
----------------------

É uma estrutura que permite que um grupo de comandos
seja executado, repetidamente, ENQUANTO uma condição
(expressão lógica) for VERDADEIRA.
Nós chamamos esta condição de "condição de controle
da estrutura de repetição".

1 - Repetição com verificação da condição no final
---------------------------------------------------

Esta estrutura de repetição, primeiro executa os comandos,
e depois verifica a condição,
Os comandos podem ser executados 1 ou n vezes.

Sintaxe:
--------

  do
  {
  	<comandos>
  }while (condição);

do - FAÇA, é a palavra chave que define a estrutura de repetição
{
<comandos> - bloco, delimitado por chaves {}, que contém os
}						 comandos que serão executados, ENQUANTO a condição
						 for VERDADEIRA
while (condição) - é a expressão lógica, cujo resultado será sempre
						 			 VERDADEIRO ou FALSO, que controle a execução
						 			 da estrutura

//============================================================================

Exemplo:
--------

Mostre na tela os 10 primeiros números naturais ímpares
*/
#include <stdio.h>
int main()
{
	int numero, contador;

	numero = 1;
	contador = 1;

	do
		{
			printf("%d ",numero);
			numero = numero + 2;
			contador = contador + 1;
		}
	while (contador <= 10);

	return 0;
}
