/*
CÁLCULO DE FATORIAL DE UM NÚMERO
--------------------------------
O fartorial de um número é dado por

n * n-1 * n-2 * n-3 * .... * 1

Exemplo
-------
O fatorial do número 6

6 * 5 * 4 * 3 * 2 * 1
-----
   30 * 4 * 3 * 2 * 1
   ------
      120 * 3 * 2 * 1
      -------
          360 * 2 * 1
          -------
              720 * 1
*/
#include <stdio.h>
int main(){
	unsigned long long numero, mult, fat;
	
	printf("\nCalculo do fatorial de um numero: ");
	scanf("%i",&numero);
	
	mult = numero - 1;
	fat = numero;
	
	while(mult > 1){
		fat = fat * mult;
		mult = mult - 1;
	}	
	
	printf("\nO fatorial de %d e %d",numero,fat);
	
	return 0;
}