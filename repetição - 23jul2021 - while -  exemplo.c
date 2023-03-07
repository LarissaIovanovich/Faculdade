/*
Estrutura de repetição
----------------------

É uma estrutura que permite que um grupo de comandos
seja executado, repetidamente, ENQUANTO uma condição
(expressão lógica) for VERDADEIRA.
Nós chamamos esta condição de "condição de controle 
da estrutura de repetição".

1 - Repetição com verificação da condição no início
---------------------------------------------------

Esta estrutura de repetição, primeiro verifica a condição,
e depois executa os comandos.
Os comandos podem ser executados 0 ou n vezes.

Sintaxe:
--------

while (condição)
  {
  	<comandos>  
  }

while - ENQUANTO, é a palvra chave que definida estrutura de
				repetição
(condição) - é a expressão lógica, cujo resultado será sempre
						 VERDADEIRO ou FALSO, que controle a execução
						 da estrutura
{
<comandos> - bloco, delimitado por chaves {}, que contém os 
}						 comandos que serão executados, ENQUANTO a condição
						 for VERDADEIRA	

//============================================================================

Exemplo:
--------

Mostre na tela os 10 primeiros números naturais ímpares
*/
#include <stdio.h>
int main()
{
	int numero, contador, limite;
	
	printf("\nQuantos numeros naturais impares devo mostrar na tela? ");
	scanf("%d",&limite);
	
	numero = 1;
	contador = 1;
	
	while (contador <= limite)
	{
	  printf("%d ",numero);
		numero = numero + 2;
		contador = contador + 1;
	}

	return 0;
}
