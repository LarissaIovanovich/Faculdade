/*
4) Calcular o volume de um cilindro. 
Perguntar ao usu�rio se h� outros c�lculos 
a serem realizados para continuar ou n�o o programa.

entradas de dados:
	para cada volume que ser� calculado:
		raio, altura
sa�das de dados:
	para cada volume calculado:
		volume do cilindro
processamento
1 - obter o raio do cilindro
2 - obter a altura do cilindro
3 - calcular o volume do cilindro
4 -		volume = 	PI * raio ^ 2 * altura  
5 -	mostrar o volume calculado
6 - perguntar ao us�rio se deseja realizar outro c�lculo
			caso positivo, recome�ar a partir do passo 1
			caso negativo, encerrar o programa
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>
#include <string.h>
int main()
{
	setlocale(LC_ALL,"Portuguese");
	float volume, raio, altura;
	char controle[4];
	
	do
	{
		printf("\nDigite a altura do cilindro: ");
		scanf("%f",&altura);
		printf("\nDigite o raio do cilindro: ");
		scanf("%f",&raio);
		volume = M_PI * pow(raio,2.0) * altura;
		printf("\nO volume do cilindro � %0.2f\n",volume);
		
		printf("\nDeseja realizar outro c�lculo? Digite SIM ou N�O ");
		fflush(stdin);
		gets(controle);
			
	}while(strcmp(strupr(controle),"SIM") == 0);
	
	return 0;
}
