/*
10) Para um grupo indeterminado de 2 n�meros quaisquer,
informar para cada grupo:
a) o maior
b) o menor
c) se s�o iguais

entradas de dados:
	diversos conjuntos de dois n�meros
sa�das de dados:
	para cada conjunto lido:
		o maior n�mero
		o menor n�mero
		se s�o iguais
processamento
1 - obter dois n�meros
2 - se n1 for maior que n2 ent�o
			mostrar mensagem - n1 � maior que n2
			sen�o
				se n1 for menor que n2 ent�o
					mostrar mensagem - n2 � maior que n1
					sen�o
						mostrar mensagem - os n�meros s�o iguais
3 - perguntar ao usu�rio se h� outro conjunto de
			n�meros para entrada
			caso positivo, repetir os passos1, 2 e 3
			caso negativo, encerrar a repeti��o				

*/
#include <stdio.h>
#include <locale.h>
int main()
{
	setlocale(LC_ALL,"Portuguese");

  float n1, n2;
  int controle;
  
  do
  {
  	system("cls");
  	printf("\nDigite o primeiro n�mero: ");
  	scanf("%f",&n1);
   	printf("\nDigite o segundo n�mero: ");
  	scanf("%f",&n2);
		
		if (n1 > n2)
		  printf("\n%f � maior do que %f",n1, n2);	
		else
			if(n1 < n2)	
			  printf("\n%f � maior do que %f",n2, n1);
			else
				printf("\nOs n�meros s�o iguais\n");
  	
  	printf("\nDeseja continuar? 1 para SIM ou 2 para N�O ");
  	scanf("%d",&controle);
	}while(controle == 1);

  return 0;
}
