#include <stdio.h>
#include <string.h>
main(){
  int a;
  char buffer[250];
  printf("Inverte um numero digitado pelo usuario, >= 10 e <= 999999\n");
  printf("Digite um numero: ");
  scanf("%d", &a);

  itoa(a,buffer,10);
  printf("\n\nNumero invertido: %d\n\n",atoi(strrev(buffer)));
}
