/*
10) Para um grupo indeterminado de 2 números quaisquer,
informar para cada grupo:
a) o maior
b) o menor
c) se são iguais

entradas de dados:
	diversos conjuntos de dois números
saídas de dados:
	para cada conjunto lido:
		o maior número
		o menor número
		se são iguais
processamento
1 - obter dois números
2 - se n1 for maior que n2 então
			mostrar mensagem - n1 é maior que n2
			senão
				se n1 for menor que n2 então
					mostrar mensagem - n2 é maior que n1
					senão
						mostrar mensagem - os números são iguais
3 - perguntar ao usuário se há outro conjunto de
			números para entrada
			caso positivo, repetir os passos1, 2 e 3
			caso negativo, encerrar a repetição				

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
  	printf("\nDigite o primeiro número: ");
  	scanf("%f",&n1);
   	printf("\nDigite o segundo número: ");
  	scanf("%f",&n2);
		
		if (n1 > n2)
		  printf("\n%f é maior do que %f",n1, n2);	
		else
			if(n1 < n2)	
			  printf("\n%f é maior do que %f",n2, n1);
			else
				printf("\nOs números são iguais\n");
  	
  	printf("\nDeseja continuar? 1 para SIM ou 2 para NÃO ");
  	scanf("%d",&controle);
	}while(controle == 1);

  return 0;
}
