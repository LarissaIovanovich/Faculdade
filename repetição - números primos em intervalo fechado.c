/*
escreva um programa que mostre todos os números primos em um intervalo
fechado [n1,n2] informado pelo usuário
*/
#include <stdio.h>
int main(){
	int n1,n2, p, soma;
	printf("\nEncontra todos os numeros primos em um intervalo fechado");
	printf("\nDigite o inicio do intervalo: ");
	scanf("%d",&n1);
	printf("\nDigite o final do intervalo: ");
	scanf("%d",&n2);
	while(n1 <= n2){
	  p = n1;
	  soma = 0;
	  while(p >= 1){
		  if(n1 % p == 0){
			  soma = soma + 1;
		  	if(soma == 3)
			  	break;
		  }
		  p = p - 1;
	  }
	  if(soma == 2)
		  printf("\n%d e primo",n1);
	  n1 = n1 + 1;
	}
	return 0;
}