#include <stdio.h>
#include <stdlib.h>

struct {
	int cod;
	int quantidade;
	char descricao[50];
	float valorunit;
} typedef tp_lista;

int main(){

	tp_lista *compras;
	int i, qtd, fim;
	
	qtd = 2;
		
	if ((malloc(qtd * sizeof(tp_lista)) == NULL)){
    printf("\nSem espaco de memoria\n");
    exit(1);
  }
  
  compras = malloc(qtd * sizeof(tp_lista));
	
	for(i = 0;i < qtd;i = i + 1)
	{
	  printf("Codigo --> ");
	  scanf("%d",&compras[i].cod);
	  printf("Quantidade --> ");
	  scanf("%d",&compras[i].quantidade);
	  printf("Descricao --> ");
	  fflush(stdin);
	  gets(compras[i].descricao);
	  printf("Valor unitario --> ");
	  scanf("%f",&compras[i].valorunit);
	  printf("\nDeseja continuar? 1 para SIM ou 2 para NAO: ");
	  scanf("%d",&fim);
	  if(fim == 1){
	  	qtd = qtd + 2;
			compras = realloc(compras,qtd * sizeof(tp_lista));
		}
		else
		  break;
	  system("cls");
	}
	
	for(i = 0;i < qtd;i = i + 1){
	  printf("\nCodigo ----------> %d", compras[i].cod);
	  printf("\nQuantidade ------> %d", compras[i].quantidade);
	  printf("\nDescricao -------> %s", compras[i].descricao);
	  printf("\nValor unitario --> %2.2f", compras[i].valorunit);
	}
	
	return 0;
}