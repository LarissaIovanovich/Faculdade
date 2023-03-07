#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

struct e
{
	int codigo;
	char nome[50];
	float potencia;
	float consumo;
	int tempoativo;
};

typedef struct e equipamento;

float calculaconsumo(float,int);
void preenche(equipamento[]);
void relatorio(equipamento[],char[]);
//nas funções de ordenação o último parâmetro indica a ordem
//1 ordem crescente e 2 ordem decrescente
void ordena_potencia(equipamento[],int);
void ordena_nome(equipamento[],int);
int buscaequipamento(equipamento [],int);
int buscaequipamento2(equipamento [],int, char[]);
equipamento * aloca_vetor(int);
equipamento * realoca_vetor(equipamento *, int);

int Q = 3;
int limite;

int main()
{

	char cabecalho[50], nome[50];
	int codigo, i;
	equipamento *L;

	Q = 3;

	L = aloca_vetor(Q);

	preenche(L);
	strcpy(cabecalho,"Sem ordenacao");
	relatorio(L,cabecalho);
	ordena_potencia(L,1); //1 ordena crescente e 2 ordena decrescente
	strcpy(cabecalho,"Ordenado por potencia");
	relatorio(L,cabecalho);
	ordena_nome(L,2);//1 ordena crescente e 2 ordena decrescente
	strcpy(cabecalho,"Ordenado por nome");
	relatorio(L,cabecalho);

	codigo = buscaequipamento2(L,1,nome);
	printf("\nEquipamento com maior consumo %d - %s",codigo,nome);
	codigo = buscaequipamento2(L,2,nome);
	printf("\nEquipamento com menor consumo %d - %s",codigo,nome);

	/*
	  codigo = buscaequipamento(L,1);
		for(i = 0;i < Q;i = i + 1)
		{
			if(codigo == L[i].codigo)
			{
			  printf("\nEquipamento com maior consumo %d - %s",codigo,L[i].nome);
			  break;
			}
		}
	*/
	free(L);
	return 0;
}

void preenche(equipamento lista[])
{
	int i = 0, fim = 0;
	srand(time(NULL));
	while(!(fim))
		{
			lista[i].codigo = i + rand() + 1;
			printf("informe o nome do equipamento: ");
			fflush(stdin);
			gets(lista[i].nome); //lê toda a string
			do
				{
					printf("informe a potencia em watts do equipamento: ");
					scanf("%f",&lista[i].potencia);
				}
			while((lista[i].potencia < 1) || (lista[i].potencia > 7500));
			do
				{
					printf("informe o tempo ativo do equipamento: ");
					scanf("%d",&lista[i].tempoativo);
				}
			while((lista[i].tempoativo < 1) || (lista[i].tempoativo > 600));
			lista[i].consumo = calculaconsumo(lista[i].potencia, lista[i].tempoativo);
			i = i + 1;

			if(i == Q-1)
				{
					Q = Q + 3;
					lista = realoca_vetor(lista, Q);
				}

			printf(" \nDeseja cadastrar um novo equipamento? 0 para SIM ou 1 para NAO ");
			scanf("%d",&fim);
		}
		limite = i;
}

void relatorio(equipamento lista[], char texto[])
{
	int i;
	printf("\n\n--------- %s ---------\n",texto);
	for(i = 0; i < limite; i = i + 1)
		{
			printf("\n----------------------------------");
			printf("\nCodigo ------> %d",lista[i].codigo);
			printf("\nNome --------> %s",lista[i].nome);
			printf("\nPotencia ----> %2.2f",lista[i].potencia);
			printf("\nTempo Ativo -> %d",lista[i].tempoativo);
			printf("\nConsumo -----> %2.2f",lista[i].consumo);
		}
}

float calculaconsumo(float p, int ta)
{
	return (p * (ta / 60.0 * 30.0) / 1000.0);
}

//1 ordem crescente e dois ordem decrescente
void ordena_potencia(equipamento lista[], int ordem)
{
	int i, j;
	equipamento aux;
	for(i = 0; i < limite - 1; i++)
		{
			for(j = i + 1; j < limite; j++)
				{
					if(ordem == 1)
						{
							if(lista[i].potencia > lista[j].potencia)
								{
									aux = lista[i];
									lista[i] = lista[j];
									lista[j] = aux;
								}
						}
					else if (ordem == 2)
						{
							if(lista[i].potencia < lista[j].potencia)
								{
									aux = lista[i];
									lista[i] = lista[j];
									lista[j] = aux;
								}
						}
				}
		}
}

//1 ordem crescente e dois ordem decrescente
void ordena_nome(equipamento lista[], int ordem)
{
	int i, j;
	equipamento aux;
	for(i = 0; i < limite - 1; i++)
		{
			for(j = i + 1; j < limite; j++)
				{
					if(ordem == 1)
						{
							if(lista[i].nome < lista[j].nome)
								{
									aux = lista[i];
									lista[i] = lista[j];
									lista[j] = aux;
								}
						}
					else if (ordem == 2)
						{
							if(lista[i].nome > lista[j].nome)
								{
									aux = lista[i];
									lista[i] = lista[j];
									lista[j] = aux;
								}
						}
				}
		}
}

int buscaequipamento(equipamento v[], int tipo)
{
	float valor;
	int codigo, i;
	valor = v[0].consumo;
	codigo = v[0].codigo;
	if(tipo == 1)
		{
			for(i = 0; i < limite; i = i + 1)
				{
					if(v[i].consumo > valor)
						{
							codigo = v[i].codigo;
							valor = v[i].consumo;
						}
				}
		}
	else
		{
			for(i = 0; i < limite; i = i + 1)
				{
					if(v[i].consumo < valor)
						{
							codigo = v[i].codigo;
							valor = v[i].consumo;
						}
				}
		}
	return codigo;
}

int buscaequipamento2(equipamento v[], int tipo, char nomeeqp[])
{
	float valor;
	int codigo, i;
	valor = v[0].consumo;
	codigo = v[0].codigo;
	strcpy(nomeeqp,v[0].nome);
	if(tipo == 1)
		{
			for(i = 0; i < limite; i = i + 1)
				{
					if(v[i].consumo > valor)
						{
							codigo = v[i].codigo;
							strcpy(nomeeqp,v[i].nome);
							valor = v[i].consumo;
						}
				}
		}
	else
		{
			for(i = 0; i < limite; i = i + 1)
				{
					if(v[i].consumo < valor)
						{
							codigo = v[i].codigo;
							strcpy(nomeeqp,v[i].nome);
							valor = v[i].consumo;
						}
				}
		}
	return codigo;
}

equipamento* aloca_vetor(int qtd)
{
	equipamento *lista;

	if(malloc(qtd * sizeof(equipamento)) == NULL)
		{
			printf("\nNao ha memoria suficiente\n");
			exit(0);
		}
	lista = malloc(qtd * sizeof(equipamento));

	return lista;
}

equipamento* realoca_vetor(equipamento *lista, int qtd)
{
	if(realloc(lista, qtd * sizeof(equipamento)) == NULL)
		{
			printf("\nNao ha memoria suficiente\n");
			exit(0);
		}
	lista = realloc(lista,qtd * sizeof(equipamento));

	return lista;
}




