/*
******************************************************************************
1)Crie uma função que receba como parâmetros dois vetores de inteiros:
 x1 e x2 e as suas respectivas quantidades de elementos: n1 e n2.
 A função deverá retornar um ponteiro para um terceiro vetor,
 x3, alocado dinamicamente, contendo a união de x1 e x2 e usar o ponteiro
 qtd para retornar o tamanho de x3.
Sendo
x1 = {1, 3, 5, 6, 7}
x2 = {1, 3, 4, 6, 8}
x3 irá conter {1, 3, 4, 5, 6, 7, 8}

Assinatura da função:

int* uniao(int *x1, int *x2, int n1, int n2, int* qtd);

******************************************************************************
2)Crie uma função que receba como parâmetros dois vetores de inteiros:
  x1 e x2 e as suas respectivas quantidades de elementos: n1 e n2.
  A função deverá retornar um ponteiro para um terceiro vetor,
  x3, alocado dinamicamente, contendo a intersecção de x1 e x2 e usar o ponteiro
  qtd para retornar o tamanho de x3.
Sendo
x1 = {1, 3, 5, 6, 7}
x2 = {1, 3, 4, 6, 8}
x3 irá conter {1, 3, 6}

Assinatura da função:

int* interseccao(int *x1, int *x2, int n1, int n2, int *qtd);

******************************************************************************
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//****************************************************************************
int * uniao(int *, int *, int, int, int *);
int * interseccao(int *, int *, int, int, int *);
int * liberamemoria(int *);
void imprime(int *, int, char *);
void preenche(int *, int);
int * aloca_vetor(int);

//****************************************************************************
int main()
{
	int *x1; //[20] = {1, 3,	5, 6,	7};
	int *x2; //[20] = {1, 3,	4, 6,	8};
	int n1 = 5, n2 = 5, qtd = 0, op;
	int *v3; //{1, 3, 4, 5, 6, 7, 8}
	//{1, 3, 6}
	srand(time(NULL));
	do
		{
			printf("\nSelecione uma opcao");
			printf("\n1 - Uniao de dois vetores");
			printf("\n2 - Interseccao de dois vetores");
			printf("\n3 - Sair\n");
			scanf("%d", &op);
			switch(op)
				{
					case 1:
						printf("\nQuantos numeros deve haver no vetor 1? ");
						scanf("%d",&n1);
						printf("\nQuantos numeros deve haver no vetor 2? ");
						scanf("%d",&n2);
						x1 = aloca_vetor(n1);
						x2 = aloca_vetor(n2);
						preenche(x1, n1);
						preenche(x2, n2);
						v3 = uniao(x1, x2, n1, n2, &qtd);
						imprime(x1, n1, "Vetor X1");
						imprime(x2, n2, "Vetor X2");
						imprime(v3, qtd, "Uniao de X1 e X2");
						v3 = liberamemoria(v3);
						qtd = 0;
						break;
					case 2:
						printf("\nQuantos numeros deve haver no vetor 1? ");
						scanf("%d",&n1);
						printf("\nQuantos numeros deve haver no vetor 2? ");
						scanf("%d",&n2);
						x1 = aloca_vetor(n1);
						x2 = aloca_vetor(n2);
						preenche(x1, n1);
						preenche(x2, n2);
						v3 = interseccao(x1, x2, n1, n2, &qtd);
						imprime(x1, n1, "Vetor X1");
						imprime(x2, n2, "Vetor X2");
						imprime(v3, qtd, "Interseccao de X1 e X2");
						v3 = liberamemoria(v3);
						qtd = 0;
						break;
					case 3:
						exit(0);
					default:
						printf("\nOpcao incorreta\n");
				}
			system("pause");
			system("cls");	
		}
	while(op != 3);
	return 0;
}
//****************************************************************************
int * aloca_vetor(int qtd)
{
	int *vetor;
	int i;
	if(malloc(qtd*sizeof(int)) == NULL)
		{
			printf("\nErro ao alocar memoria para o vetor\n");
			exit(0);
		}
	vetor = malloc(qtd*sizeof(int));
	return vetor;
}
//****************************************************************************
void preenche(int *v, int qtd)
{
	int i;
	for(i = 0; i < qtd; i = i + 1)
		do
			{
				v[i] = rand() / 1000 + 1;
			}
		while(v[i] >= 20);
}
//****************************************************************************
void imprime(int *v, int qtd, char *texto)
{
	int i;
	printf("\n%s\n", texto);
	for(i = 0; i < qtd; i = i + 1)
		printf("%d ", v[i]);
	printf("\n");
}
//****************************************************************************
int* liberamemoria(int *v)
{
	free(v);
	return v;
}
//****************************************************************************
int* uniao(int *x1, int *x2, int n1, int n2, int *qtd)
{
	int *vetor;
	int i, j, conta;
	if(*qtd == 0)
		{
			vetor = malloc(1 * sizeof(int));
			vetor[*qtd] = x1[0];
			*qtd = *qtd + 1;
		}
	for(i = 1; i < n1; i = i + 1)
		{
			for(conta = 0, j = 0; j < i; j = j + 1)
				{
					if(x1[i] == vetor[j])
						{
							conta = 1;
							break;
						}
				}
			if(conta == 0)
				{
					vetor = realloc(vetor, (*qtd + 1) * sizeof(int));
					vetor[*qtd] = x1[i];
					*qtd = *qtd + 1;
				}
		}
	for(i = 0; i < n2; i = i + 1)
		{
			for(conta = 0, j = 0; j < (i + n1); j = j + 1)
				{
					if(x2[i] == vetor[j])
						{
							conta = 1;
							break;
						}
				}
			if(conta == 0)
				{
					vetor = realloc(vetor, (*qtd + 1) * sizeof(int));
					vetor[*qtd] = x2[i];
					*qtd = *qtd + 1;
				}
		}
	return vetor;
}
//****************************************************************************
int* interseccao(int *x1, int *x2, int n1, int n2, int *qtd)
{
	int *vetor;
	int i, j, k, conta, conta2;

	for(i = 0; i < n1; i = i + 1)
		{
			for(j = 0; j < n2; j = j + 1)
				{
					if(x1[i] == x2[j] && *qtd == 0)
						{
							vetor = malloc(1 * sizeof(int));
							vetor[*qtd] = x1[i];
							*qtd = *qtd + 1;
						}
					else
						{
							if(x1[i] == x2[j] && *qtd > 0)
								{
									for(conta = 0, k = 0; k < i; k = k + 1)
										{
											if(x1[i] == vetor[k])
												{
													conta = 1;
													break;
												}
										}
									for(conta2 = 0, k = 0; k < j; k = k + 1)
										{
											if(x2[j] == vetor[k])
												{
													conta2 = 1;
													break;
												}
										}
									if(conta == 0 && conta2 == 0)
										{
											vetor = realloc(vetor, (*qtd + 1) * sizeof(int));
											vetor[*qtd] = x1[i];
											*qtd = *qtd + 1;
										}
								}
						}
				}
		}
	return vetor;
}
//****************************************************************************