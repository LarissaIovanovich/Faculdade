/*

Do arquivo "exercicios com ponteiros - 02.pdf" no Moodle da disciplina Técnicas de Programação

1) Crie	uma	função que receba	como	parâmetros	dois	vetores	de	inteiros: x1	e	x2 e	as
suas	respectivas	quantidades	de	elementos:	n1	e	n2.
	A	função	deverá	retornar	um	ponteiro	para	um	terceiro	vetor,	x3,	alocado	dinamicamente,
contendo	a	união	de x1	e	x2 e usar	o	ponteiro qtd	para	retornar	o	tamanho	de	x3.

Sendo:
	x1	=	{1,	3, 5, 6, 7}
	x2	=	{1,	3, 4,	6, 8}
	x3	irá	conter	{1, 3, 4, 5, 6, 7, 8}

Assinatura	da	função:

int * uniao(int *x1, int *x2, int n1, int n2, int* qtd);

*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define Q 10

int * uniao(int *, int *, int, int, int *);
int * aloca_vetor(int); //quantidade de elementos a serem alocados
int * realoca_vetor(int *, int); //vetor e o novo tamanho do vetor a ser realocado
void preenche_vetor(int *, int);
void imprime_vetor(int *, int, char *);
void bubbleSort(int *, int);

int main()
{
	int *vetor1, *vetor2, *vetor3, q3, i; //q3 - tamanho do vetor3

	srand(time(NULL));

	vetor1 = aloca_vetor(Q);
	vetor2 = aloca_vetor(Q);
	preenche_vetor(vetor1, Q);
	preenche_vetor(vetor2, Q);
	bubbleSort(vetor1,Q);
	bubbleSort(vetor2,Q);
	imprime_vetor(vetor1, Q,"\nVetor X1\n");
	imprime_vetor(vetor2, Q,"\nVetor X2\n");
	vetor3 = uniao(vetor1, vetor2, Q, Q, &q3);
	bubbleSort(vetor3,q3);
	imprime_vetor(vetor3, q3,"\nVetor X3\n");
	return 0;
}

int * uniao(int *x1, int *x2, int n1, int n2, int *qtd)
{
	int *x3;
	int i, j, iguais;
//copia todos os elementos do vetor x1 para o vetor x3, sem repetições
//====================================================================
	*qtd = 1;
	x3 = aloca_vetor(*qtd);		//aloca memória inicial para o vetor x3
	x3[0] = x1[0];						//copia o primeiro valor do vetor x1 para a primeira posição do vetor x3
	for(i = 0; i < n1; i = i + 1)  //laço para percorrer o vetor x1
		{
			iguais = 0;
			for(j = 0; j < *qtd; j = j + 1)  //laço para percorrer o vetor x3, verificando se o valor apontado em x1
				{
					//já está copiado
					if(x1[i] == x3[j])     //se o valor apontado em x1 existir em x3
						iguais = iguais + 1; //a variável iguais será incrementada em 1
				}
			if(iguais == 0)		//se o valor apontado em x1 ainda não foi copiado para x3 a variável iguais conterá 0
				{
					*qtd = *qtd + 1;							//incrementa o contador de valores do vetor x3
					x3 = realoca_vetor(x3,*qtd);	//realoca memória para o vetor x3
					x3[*qtd-1] = x1[i];						//copia o conteúdo de x1 para a posição atual em x3
				}
		}
//copia todos os elementos do vetor x2 para o vetor x3, sem repetições
//====================================================================
	for(i = 0; i < n2; i = i + 1) //laço para percorrer o vetor x2
		{
			iguais = 0;
			for(j = 0; j < *qtd; j = j + 1) //laço para percorrer o vetor x3, verificando se o valor apontado em x2
				{
					//já está copiado
					if(x2[i] == x3[j])		 //se o valor apontado em x1 existir em x3
						iguais = iguais + 1; //a variável iguais será incrementada em 1
				}
			if(iguais == 0)		//se o valor apontado em x1 ainda não foi copiado para x3 a variável iguais conterá 0
				{
					*qtd = *qtd + 1;							//incrementa o contador de valores do vetor x3
					x3 = realoca_vetor(x3,*qtd);	//realoca memória para o vetor x3
					x3[*qtd-1] = x2[i];						//copia o conteúdo de x1 para a posição atual em x3
				}
		}
	return x3;
}

int * aloca_vetor(int q)
{
	int *v;
	if (malloc(q * sizeof(int)) == NULL)
		{
			printf("\nNao ha memoria suficiente\n");
			exit(0);
		}
	v = malloc(q * sizeof(int));
	return v;
}

int * realoca_vetor(int *v, int q)
{
	if (realloc(v,q * sizeof(int)) == NULL)
		{
			printf("\nNao ha memoria suficiente\n");
			exit(0);
		}
	v = realloc(v,q * sizeof(int));
	return v;
}

void preenche_vetor(int *v, int q)
{
	int i;
	for(i = 0; i < q; i = i + 1)
		do
			{
				v[i] = rand()/1000;
			}
		while((v[i] < 2) || (v[i] > 20));
}
void imprime_vetor(int *v, int q, char *texto)
{
	int i;
	printf("\n%s",texto);
	for(i = 0; i < q; i = i + 1)
		printf("%d ",v[i]);
}

void bubbleSort(int *v, int n)
{
	int i, j, aux;
	for(i = n-1; i > 0; i--)
		{
			for(j = 0; j < i; j++)
				{
					if(v[j] > v[j+1])
						{
							aux = v[j];
							v[j] = v[j+1];
							v[j+1] = aux;
						}
				}
		}
}
