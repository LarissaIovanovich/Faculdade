/*
4. Escreva um programa em Linguagem C que:
a) Contenha uma função que receba múltiplos argumentos int positivos(int,...);
b) A função poderá receber uma quantidade indefinida de números inteiros 
positivos, tendo como valor o número -1;
c) A função deverá:
	i. Contar a quantidade de números que recebeu como parâmetro;
	ii. Alocar dinamicamente um vetor de inteiros com o tamanho igual à 
		quantidade de parâmetros recebidos pela função;
	iii. Armazenar os valores do vetor em um arquivo, separados por ; (ponto e vírgula);
	iv. Liberar a memória alocada dinamicamente.

*/
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
/* 
********************************************************************
  Este exercício foi resolvido com duas funções de múltiplos argumentos
  
  1 - Na função int positivo(int,...)
  		Não há a contagem inicial de quantos argumentos a função recebe, uma
  		vez que a cada novo valor lido um realloc é realizado para a criação de
  		mais um espaço de memória para armazenar este valor

  2 - Na função int positivo_v02(int,...)
  		Há a contagem de quantos argumentos a função recebe, e depois a alocação
  		dinâmica (malloc) de um vetor com a quantidade necessária de elementos
  		para armazenar todos os parâmetros recebidos		  		
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