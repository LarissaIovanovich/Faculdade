/*
Mostre todos os números primos em um intervalo 
[n1,n2] fornecido pelo usuário
*/
#include <stdio.h>
int main(){
	int n1, n2, aux, soma;
	n1 = 20;
	n2 = 100;
	while(n1 <= n2){
		soma = 0;
		aux = n1;
		while(aux >= 1){
			if(n1 % aux == 0){
				soma = soma + 1;
				if(soma == 3)
					break;
				}
			aux = aux - 1;
		}
		if(soma == 2)
			printf("\nO numero %d e primo",n1);
		n1 = n1 + 1;
	}
	return 0;
}
