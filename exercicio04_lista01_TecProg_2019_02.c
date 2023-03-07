/*
4. Escreva um programa em Linguagem C que:
a) Contenha uma fun��o que receba m�ltiplos argumentos int positivos(int,...);
b) A fun��o poder� receber uma quantidade indefinida de n�meros inteiros 
positivos, tendo como valor o n�mero -1;
c) A fun��o dever�:
	i. Contar a quantidade de n�meros que recebeu como par�metro;
	ii. Alocar dinamicamente um vetor de inteiros com o tamanho igual � 
		quantidade de par�metros recebidos pela fun��o;
	iii. Armazenar os valores do vetor em um arquivo, separados por ; (ponto e v�rgula);
	iv. Liberar a mem�ria alocada dinamicamente.

*/
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
/* 
********************************************************************
  Este exerc�cio foi resolvido com duas fun��es de m�ltiplos argumentos
  
  1 - Na fun��o int positivo(int,...)
  		N�o h� a contagem inicial de quantos argumentos a fun��o recebe, uma
  		vez que a cada novo valor lido um realloc � realizado para a cria��o de
  		mais um espa�o de mem�ria para armazenar este valor

  2 - Na fun��o int positivo_v02(int,...)
  		H� a contagem de quantos argumentos a fun��o recebe, e depois a aloca��o
  		din�mica (malloc) de um vetor com a quantidade necess�ria de elementos
  		para armazenar todos os par�metros recebidos		  		
********************************************************************  		
*/
int positivo(int,...);
int positivo_v02(int,...);
//**********************************************************
int main(){
	
	positivo_v02(11,22,33,44,55,66,77,88,99,100,200,300,400,500,-1);
	positivo_v02(1,2,3,4,5,6,7,8,9,10,20,30,40,50,-1);
	positivo(1,3,5,7,9,11,-1);	
	positivo(2,4,6,8,10,-1);	
	
	return 0;
}
//**********************************************************
int positivo(int n1, ...) {
	FILE *arq;
	int *vetor;
	va_list pa; 
  int q, i, num;
  
  vetor = malloc(1 * sizeof(int));
  
	va_start(pa, n1); 
  if(n1 > 0){
		vetor[0] = n1;
		i = 1;
		do{
		  num = va_arg(pa, int);
			if (num > 0){
				vetor = realloc(vetor, (i + 1) * sizeof(int));
				vetor[i] = num;
				i = i + 1;
			}
		}while(num != -1);
	}
  
  arq = fopen("exercicio04.txt","a");
  
	for(q = 0;q < i;q = q + 1){
		fprintf(arq,"%d;",vetor[q]);
	}
	fprintf(arq,"\n");
 
	fclose(arq);
	free(vetor); 
	va_end(pa); 

	return 0;
}
//**********************************************************
int positivo_v02(int n1, ...) {
	FILE *arq;
	int *vetor;
	va_list pa; 
  int q, i, num, qtd = 0;
   
  va_start(pa,n1);
  if(n1 > 0){
		qtd = 1;
    do{
    	num = va_arg(pa,int);
			if (num > 0)
      	qtd = qtd + 1;
	  }while(num != -1);
	}  
  
  if(qtd > 0){
    vetor = malloc(qtd * sizeof(int));  
	  va_start(pa, n1); 
	  vetor[0] = n1;
		i = 1;
		do{
		  num = va_arg(pa, int);
			if (num > 0){
				vetor[i] = num;
				i = i + 1;
			}
		}while(num != -1);
	}
  
  arq = fopen("exercicio04.txt","a");
  
	for(q = 0;q < i;q = q + 1){
		fprintf(arq,"%d;",vetor[q]);
	}
	fprintf(arq,"\n");
 
	fclose(arq);
	free(vetor); 
	va_end(pa); 

	return 0;
}
//**********************************************************