/*
10) Para um grupo indeterminado de 2 n�meros quaisquer,
informar para cada grupo:
a) o maior
b) o menor
c) se s�o iguais
--------------------------------------------
entradas de dados:
  dois n�meros, sendo que ser�o fornecidos conjuntos indeterminados de
    n�meros
sa�das de dados:
  para cada conjunto de dois n�meros digitados:
    o maior
    o menor
    se s�o iguais
processamento
  enquanto o usu�rio desejar
    obtenha o primeiro n�mero (a)
    obtenha o segundo n�mero (b)
    se a for igual a b ENT�O
      escreva - os n�meros s�o iguais
      SEN�O
        se a for maior do que b
          escreva - a � o maior n�mero e b � o menor n�mero
          SEN�O
            escreva - b � o maior n�mero e a � o menor n�mero
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











