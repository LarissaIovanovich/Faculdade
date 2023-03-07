/*
2. Implemente um programa que leia o nome, a idade
e o endereço de uma pessoa e armazene os dados em
uma estrutura.
*/
#include <stdio.h>
#include <stdlib.h>
struct
{
	char nome[50];
	int idade;
	char endereco[100];
} typedef pessoa;

int main()
{
	pessoa aluno;

	printf("\nDigite o nome do aluno: ");
	fflush(stdin);
	gets(aluno.nome);
	printf("\nDigite a idade do aluno: ");
	scanf("%d",&aluno.idade);
	printf("\nDigite o endereco do aluno: ");
	fflush(stdin);
	gets(aluno.endereco);

	printf("\n\n%s - idade %d - Endereco: %s",aluno.nome, aluno.idade,aluno.endereco);

	return 0;
}