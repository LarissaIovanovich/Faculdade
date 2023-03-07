/*
FA�A - Executa um grupo de comandos enquanto a condi��o
       l�gica da estrutura for verdadeira
       � executado 1 ou N vezes, uma vez que a condi��o
       somente � verificada depois que os comandos s�o
       executados
           
SINTAXE:

do 
{
	<comando(s)>
}while <condi��o>;

<condi��o> - � uma express�o l�gica cujo resultado sempre ser�
             VERDADEIRO ou FALSO
*/
//***********************************************************************
//calcular a m�dia aritm�tica para um grupo de 5 valores reais fornecidos
//pelo usu�rio
//***********************************************************************
//entradas de dados: 
//                  cada um dos 5 valores que o usu�rio ir� fornecer
//sa�das de dados:
//                m�dia dos 5 valores fornecidos pelo usu�rio
//processamento:
//              para cada um dos 5 valores que o usu�rio fornecer, 
//              som�-lo ao valor
//              anterior j� armazenado em uma vari�vel e contar mais um
//              � quantidade de n�meros informados
//              ap�s o usu�rio informar o quinto n�mero
//              calcular a m�dia, dividindo a soma de todos os
//              n�meros por 5
#include <stdio.h>
int main(){ 
  float soma, numero;
  int quantidade;
  soma = 0;
  quantidade = 0;//inicializa��o da vari�vel de controle do la�o de repeti��o
//a estrutura de repeti��o a seguir � controlado por um CONTADOR
//que � uma vari�vel que ter� seu valor alterado (neste cado acrescido de
//1, cada vez que um novo valor for lido)
//quando o limite for alcan�ado a estutura de repeti��o ser� finalizada.
//Utilizamos um CONTADOR quando sabemos de antem�o quantas vezes
//uma estutura de repeti��o ser� executada  
  do{  //condi��o de controle do la�o de repeti��o
	 printf("Digite um numero: ");
	 scanf("%f",&numero);
	 soma = soma + numero;
	 quantidade = quantidade + 1; //altera��o do valor da vari�vel de controle
  }while (quantidade < 5);
  printf("\nA media e: %f",soma/quantidade);  	
  return 0;	
}