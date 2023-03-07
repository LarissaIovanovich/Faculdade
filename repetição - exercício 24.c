/*
24) Escreva um programa que, dado um conjunto de valores inteiros e positivos, 
determine qual o menor valor do conjunto. O final do conjunto de valores é 
conhecido através do valor zero, que não deve ser considerado

entradas de dados
  conjunto de valores inteiros e positivos
saídas de dados
  menor valor do conjunto (exceto zero)
processamento
  atribuir -1 a valor
  atribuir 999999 a m
	enquanto valor for diferente de 0
	  obter valor enquanto valor for menor do que 0
		se valor for maior do que 0 e valor for menor do que m então
		  m recebe valor
	fimenquanto
	mostrar m	  
*/
#include <stdio.h>
int main(){
	int valor, menor, maior;
	do{
		printf("Digite um numero inteiro positivo maior que 0 (0 finaliza): ");
		scanf("%d",&valor);
	}while(valor < 0);
  menor = valor;
  maior = valor;
  while(valor != 0){
		do{
			printf("Digite um numero inteiro positivo maior que 0 (0 finaliza): ");
			scanf("%d",&valor);
		}while(valor < 0);
	  if((valor > 0) && (valor < menor))
			menor = valor;
	  if((valor > 0) && (valor > maior))
			maior = valor;			
	}
  printf("\nO menor valor informado foi %d",menor);	
  printf("\nO maior valor informado foi %d",maior);	
	return 0;
}

