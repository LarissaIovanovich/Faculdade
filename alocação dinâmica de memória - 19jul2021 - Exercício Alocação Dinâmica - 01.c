/*
1) Implemente, na linguagem de programação C, uma função que tenha o seguinte protótipo:
int *Maiores (int *vet, int n, int x, int *qtd);
	Essa função recebe os seguintes parâmetros:
		→ vet: um vetor de números inteiros
		→ n: a quantidade de elementos do vetor vet
		→ x: um número inteiro
	Essa função:
		→ Verifica a quantidade de elementos do vetor que sejam maiores do que x;
		→ Caso a quantidade seja maior do que 0 (zero), aloca dinamicamente uma área do
			exato tamanho necessário para armazenar os valores;
		→ Copia os elementos do vetor que sejam maiores do que x para a área alocada
			dinamicamente.
	Essa função retorna:
		→ o endereço da área alocada dinamicamente, preenchida com os números maiores
			do que x, ou NULL, caso essa relação de números não tenha sido criada;
		→ a quantidade de números carregados na área alocada dinamicamente, através do
			parâmetro qtd.

2) Escreva um programa completo em C que:
	→ Crie e inicialize um vetor de números inteiros e liste seus valores na tela;
	→ Leia do teclado um número inteiro;
	→ Chame a função implementada na primeira questão (Maiores) para obter a relação de
		números maiores do que o valor lido do teclado;
	→ Liste na tela todo o conteúdo da relação obtida pela função chamada (Maiores) ou uma
		mensagem de erro, se for o caso.

	Veja a seguir um exemplo do que se espera que apareça na tela por ocasião da execução desse
		programa (os valores podem diferir).

	vetor original = {7, 35, 10, 18}
	Digite o valor limite: 11
	valores maiores do que 11 = {35, 18}

	vetor original = {7, 35, 10, 18}
	Digite o valor limite: 100
	nada a declarar!

*/
#include <stdio.h>
#include <stdlib.h>

int *Maiores (int *, int, int, int *);

int main()
{
	int vetor[10] = {1,2,3,4,5,6,7,8,9,10}, qtd, *maiores;
	int n = 10, valor, i;

	printf("\nvetor original\n");
	for(i = 0; i < n; i = i + 1)
		printf("%d ",vetor[i]);

	printf("\nDigite o valor limite: ");
	scanf("%d",&valor);

	maiores = Maiores(vetor, 10, valor, &qtd);

	if(maiores == NULL)
		{
			printf("\nNao ha valores maiores do que %d no vetor original",valor);
		}
	else
		{
			printf("\nvalores maiores do que %d = ",valor);
			for(i = 0; i < qtd; i = i + 1)
				printf("%d ",maiores[i]);
		}

	free(maiores);

	return 0;
}

int *Maiores (int *vet, int n, int x, int *qtd)
{
	/*
	i = índice para percorrer o vetor *vet
	j = índice para percorre o vetor *m (maiores)
	q = quantidade de números maiores que x em *vet
	*m = vetor que irá armazenar os valores maiores que x, caso existam em *vet
	*/

	int i, j, q = 0, *m;
//procura no vetor *vet os números que são maiores do que x, armazeando esta quantidade em q
	for(i = 0; i < n; i = i + 1)
		{
			if(vet[i] > x)
				q = q + 1;
		}
//se não encontrou nenhum número maior que x em *vet, atribui 0 para *qtd e retorna NULL
	if(q == 0)
		{
			*qtd = 0;
			return NULL;
		}
//se não retornar NULL, então aloca memória para o vetor *m na quantidade definida anteriormente por q
//atribui o valor de q para *qtd;
	if(malloc(q * sizeof(int)) == NULL)
		{
			printf("\nErro de memoria\n");
			exit(0);
		}
//aloca memória para o vetor *m
	m = malloc(q * sizeof(int));
//atribui para o ponteiro *qtd (para quem qta está apontando) o valor de q	
	*qtd = q;
/*
	percorre novamente o vetor *vet e, ao encontrar um número maior do que x, copia o mesmo para
	o vetor *m, utilizando j para índice para *m
*/
	for(i = 0, j = 0; i < n; i = i + 1)
		{
			if(vet[i] > x)
				{
					m[j] = vet[i];
					j = j + 1;
				}
		}
//retorno *m para o programa principal
	return m;
}
