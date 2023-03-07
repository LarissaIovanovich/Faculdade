/*
ALOCAÇÃO DINÂMICA DE MEMÓRIA
----------------------------

Quando declaramos uma variável 

int n;

Sabemos que n pode armazenar um único valor, do tipo inteiro,
a cada momento da execução de um programa

Se declaramos 

int vetor[10];

Sabemos que vetor pode armazenar dez valores do tipo inteiro,
um em cada uma de suas "posições", ou endereços de memória.
Mesmo assim, da forma como vetor foi declarado ele é estático,
ou seja, não podemos alterar seu tamanho para maior ou menor,
durante a execução do programa, mesmo que possamos acessar
seu conteúdo através de um ponteiro (como vimos anteriormente).

A declaração

int matriz[3][3]

Assemelha-se a descrição do vetor que fizemos acima.

Para o caso de ser necessário utilizar um vetor ou 
uma matriz cujo tamanho seja determinado durante
a execução do programa (dinamicamente), utilizamos
o recurso de ALOCAÇÃO DINÂMICA DE MEMÓRIA.
*/
#include <stdio.h>
#include <stdlib.h>
int main()
{
	int *copia; //salva o endereço inicial de vetor
							//após sua alocação dinámica de memória
	int *vetor; //ponteiro que conterá o endereço do
							//vetor que será alocado dinamicamente
	int i, Q, N; //i será um contador para percorrer o vetor
						   //Q será o tamanho do vetor informado pelo usuário
							 //N contém o quantidade de elementos
							 //que serão acrescentados ao vetor dinâmico
							 	
	printf("\nPreenche um vetor de inteiros\n");
	printf("\nInforme qual a dimensao do vetor: ");
	scanf("%d",&Q);
	
	vetor = malloc(Q * sizeof(int));
	copia = vetor;
//malloc - comando que aloca dinamicamente
//				 um determinado número de blocos de memória	
//vetor recebe um endereço de memória inicial
//de um bloco com Q elementos do tamanho em bytes
//do tipo inteiro - sizeof(int) retorna o tamanho em
//bytes do tipo inteiro												

//a partir deste ponto, vetor pode ser manipulado como
//um ponteiro, ou como um vetor "comum"	
	
//manipulando vetor como um vetor "comum"	
	for(i = 0;i < Q;i = i + 1)
		vetor[i] = i + 3;
	printf("\nVetor como variavel \"comum\" \n");	
	for(i = 0;i < Q;i = i + 1)
		printf("%d ",vetor[i]);
		
//manipulando vetor como um ponteiro
	vetor = copia; //atribui para vetor o endereço
								 //da sua primeira posição, que foi
								 //salva em copia
	for(i = 0;i < Q;i = i + 1)
	{
		*vetor = i + 6;
    vetor++;	
  }
  vetor = copia; //atribui para vetor o endereço
								 //da sua primeira posição, que foi
								 //salva em copia  
	printf("\nVetor como ponteiro \n");	
	for(i = 0;i < Q;i = i + 1)
	{
		printf("%d ",*vetor);		
	  vetor++;
	}
	vetor = copia;
/*
Para o caso de ser necessário alterar a quantidade
de blocos de memória que foram alocados dinamicamente,
utilizamos o comando realloc, que permite fazer ]
esta modificação
*/	
	printf("\nQuantos elementos serao acrescentados ao vetor? ");
	scanf("%d",&N);	
	
	vetor = realloc(vetor, (Q+N)*sizeof(int));
//cria um novo espaço de memória
//na realidade aumenta a quantidade de blocos
//de memória para o novo tamanho determinado por
//Q+N	

	for(i = Q;i < (Q+N);i = i + 1)
		vetor[i] = i + 11;
	printf("\nNovos elementos no vetor\n");	
	for(i = 0;i < (Q+N);i = i + 1)
		printf("%d ",vetor[i]);	
	return 0;
}