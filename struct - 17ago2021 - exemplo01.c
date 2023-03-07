/*
Estrutura de dados heterogênea - struct
---------------------------------------

Permite que variáveis de tipos diferentes (campos) sejam
armazenadas sob um mesmo nome (registro - struct)

********************************************
*Uma struct é um tipo definido pelo usuário*
********************************************

Sintaxe:
--------

struct <nome_da_struct>
{
  <tipo de dados> <nome de campo 1>;
  <tipo de dados> <nome de campo 2>;
  ...
	<tipo de dados> <nome de campo n>;
} [typedef] [nome_do_novo_tipo];

Exemplo:
--------

struct a
{
	int ra;
	char nome[50];
	char disciplina[50];
	float media_final;
}typedef aluno;

aluno turma[50];

*/
#include <stdio.h>
#include <stdlib.h>

struct d
{
	char disciplina[50];
	float media_final;
} typedef disc;

struct a
{
	int ra;
	char nome[50];
	disc lista_disciplina[5];
} typedef aluno;

int main()
{
	aluno turma[3];
	int i, j;

	for(j = 0; j < 3; j = j + 1)
		{
			printf("\nDigite o RA do %do Aluno: ",j+1);
			scanf("%d",&turma[j].ra);
			printf("\nDigite o Nome do %do Aluno: ",j+1);
			fflush(stdin);
			gets(turma[j].nome);
			for(i = 0; i < 5; i = i + 1)
				{
					printf("\nDigite a %da Disciplina do Aluno %s: ",i+1,turma[j].nome);
					fflush(stdin);
					gets(turma[j].lista_disciplina[i].disciplina);
					printf("\nDigite a Media Final: ");
					scanf("%f",&turma[j].lista_disciplina[i].media_final);
				}
		}
	return 0;
}
