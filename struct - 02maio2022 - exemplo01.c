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
#include <string.h>

struct
{
	char cidade[100];
	char uf[3];
} typedef tipo_endereco;

struct
{
	int ra;
	char nome[50];
	tipo_endereco local;
	float notas[4];
	float media;
	char sf[15];
} typedef tipo_aluno;

void relacao_de_alunos(tipo_aluno[],int);

int main()
{
	tipo_aluno *turma;

	int i, j, qtd;

	printf("\nQuantos alunos ha na turma? ");
	scanf("%d",&qtd);

	if(malloc(qtd * sizeof(tipo_aluno)) == NULL)
		{
			printf("\nErro de memoria\n");
			exit(0);
		}

	turma = malloc(qtd * sizeof(tipo_aluno));

	for(i = 0; i < qtd; i = i + 1)
		{
			printf("\nDigite o RA do %do aluno: ",i+1);
			scanf("%d",&turma[i].ra);
			printf("\nDigite o nome do aluno: ");
			fflush(stdin);
			gets(turma[i].nome);
			printf("\nQual a cidade do aluno? ");
			fflush(stdin);
			gets(turma[i].local.cidade);
			printf("\nQual o estado da cidade? ");
			fflush(stdin);
			gets(turma[i].local.uf);

			turma[i].media = 0;
			for(j = 0; j < 4; j = j + 1)
				{
					printf("Digite a %da nota do %do aluno: ",j+1,i+1);
					scanf("%f",&turma[i].notas[j]);
					turma[i].media = turma[i].media + turma[i].notas[j];
				}
			turma[i].media = turma[i].media / 4;
			if(turma[i].media >= 6)
				strcpy(turma[i].sf,"APROVADO");
			else
				strcpy(turma[i].sf,"REPROVADO");
		}

	relacao_de_alunos(turma, qtd);

	return 0;
}

void relacao_de_alunos(tipo_aluno *lista, int q)
{
	int i, j;
	for(i = 0; i < q; i = i + 1)
		{
			printf("\n-----------------------------------------");
			printf("\nNome - %s - RA - %d",lista[i].nome,lista[i].ra);
			printf("\nCidade - %s - UF - %s",lista[i].local.cidade,lista[i].local.uf);
			printf("\nNotas: ");
			for(j = 0; j < 4; j = j + 1)
				{
					printf("%6.1f",lista[i].notas[j]);
				}
			printf("\nMedia - %0.2f",lista[i].media);
			printf("\nSituacao - %s",lista[i].sf);
		}
}
