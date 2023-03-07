/*

34) Escreva um programa que calcule e escreva a soma dos 
50 primeiros termos da série:
      1!    2!    3!    4!    5!
S =  --- - --- + --- - --- + --- - ...
      1     3     7     15    31
*/
#include <stdio.h>
int main(){
	double s, x, y, aux, fat;
	int sinal;
  s = 0;
  x = 1;
  y = 1;
  sinal = 1;
  while (x <= 50){
		fat = x;
		aux = x - 1;
		while (aux > 1){
			fat = fat * aux;
			aux = aux - 1;
		}
		printf("\nx --> %.0lf y --> %.0lf x! --> %.0lf",x,y,fat);
		s = s + (fat / y * sinal);
		sinal = sinal * -1;
		x = x + 1;
		y = y * 2 + 1;
	}
	printf("\nS --> %lf\n",s);
	return 0;
}
