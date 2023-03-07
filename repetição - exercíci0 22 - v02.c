/*
22 - Escreva um programa que calcule e escreva a soma dos 
50 primeiros termos da série:

  1!    2!    3!    4!    5!               x
 --- - --- + --- - --- + --- - ...        ---
  1     3     7     15    31               y

----------------------------------
entradas de dados:
  não há
saídas de dados:
  valor total da série calculada
processamento:	
  atribuir 1 a x
	atribuir 1 a y	
	enquanto x for menor ou igual a 50 
	  calcular o fatorial de x
		  atribuir o valor de x a fat
			atribuir x - 1 a mult
			enquanto mult for maior do que 1
			  fat recebe fat multiplicado por mult
				mult recebe mult - 1
			se x for par (x mod 2 == 0) então
			  serie recebe a serie somada a (fat divido por y) vezes -1
			  senao
			    serie recebe a serie somada a (fat divido por y)
	    y = y * 2 + 1	
			x = x + 1
	mostar a serie calculada		    
*/
#include <stdio.h>

int main(){
	double x, y, fat, mult, serie;
	int sinal;
	
	x = 1;
	y = 1;
	serie = 0;
	sinal = 1;
	while (x <= 50){
		fat = x;
		mult = x - 1;
		while (mult > 1){
			fat = fat * mult;
			mult = mult - 1;
		}
		serie = serie + fat / y * sinal;
		sinal = sinal * -1;					
    y = y * 2 + 1;	
		x = x + 1;
	}
	printf("\nSerie %lf",serie);
	return 0;
}

































