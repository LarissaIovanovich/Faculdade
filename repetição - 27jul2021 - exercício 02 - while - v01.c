/*
2) Calcular a média final obtida por um grupo de 22 alunos,
para 4 notas bimestrais.

calcular a média de cada aluno
calcular a média da turma

entradas de dados:
------------------
	4 notas, de 22 alunos (88 notas)

saídas de dados:
----------------
	média de cada aluno
	média da turma
	
processamento:
--------------
	inicializar numero de alunos em 0 (nalunos)	
	inicializar soma total em 0
	enquanto numero de alunos for menor do que 22
		obter 4 notas
		calcular a média do n aluno (n - primeiro, segundo, terceiro...)
			media = (n1 + n2 + n3 + n4) / 4
		mostrar a media calculada
		somatotal = somatotal + media
		numero de alunos = numero de alunos + 1
	mostrar a media total
		soma total / 22	

*/
#include <stdio.h>
int main()
{
	int nalunos, quantidade;
	float n1, n2, n3, n4, media, somatotal;
	
	nalunos = 0;
	somatotal = 0;
	
	printf("\nPrograma para calcular media\n");
	printf("\nPara quantos alunos os calculos serao realizados? ");
	scanf("%d",&quantidade);
	
	while(nalunos < quantidade)
	{
		printf("\nDigite 4 notas do %d aluno separadas por ENTER\n",nalunos+1);
		scanf("%f%f%f%f",&n1,&n2,&n3,&n4);
		media = (n1 + n2 + n3 + n4) / 4;
		printf("\nA media do %d aluno e %0.1f",nalunos+1, media);
		somatotal = somatotal + media;
		nalunos = nalunos + 1;
	}
	
	printf("\nA media da turma e %0.1f",somatotal/quantidade);
}
