/*
4. Crie uma estrutura representando os alunos de um determinado curso. A
estrutura deve conter a matricula do aluno, nome, nota da primeira prova, nota
da segunda prova e nota da terceira prova.
a) Permita ao usuário entrar com os dados de 5 alunos;
b) Encontre o aluno com maior nota da primeira prova;
c) Encontre o aluno com maior média geral;
d) Encontre o aluno com menor média geral;
e) Para cada aluno diga se ele foi aprovado ou reprovado, considerando o
	 valor 6 para aprovação;
f) Crie dois vetores, dividindo o conteúdo do primeiro vetor:
	 a. Aprovados
	 b. Reprovados
g) Ordene os dois novos vetores: o de aprovados por média em ordem
	 crescente, e o de reprovados por média me ordem decrescente;
h) Exibir na tela os dados do vetor de aprovados, seguido dos dados do vetor
	 de reprovados.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct
{
	int matricula;
	char nome[50];
	float p1, p2, p3, media;
	char situacao[4];  //APR ou REP
} typedef aluno;

//realiza o cadastro de alunos na turma
void cadastrar(aluno *); //vetor do tipo aluno
//retorna a matricula do aluno com a maior nota na primeira prova
int maior_p1(aluno *); //vetor do tipo aluno
//retorna a matricula do aluno com a maior ou a menor media geral (tipo 1 maior, tipo 2 menor)
int encontra_media(aluno *, int); //vetor do tipo aluno, tipo de busca
//mostra o conteúdo de um vetor do tipo alunos, com a situação de cada pessoa cadastrada
void lista_turma(aluno *); //vetor do tipo aluno
//aloca memória para um vetor do tipo aluno
aluno * aloca_memoria(int); //tamanho do vetor que será criado
//copia o conteúdo do vetor original, para um vetor destino
aluno * separa_situacao(aluno *, aluno *, int, int); //vetor original, vetor destino, tamanho do vetor destino, tipo do vetor destino 1 - APR, 2 - REP
//ordena vetor
void ordena_media(aluno *, int); //vetor a ser ordenado, tipo de ordenação 1 - crescente, 2 - decrescente

/*
pos é uma variável global que armazena o número de alunos que já foram
		cadastrados no vetor, indicando qual é a próxima posição "válida" a ser preenchida no vetor
		é o índice do vetor

inicio é uma variável que informa se o vetor de alunos já existe ou ainda não foi criado
	0 - indica que o vetor ainda não foi alocado
	1 - indica que o vetor já foi alocado
*/

int pos, inicio = 0;

int main()
{

	return 0;
}

//realiza o cadastro de alunos na turma
//vetor do tipo aluno
void cadastrar(aluno *vetor)
{
	if(pos == 4)
		{
			printf("\nNao ha mais espaco de memoria para cadastrar alunos\n");
		}
	else
		{
			printf("\nDigite a matricula do aluno: ");
			scanf("%d",&vetor[pos].matricula);
			printf("\nDigite o nome do aluno: ");
			fflush(stdin);
			gets(vetor[pos].nome);
			do
				{
					printf("\nDigite a primeira nota do aluno: ");
					scanf("%f",&vetor[pos].p1);
				} while((vetor[pos].p1 < 0) || (vetor[pos].p1 > 10));
			do
				{
					printf("\nDigite a segunda nota do aluno: ");
					scanf("%f",&vetor[pos].p2);
				}while((vetor[pos].p2 < 0) || (vetor[pos].p2 > 10));
			do
				{
					printf("\nDigite a terceira nota do aluno: ");
					scanf("%f",&vetor[pos].p3);
				}while((vetor[pos].p3 < 0) || (vetor[pos].p3 > 10));
			
			vetor[pos].media = (vetor[pos].p1 + vetor[pos].p2 + vetor[pos].p3) / 3;
		
			if(vetor[pos].media < 6)
				strcpy(vetor[pos].situacao,"REP");
				else
					strcpy(vetor[pos].situacao,"APR");
			
			pos = pos + 1;
		}
}
//retorna a matricula do aluno com a maior nota na primeira prova
//vetor do tipo aluno
int maior_p1(aluno *vetor)
{
	float maior;

	return maior;
}
//retorna a matricula do aluno com a maior ou a menor media geral (tipo 1 maior, tipo 2 menor)
//vetor do tipo aluno, tipo de busca
int encontra_media(aluno *vetor, int tipo)
{
	int matr, i;
	float valor;
	valor = vetor[0].media;
	if(tipo == 1)
		{
			for(i = 0; i < pos;i = i + 1)
				if(vetor[i].media > valor)
				{
					valor = vetor[i].media;
	        matr = vetor[i].matricula;	
	 			}
		}
	else
		{
			for(i = 0; i < pos;i = i + 1)
				if(vetor[i].media < valor)
				{
					valor = vetor[i].media;
	        matr = vetor[i].matricula;	
	 			}
		}
	return matr;
}
//mostra o conteúdo de um vetor do tipo alunos, com a situação de cada pessoa cadastrada
//vetor do tipo aluno
void lista_turma(aluno *vetor)
{


}

//aloca memória para um vetor do tipo aluno
//tamanho do vetor que será criado
aluno * aloca_memoria(int q)
{
	aluno *vetor;
	if((aluno*)malloc(q * sizeof(aluno)) == NULL)
		{
			printf("\nErro! Nao ha memoria suficiente! (1)\n");
			exit(0);
		}
	vetor = (aluno*)malloc(q * sizeof(aluno));
	return vetor;
}

//copia o conteúdo do vetor original, para um vetor destino
//vetor original, vetor destino, tamanho do vetor destino, tipo do vetor destino 1 - APR, 2 - REP
aluno * separa_situacao(aluno *origem, aluno *destino, int q, int tipo)
{

	return destino;
}

//ordena vetor
//vetor a ser ordenado, tipo de ordenação 1 - crescente, 2 - decrescente
void ordena_media(aluno *vetor, int tipo)
{


}