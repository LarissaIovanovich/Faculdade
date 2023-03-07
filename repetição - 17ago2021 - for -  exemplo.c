/*
Estrutura de repetição
----------------------

É uma estrutura que permite que um grupo de comandos
seja executado, repetidamente, ENQUANTO uma condição
(expressão lógica) for VERDADEIRA.
Nós chamamos esta condição de "condição de controle
da estrutura de repetição".

1 - Repetição com verificação da condição no início (laço contado)
------------------------------------------------------------------

Esta estrutura de repetição, primeiro verifica a condição,
e depois executa os comandos,
Os comandos podem ser executados 0 ou n vezes.

Sintaxe:
--------

	for([inicialização];[condição];[incremento/decremento])
	{
		<comandos>
  }

for - palavra reservada da linguagem C que especifica a estrutura de repetição
[inicialização] - área de inicialização de variáveis.
									É executada sempre no início, e apenas uma vez.

[condição] - é a expressão lógica de controle da estrutura.
						 É verifica sempre após a [inicialização], e depois
						 da execução do [incremento/decremento]

[incremento/decremento] - esta área contém os comandos de incremento
													e/ou decremento da variável de controle
													da estrutura.
													É executada sempre depois dos <comandos>

<comandos> - um bloco de comandos, delimitado por chaves {}, que
						 é sempre executado depois da verificação da condição,
						 se a mesma for VERDADEIRA.
						 Ao final deste bloco, a área de [incremento/decremento]
						 é executada

//============================================================================

Exemplo:
--------

Mostre na tela os 10 primeiros números naturais ímpares
*/
#include <stdio.h>
int main()
{
	int numero, contador;
//****************************************
//WHILE
//****************************************
	numero = 1;
	contador = 1;
	while (contador <= 10)
		{
			printf("%d ",numero);
			numero = numero + 2;
			contador = contador + 1;
		}

//****************************************
//DO ... WHILE
//****************************************
	numero = 1;
	contador = 1;
	do
		{
			printf("%d ",numero);
			numero = numero + 2;
			contador = contador + 1;
		}
	while (contador <= 10);

//****************************************
//FOR
//****************************************
	for(numero = 1, contador = 1;contador <= 10;contador = contador + 1)
		{
			printf("%d ",numero);
			numero = numero + 2;
		}

	return 0;
}
