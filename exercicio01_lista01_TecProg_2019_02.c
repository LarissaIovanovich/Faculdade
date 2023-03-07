/*
1. Escreva um programa em Linguagem C que leia um arquivo que contém n linhas,
cada uma contendo apenas um número. Para cada linha deste arquivo:
a) Faça a alocação dinâmica de memória de um vetor de inteiros de tamanho
correspondente ao valor lido;
b) Preencha randomicamente o vetor criado;
c) Ordene o vetor criado;
d) Mostre o vetor ordenado;
e) Libere a memória do vetor criado dinamicamente.
Os itens b), c) e d) devem ser realizados através de funções

arquivo.txt
4
5
16
31

*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>   

void preenche(int [], int); //vetor e tamanho do vetor
void ordena(int [], int);   //vetor e tamanho do vetor
void imprime(int [], int);  //vetor e tamanho do vetor

int main()
{
	srand(time(NULL));
  FILE *arq;
  int num, *vetor;
  arq = fopen("exercicio01.txt","r");
  if(arq == NULL){
			printf("\nProblemas com a abertura do arquivo\n");
			exit(0); 	
	}
  while(fscanf(arq,"%d",&num) != EOF){
		if(num > 0)
			vetor = malloc(num * sizeof(int));
		if(vetor == NULL){
			printf("\nNao ha memoria para alocacao do vetor\n");
			break;
		}
		else{
			preenche(vetor,num);
		  ordena(vetor,num);
		  imprime(vetor,num);
		  free(vetor);
		}
	}
	fclose(arq);
	return 0;
}
void preenche(int v[], int q)
{
	int i;
	for(i = 0; i < q; i = i + 1) {
		v[i] = rand() / 200;
	}
}
void ordena(int v[], int q)
{
	int i, j, aux;
	for(i = 0; i < q-1; i++) {
		for(j = i + 1; j < q; j++) {
			if(v[i] > v[j]) {
				aux = v[i];
				v[i] = v[j];
				v[j] = aux;
			}
		}
	}
}
void imprime(int v[], int q)
{
	int i;
	printf("%d --> ",q);
	for(i = 0; i < q; i = i + 1) {
		printf("%d ", v[i]);
	}
	printf("\n-------------------------\n");
}