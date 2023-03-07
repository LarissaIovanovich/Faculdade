/*
2. Escreva um programa em Linguagem C que declare uma estrutura para o
cadastro de alunos:
a) Deverão ser armazenados, para cada aluno:
	a. matrícula
	b. nome
	c. sobrenome
	d. ano de nascimento
b) Ao início do programa, o usuário deverá informar o número de alunos
que serão cadastrados;
c) O programa devera alocar dinamicamente a quantidade necessária de
memória para armazenar os registros dos alunos em um vetor;
d) O programa deverá pedir ao usuário que entre com as informações dos alunos;
e) Mostrar os dados e depois gravá-los em um arquivo;
f) Liberar a memória alocada.

*/
#include <stdio.h>
#include <stdlib.h>

struct {
	int matricula;
	char nome[50];
	char sobrenome[50];
	int anonascimento;
} typedef aluno;


int main()
{
	FILE *arq;
	int q, i;
	aluno *vetor;

	printf("\nCadastrar dados de alunos");
	printf("\n-------------------------");
	printf("\nInforme a quantidade de alunos para o cadastro: ");
	scanf("%d", &q);

	vetor = malloc(q * sizeof(aluno));
	if(vetor == NULL) {
		printf("\nNao ha memoria para alocacao do vetor\n");
		exit(0);
	}

	for(i = 0; i < q; i = i + 1) {
		printf("\nMatricula.........: ");
		scanf("%d", &vetor[i].matricula);
		printf("\nNome..............: ");
#ifdef LINUX
		__fpurge(stdin);
#else
		fflush(stdin);
#endif
		gets(vetor[i].nome);
		printf("\nSobrenome.........: ");
#ifdef LINUX
		__fpurge(stdin);
#else
		fflush(stdin);
#endif
		gets(vetor[i].sobrenome);
		printf("\nAno de Nascimento.: ");
		scanf("%d", &vetor[i].anonascimento);
		printf("\n-----------------------------------");
	}

  arq = fopen("exercicio02.txt","w");
  fwrite(&q, sizeof(int), 1, arq);
  fwrite(vetor, sizeof(aluno), q, arq);	
	fclose(arq);
	free(vetor);	  

/* 
********************************************************************
  este trecho de código:
	1 - abre o arquivo
	2 - lê a quantidade de registros que foram gravados
	3 - aloca memória para armazenar a quantidade de registros gravados
	4 - lê o conteúdo do arquivo para o vetor dinâmico
	5 - mostra o conteúdo do vetor na tela
	6 - fecha o arquivo
	7 - libera a memória alocada dinamicamente
********************************************************************		
	arq = fopen("exercicio02.txt", "r");
	fread(&q, sizeof(int), 1, arq);
	vetor = malloc(sizeof(aluno) * q);
	fread(vetor, sizeof(aluno), q, arq);
	for(i = 0; i < q; i = i + 1) {
		printf("\n-----------------------------------");
		printf("\nMatricula.........: %d ", vetor[i].matricula );
		printf("\nNome..............: %s ", vetor[i].nome);
		printf("\nSobrenome.........: %s ", vetor[i].sobrenome);
		printf("\nAno de Nascimento.: %d ", vetor[i].anonascimento);
	}
	fclose(arq);
	free(vetor);	
*/	
	return 0;
}
