#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
Este programa faz a alocação dinâmica de uma matriz.
O número de linhas deve ser igual ao número de colunas.
Existem as seguintes funções:

-----------------------------
int **Alocar_matriz(int, int)
-----------------------------
recebe 
	o número de linhas e de colunas da matriz
realiza
	a alocação de memória para as linhas e colunas da matriz
	para uma matriz 3 X 3:
	
      0    1     2     
  +-----+-----+-----+
0 | 0,0 | 0,1 | 0,2 |
  +-----+-----+-----+
1 | 1,0 | 1,1 | 1,2 |
  +-----+-----+-----+
2 | 2,0 | 2,1 | 2,2 |
  +-----+-----+-----+
	
devolve 
	ponteiro para a matriz alocada

-------------------------------------------------
int **Realocar_matriz(int, int, int, int, int **)
-------------------------------------------------
recebe
	o número de linhas e colunas da matriz (primeiro e segundo parâmetros)
	o novo número de linhas e colunas da matriz (terceiro e quarto parâmetros)
	um ponteiro para a matriz (quinto parâmetro)
realiza
	a realocação das colunas para a matriz já existente:
	  0,3 a 2,5
	
     0     1     2     3     4     5
  +-----+-----+-----+-----+-----+-----+
0 | 0,0 | 0,1 | 0,2 | 0,3 | 0,4 | 0,5 |
  +-----+-----+-----+-----+-----+-----+
1 | 1,0 | 1,1 | 1,2 | 1,3 | 1,4 | 1,5 |
  +-----+-----+-----+-----+-----+-----+
2 | 2,0 | 2,1 | 2,2 | 2,3 | 2,4 | 2,5 |
  +-----+-----+-----+-----+-----+-----+

	a realocação das linhas e colunas novas
	  3,0 a 5,5  
 
     0     1     2     3     4     5
  +-----+-----+-----+-----+-----+-----+
0 | 0,0 | 0,1 | 0,2 | 0,3 | 0,4 | 0,5 |
  +-----+-----+-----+-----+-----+-----+
1 | 1,0 | 1,1 | 1,2 | 1,3 | 1,4 | 1,5 |
  +-----+-----+-----+-----+-----+-----+
2 | 2,0 | 2,1 | 2,2 | 2,3 | 2,4 | 2,5 |
  +-----+-----+-----+-----+-----+-----+
3 | 3,0 | 3,1 | 3,2 | 3,3 | 3,4 | 3,5 |
  +-----+-----+-----+-----+-----+-----+
4 | 4,0 | 4,1 | 4,2 | 4,3 | 4,4 | 4,5 |
  +-----+-----+-----+-----+-----+-----+	
5 | 5,0 | 5,1 | 5,2 | 5,3 | 5,4 | 5,5 |
  +-----+-----+-----+-----+-----+-----+ 	 
		 
devolve 
	ponteiro para a nova matriz realocada

--------------------------------------
int **Liberar_matriz(int, int, int **)
--------------------------------------
recebe
	a quantidade de linhas e colunas da matriz
realiza
	a liberação de memória das colunas e das linhas da matriz
devolve
	ponteiro para a matriz
 
---------------------------------------
void Preencher_matriz(int, int, int **)
---------------------------------------
recebe
	a quantidade de linhas e colunas da matriz
realiza
  o preenchimento da matriz com números randômicos		

--------------------------------------
void Imprimir_matriz(int, int, int **)	 
--------------------------------------
recebe
	a quantidade de linhas e colunas da matriz
realiza
  a impressão na tela do conteúdo da matriz  
 
*/
int **Alocar_matriz(int, int);
int **Realocar_matriz(int, int, int, int, int **);
int **Liberar_matriz(int, int, int **);
void Preencher_matriz(int, int, int **);
void Imprimir_matriz(int, int, int **);

//*********************************************************
//Função main
//*********************************************************
int main ()
{
	int **mat;  /* matriz a ser alocada */
	int l, c;   /* numero de linhas e colunas da matriz */
	printf("Informe a quantidade de linhas e colunas: ");
	scanf("%d", &l);
  c = l;
	mat = Alocar_matriz(l, c);
	Preencher_matriz(l, c, mat);
	Imprimir_matriz(l, c, mat);
	mat = Realocar_matriz(l, c, (l * 2), (c * 2), mat);
	Imprimir_matriz(l * 2, c * 2, mat);
	mat = Liberar_matriz(l, c, mat);
	return 0;
}
//*********************************************************
//Função para alocar linhas e colunas da matriz
//*********************************************************
int **Alocar_matriz (int m, int n)
{
	int **v;  /* ponteiro para a matriz */
	int   i;  /* variavel auxiliar      */
	
	if ((m < 1) || (n < 1)) { /* verifica parametros recebidos */
		printf ("** Erro: Parametros invalidos **\n");
		return (NULL);
	}
	
	/* aloca as linhas da matriz */
	v = malloc (m * sizeof(int *));
	if (v == NULL) {
		printf ("** Erro: Memoria Insuficiente **");
		return (NULL);
	}
	
	/* aloca as colunas da matriz */
	for ( i = 0; i < m; i = i + 1 ) {
		v[i] = malloc (n * sizeof(int));
		if (v[i] == NULL) {
			printf ("** Erro: Memoria Insuficiente **");
			return (NULL);
		}
	}
	
	return(v); /* retorna o ponteiro para a matriz */
}
//*********************************************************
//Função para realocar linhas e colunas da matriz
//*********************************************************
int **Realocar_matriz(int l, int c, int m, int n, int **v)
{
//l - número de linhas atual da matriz
//c - número de colunas atual da matriz
//m - número de novas linhas para a matriz
//n - número de novas colunas para a matriz

	int i, col;
	
	/* realoca as linhas da matriz */
	v = realloc(v, (l + m) * sizeof(int *));
	
	/* realoca as colunas da matriz para as linhas já existentes*/
	for(i = 0; i < l; i = i + 1) {
		v[i] = realloc(v[i], (c + n) * sizeof(int));

		for(col = c; col < (c + n); col = col + 1)
			v[i][col] = rand() / 1000 + 1;

		if (v[i] == NULL) {
			printf ("** Erro: Memoria Insuficiente **");
			exit(1);
		}
	}
	
	/* aloca as colunas da matriz para as linhas novas*/
	for(i = l; i < (l + m); i = i + 1) {
		v[i] = malloc((c + n) * sizeof(int));

		for(col = 0; col < (l + m); col = col + 1)
			v[i][col] = rand() / 1000 + 1;

		if (v[i] == NULL) {
			printf ("** Erro: Memoria Insuficiente **");
			exit(1);
		}
	}
	return(v);
}
//*********************************************************
//Função para liberar linhas e colunas da matriz
//*********************************************************
int **Liberar_matriz(int m, int n, int **v)
{
	int  i;  /* variavel auxiliar */
	
	if (v == NULL)
		return (NULL);
	
	if (m < 1 || n < 1) {  /* verifica parametros recebidos */
		printf("** Erro: Parametro invalido **\n");
		return(v);
	}
	
	for(i = 0; i < m; i = i + 1)
		free(v[i]); /* libera as linhas da matriz */
	
	free(v);       /* libera a matriz */
	
	return (NULL); /* retorna um ponteiro nulo */
}
//*********************************************************
//Função para preencher linhas e colunas da matriz
//*********************************************************
void Preencher_matriz(int l, int c, int **v)
{
	int i, j;
	srand(time(NULL));
	for(i = 0; i < l; i= i + 1)
		for(j = 0; j < c; j = j + 1)
			v[i][j] = rand() / 1000 + 1;
}
//*********************************************************
//Função para imprimir linhas e colunas da matriz
//*********************************************************
void Imprimir_matriz(int l, int c, int **v)
{
	int i, j;
	printf("\n---------------------\n");
	for(i = 0; i < l; i = i + 1){
		for(j = 0; j < c; j = j + 1)
			printf("%3d ", v[i][j]);
		printf("\n");
	}
}

