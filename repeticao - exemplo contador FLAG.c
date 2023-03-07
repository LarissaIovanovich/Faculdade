#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

int main(){
  setlocale(LC_ALL,"Portuguese");  
  int n, x; 
  char F;  
 
  F = 'S';
  while ((F == 'S') || (F == 's')){
    do{
      printf("Digite um número par e positivo: ");
      scanf("%d",&n); 
    }while((n <= 0) || (n % 2 != 0));
    x = 1; 
    while (x <= 10){
   	  printf("\n%2d X %2d = %2d",n,x,n*x);
	  x = x + 1;
    }
    do{
      printf("\nDeseja continuar? S ou N: ");
      fflush(stdin);
	  scanf("%c",&F);
	}while ((F != 'S') && (F != 's') && (F != 'N') && (F != 'n'));  
  }
  
  return 0;	  
}