/*
16 - Escreva um programa que calcule e escreva o valor de S onde:

     1     2     3     4     5     6          
S = --- - --- * --- / --- + --- - --- * ...   
     1     4     9     16    25    36         
*/
#include <stdio.h>
int main(){
	float x, s;
	int sinal;
	s = 0;
	x = 1;
	sinal = 1;
	while(x < 20){
		switch(sinal){
			case 1:
			  s = s + (x / (x * x));
        sinal = 2;
        break;
			case 2:
			  s = s - (x / (x * x));
        sinal = 3;
        break;
			case 3:
			  s = s * (x / (x * x));
        sinal = 4;
        break;
			case 4:
			  s = s / (x / (x * x));
        sinal = 1;
        break;
		}
		x = x + 1;
	}
	printf("\nS --> %f\n",s);	
	return 0;
}