#include <stdio.h>
#include <string.h>
main(){
  int a, b, c;
  char buffer[250];
  printf("Inverte um numero digitado pelo usuario, >= 10 e <= 999999\n");
  printf("Digite um numero: ");
  scanf("%d", &a);

  itoa(a,buffer,10);
  printf("\n\nNumero invertido: %d\n\n",atoi(strrev(buffer)));

  b = a;
  c = 1;
  while (b > 0){
    b = b / 10;
    c = c * 10;
  }
  c = c / 10;
  b = 0;
  while (a > 0){
    b = b + a % 10 * c;
    a = a / 10;
    c = c / 10;
  }
  printf("\nO numero invertido e %d\n", b);
}
