/*
10) Para um grupo indeterminado de 2 números quaisquer,
informar para cada grupo:
a) o maior
b) o menor
c) se são iguais
--------------------------------------------
entradas de dados:
  dois números, sendo que serão fornecidos conjuntos indeterminados de
    números
saídas de dados:
  para cada conjunto de dois números digitados:
    o maior
    o menor
    se são iguais
processamento
  enquanto o usuário desejar
    obtenha o primeiro número (a)
    obtenha o segundo número (b)
    se a for igual a b ENTÃO
      escreva - os números são iguais
      SENÃO
        se a for maior do que b
          escreva - a é o maior número e b é o menor número
          SENÃO
            escreva - b é o maior número e a é o menor número
----------------------------------------------------
*/
#include <stdio.h>
int main() {
  float a, b;
  int opcao;

  opcao = 1;
  while(opcao){
    printf("\nDigite o primeiro numero: ");
    scanf("%f",&a);
    printf("\nDigite o segundo numero: ");
    scanf("%f",&b);
    if(a == b)
    {
      printf("\nos numeros sao iguais\n");
    }
    else {
      if (a > b) {
        printf("\na(%f) e maior e b(%f) e menor\n",a,b);
      }
      else
      {
        printf("\nb(%f) e maior e a(%f) e menor\n",b,a);
      }
		}
		do{
		  printf("\nDeseja continuar? 1 para SIM ou 0 para NAO ");
		  scanf("%d",&opcao);
		}while ((opcao != 0) && (opcao != 1));
  }
  return 0;
}











