#include <stdio.h>
main(){
  int a, b, c;
  printf("Inverte um numero digitado pelo usuario, >= 10 e <= 999999\n");
  printf("Digite um numero: ");
  scanf("%d", &a);
  b = a;
  c = 1;
  while (b > 0){ //conta quantos dígitos possui o número informado
    b = b / 10;
    c = c * 10;
  }
  c = c / 10;
  b = 0;
  while (a > 0){ //inverte o número informado
    b = b + a % 10 * c;
    a = a / 10;
    c = c / 10;
  }
  printf("\nO numero invertido e %d", b);
}
