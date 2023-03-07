/*
Escreva um programa que calcule e escreva a soma dos 20
primeiros termos da série

     100     99     98     97     x
S = ----- + ---- + ---- + ----   ... 
      0!     1!     2!     3!     y

entradas de dados:
  não há entradas de dados
saídas de dados:
  soma dos 20 primeiros termos da série
processamento:
  atribuir 1 a qt
	atribuir 100 a S
  atribuir 1 a y
  atribuir 99 a x
  enquanto qt for menor ou igual a 20
	  calcular o fatorial de y 
	    atribuir y - 1 a f
	    atribuir y a g
	    enquanto f for maior do que 1
	       g recebe g * f
	      f recebe f - 1
	    fimenquanto
	  S recebe S + x / g (g é o fatorial de y)
	  x recebe x - 1
	  y recebe y + 1
		qt recebe qt + 1
	fimenquanto 
*/
#include <stdio.h>
int main(){
	double x, y, S, g, f;
	int qt;
	qt = 1;
	S = 100;
	y = 1;
	x = 99;
	while(qt < 20){
		g = y;
		f = y - 1;
		while(f > 1){
			g = g * f;
			f = f - 1;
		}
		S = S + x / g; //g contem o fatorial de y
		x = x - 1;
		y = y + 1;
		qt = qt + 1;
	}
  printf("\n     100     99     98     97     x");
  printf("\nS = ----- + ---- + ---- + ----   ..."); 
  printf("\n      0!     1!     2!     3!     y	");
	printf("\nS --> %f",S);
	return 0;
}