/*
Estrutura de repeti��o
----------------------

Permite que um grupo de comandos seja executado ENQUANTO
uma determinada condi��o permanece VERDADEIRA. Quando
esta condi��o tornar-se FALSA, o fluxo de execu��o do
programa segue para o pr�ximo comando ap�s a estrutura.

3 - Repeti��o com verifica��o no in�cio - LA�O CONTADO
---------------------------------------

sintaxe:
--------

for(<inicializa��o>;<condi��o>;<incremento/decremento>)
{
	<comandos>
}

for 			 - PARA, � a estrutura de repeti��o na qual
						 os comandos ser�o executados
<inicializa��o> - � inicializada a vari�vel de controle 
									da estrutura. Esta parte da estrutura � a
									primeira a ser executada, e SOMENTE uma
									vez						 
<condi��o> - Express�o l�gica, cujo resultado ser� sempre
						 VERDADEIRO ou FALSO, e que ir� controlar
						 a execu��o da estrutura. � a segunda parte
						 da estrutura a ser executada, volta sempre
						 a ser avaliada ap�s a execu��o do inc/dec
<inc/dec>	 - � sempre executado ap�s todos os comandos dentro
						 da estrutura. Ap�s sua realiza��o, a condi��o
						 � novamente verificada						 
{  }			 - Delimitam o bloco de comandos associado �
						 estrutura
<comandos> - Ser�o executados enquanto a condi��o for
						 VERDADEIRA
						 
Esta estrutura � executada 0 ou n vezes, uma vez que ela
primeiro verifica a condi��o e depois executa os comandos.
Se inicialmente a condi��o for FALSA, os comandos n�o
ser�o executados						 
					
Exemplo:
--------
Mostrar na tela a tabuada de um n�mero fornecido 
pelo usu�rio, no formato:
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
	n�mero fornecido pelo usu�rio
sa�da de dados:
	a multiplica��o sequencial do n�mero fornecido pelo
	usu�rio, que come�a em 1 e termina em 10, sendo
	incrementada de 1 em 1
processamento:
1 -	obter o n�mero do usu�rio
2 -	inicializar a vari�vel multiplicadora(de controle) em 1
3 -	mostrar o resultado da multiplica��o do n�mero 
			pela vari�vel de controle
4 -	incrementar a vari�vel de controle em 1
5 -	repetir os passos	3 e 4 enquanto a vari�vel de controle
			for menor ou igual a 10
*/
#include <stdio.h>
#include <locale.h>
int main(){
	setlocale(LC_ALL,"Portuguese");
	int num, contador;
	
	printf("\nPrograma para mostrar a tabuada de um n�mero\n");
	printf("\nDigite um n�mero inteiro: ");
	scanf("%d",&num);
	
	for(contador = 1;contador <= 10;contador = contador + 1)		
	{
		printf("\n%d X %d = %d",num, contador, num*contador);
	}
	
	return 0;
}
