/*
2) Calcular a média final obtida por um grupo de 22 alunos, 
para 4 notas bimestrais.

entradas de dados:
	4 notas para cada aluno de um grupo de 22
saídas de dados:
	média da turma (88 notas / 22)
processamento:
	inicializar o contador com 1
	inicializar a soma com 0
	enquanto o contador for menor ou igual a 22		
		ler as 4 notas
		somar as notas lidas em soma
		incrementar o contato em 1
	mostrar a média da turma
		soma / 22
*/
#include <stdio.h>
#include <locale.h>
int main()
{
	setlocale(LC_ALL,"Portuguese");
	float soma, n1, n2, n3, n4;
	int contador;
	
	contador = 1;
	soma = 0;
	
	while(contador <= 22)
	{
		printf("\nDigite a primeira nota do %dº aluno: ",contador);
		scanf("%f",&n1);
		printf("\nDigite a segunda nota do %dº aluno: ",contador);
		scanf("%f",&n2);
		printf("\nDigite a terceira nota do %dº aluno: ",contador);
		scanf("%f",&n3);
		printf("\nDigite a quarta nota do %dº aluno: ",contador);
		scanf("%f",&n4);
		soma = soma + n1 + n2 + n3 + n4;
		contador = contador + 1;
	}
	printf("\nA média da turma é %0.2f",soma/22);
	return 0;
}




