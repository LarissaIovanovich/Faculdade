#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
int main(){
  setlocale(LC_ALL,"Portuguese");
  int n, x, s;
  printf("Digite um n�mero: ");
  scanf("%d",&n);
  x = n; 
  s = 0;
  while(x >= 1){
    if (n % x == 0)
		s = s + 1;	  
	x = x  - 1;  
  }
  if (s == 2)
  	printf("\n%d � primo",n);
    else
      printf("\n%d n�o � primo",n); 
  
  return 0; 
}