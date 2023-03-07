#include <stdio.h>
#include <stdlib.h>
struct
{
	int id;
	char nome[50];
} typedef exemplo02;

int main()
{
	exemplo02 pessoa;
	
	printf("\nDigite o codigo da pessoa: ");
	scanf("%d",&pessoa.id);
	printf("\nDigite o nome da pessoa: ");
	fflush(stdin);
	gets(pessoa.nome);
	
	printf("\nCodigo: %d ", pessoa.id);
	printf("\nNome..: %s ", pessoa.nome);
	
	return 0;
}