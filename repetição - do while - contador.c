/*
FAÇA - Executa um grupo de comandos enquanto a condição
       lógica da estrutura for verdadeira
       É executado 1 ou N vezes, uma vez que a condição
       somente é verificada depois que os comandos são
       executados
           
SINTAXE:

do 
{
	<comando(s)>
}while <condição>;

<condição> - é uma expressão lógica cujo resultado sempre será
             VERDADEIRO ou FALSO
*/
//***********************************************************************
//calcular a média aritmética para um grupo de 5 valores reais fornecidos
//pelo usuário
//***********************************************************************
//entradas de dados: 
//                  cada um dos 5 valores que o usuário irá fornecer
//saídas de dados:
//                média dos 5 valores fornecidos pelo usuário
//processamento:
//              para cada um dos 5 valores que o usuário fornecer, 
//              somá-lo ao valor
//              anterior já armazenado em uma variável e contar mais um
//              à quantidade de números informados
//              após o usuário informar o quinto número
//              calcular a média, dividindo a soma de todos os
//              números por 5
#include <stdio.h>
int main(){ 
  float soma, numero;
  int quantidade;
  soma = 0;
  quantidade = 0;//inicialização da variável de controle do laço de repetição
//a estrutura de repetição a seguir é controlado por um CONTADOR
//que é uma variável que terá seu valor alterado (neste cado acrescido de
//1, cada vez que um novo valor for lido)
//quando o limite for alcançado a estutura de repetição será finalizada.
//Utilizamos um CONTADOR quando sabemos de antemão quantas vezes
//uma estutura de repetição será executada  
  do{  //condição de controle do laço de repetição
	 printf("Digite um numero: ");
	 scanf("%f",&numero);
	 soma = soma + numero;
	 quantidade = quantidade + 1; //alteração do valor da variável de controle
  }while (quantidade < 5);
  printf("\nA media e: %f",soma/quantidade);  	
  return 0;	
}