/*
Estrutura de repetição
----------------------

Permite que um grupo de comandos seja executado ENQUANTO
uma determinada condição permanece VERDADEIRA. Quando
esta condição tornar-se FALSA, o fluxo de execução do
programa segue para o próximo comando após a estrutura.

1 - Repetição com verificação no final
--------------------------------------

sintaxe:
--------

do
{
	<comandos>
}while <condição>;

do		 		 - FAÇA, é a estrutura de repetição na qual
						 os comandos serão executados
{  }			 - Delimitam o bloco de comandos associado à
						 estrutura
<comandos> - Serão executados enquanto a condição for
						 VERDADEIRA
while <condição> - Expressão lógica, cujo resultado será sempre
						 			 VERDADEIRO ou FALSO, e que irá controlar
						 			 a execução da estrutura						 
						 
Esta estrutura é executada 1 ou n vezes, uma vez que ela
primeiro executa os comandos, e depois verifica a condição.
Se inicialmente a condição for FALSA, os comandos serão 
executados uma vez;
					
Exemplo:
--------
Mostrar na tela a tabuada de um número fornecido 
pelo usuário, no formato:
numero X numero = numero
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

entrada de dados:
	número fornecido pelo usuário
saída de dados:
	a multiplicação sequencial do número fornecido pelo
	usuário, que começa em 1 e termina em 10, sendo
	incrementada de 1 em 1
processamento:
1 -	obter o número do usuário
2 -	inicializar a variável multiplicadora(de controle) em 1
3 -	mostrar o resultado da multiplicação do número 
			pela variável de controle
4 -	incrementar a variável de controle em 1
5 -	repetir os passos	3 e 4 enquanto a variável de controle
			for menor ou igual a 10
*/
#include <stdio.h>
#include <locale.h>
int main(){
	setlocale(LC_ALL,"Portuguese");
	int num, contador;
	
	printf("\nPrograma para mostrar a tabuada de um número\n");
	printf("\nDigite um número inteiro: ");
	scanf("%d",&num);
	
	contador = 1;
	
	do
	{
		printf("\n%d X %d = %d",num, contador, num*contador);
		contador = contador + 1;		
	}while(contador <= 10);
	
	return 0;
}
