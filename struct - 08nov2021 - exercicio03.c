/*
3. Construa uma estrutura aluno com nome, número de matrícula e curso. Leia do
usuário a informação de 5 alunos, armazene em vetor dessa estrutura e imprima
os dados na tela.
*/
#include <stdio.h>
#include <stdlib.h>
struct
{
	char nome[50];
	int matricula;
	char curso[100];
} typedef aluno;

int main()
{
	aluno turma[5];
	int i;

	for(i = 0; i < 5; i = i + 1)
		{
			printf("\nDigite o nome do aluno: ");
			fflush(stdin);
			gets(turma[i].nome);
			printf("\nDigite a matricula do aluno: ");
			scanf("%d",&turma[i].matricula);
			printf("\nDigite o curso do aluno: ");
			fflush(stdin);
			gets(turma[i].curso);
		}

	for(i = 0; i < 5; i = i + 1)
		printf("\n%s - Matricula %d - Curso %s",turma[i].nome,turma[i].matricula,turma[i].curso);

	return 0;
}