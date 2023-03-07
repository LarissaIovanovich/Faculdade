/*
Escreva um programa que calcule e escreva a soma dos 20
primeiros termos da série

     100     99     98     97     x
S = ----- + ---- + ---- + ----   ... 
      0!     1!     2!     3!     y
*/
#include <stdio.h>

int main(){
	
	double x, y, s, f, fy;
/*	
	x = 99;
	y = 1;
	s = 100;
	
	while(x >= 80){
		fy = y;
		f = y - 1;
    while(f > 1){
			fy = fy * f;
			f = f - 1;
		}		
		s = s + x / fy;
		x = x - 1;
		y = y + 1;
	}
*/
  for(x = 99, y = 1, s = 100;x >= 80;x = x - 1, y = y + 1){
		for(fy = y, f = y - 1;f > 1;f = f - 1){
			fy = fy * f;
		}		
		s = s + x / fy;
	}	

	printf("\nS --> %f",s);
	
	return 0;
}