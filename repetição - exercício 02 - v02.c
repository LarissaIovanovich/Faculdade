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
	float soma, nota;
	int contador, qnotas;
	
	contador = 1;
	soma = 0;
	
	while(contador <= 22)
	{
		qnotas = 1;
		while(qnotas <= 4)
		{
			printf("\nDigite a %dª nota do %dº aluno: ",qnotas, contador);
		  scanf("%f",&nota);
  		soma = soma + nota;
  		qnotas = qnotas + 1;
  	}
		contador = contador + 1;
	}
	printf("\nA média da turma é %0.2f",soma/22);
	return 0;
}




