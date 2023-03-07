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
//====================================================================================
/*
	struct Dt_dma
	{
		int dia;
		int mes;
		int ano;	
	};

  struct Dt_dma *p;       // p é um ponteiro para registros do tipo Dt_dma
  struct Dt_dma  dt_nasc; // dt_nasc é uma variável do tipo Dt_dma
  p = &dt_nasc;           // p aponta para dt_nasc
  p-> ano = 2009;         // atribui o valor 2009 ao campo ano da variável dt_nasc
  (*p).ano = 2009;        // atribui o valor 2009 ao campo ano da variável dt_nasc

Observação:
-----------
O acesso ao membro de uma struct através de ponteiro pode utilizar utilizar 
o operador seta ->.

O comando:
	p->ano = 2009;

equivale a:
	(*p).ano = 2009
*/
#include <stdio.h>
#include <stdlib.h>

struct Produto
{
	int cod;
	float preco;
}typedef tipo_produto;

void leProd(tipo_produto *);
void mostraProd(tipo_produto *);
void aumenta (tipo_produto *);

void main()
{
	tipo_produto *prod;
	
	prod = malloc(3 * sizeof(tipo_produto));
	
	leProd(prod);
	aumenta(prod);
	mostraProd(prod);
}

void leProd(tipo_produto *q)
{
	int i;
	for (i=0; i<3; i++)
		{
			printf("Codigo? ");
			scanf("%d", &q->cod);
			printf("Preco? ");
			scanf("%f", &q->preco);
			q++;
		}
}

void mostraProd(tipo_produto *q)
{
	int i;
	printf("Novo preco\n");
	for (i=0; i<3; i++)
		{
			printf("Codigo: %d - Preco: %.2f\n",q->cod, q->preco);
			q++;
		}
}

void aumenta (tipo_produto *p)
{
	int i;
	// Aumentando o preco
	for (i=0; i<3; i++)
		{
			p->preco *= 1.15;
			p++;
		}
}
