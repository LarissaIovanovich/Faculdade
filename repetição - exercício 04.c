/*
4) Calcular o volume de um cilindro. 
Perguntar ao usuário se há outros cálculos 
a serem realizados para continuar ou não o programa.

entradas de dados:
	para cada volume que será calculado:
		raio, altura
saídas de dados:
	para cada volume calculado:
		volume do cilindro
processamento
1 - obter o raio do cilindro
2 - obter a altura do cilindro
3 - calcular o volume do cilindro
4 -		volume = 	PI * raio ^ 2 * altura  
5 -	mostrar o volume calculado
6 - perguntar ao usário se deseja realizar outro cálculo
			caso positivo, recomeçar a partir do passo 1
			caso negativo, encerrar o programa
*/
#include <stdio.h>
#include <math.h>
#include <locale.h>
int main()
{
	setlocale(LC_ALL,"Portuguese");
	float volume, raio, altura;
	int controle;
	
	do
	{
		printf("\nDigite a altura do cilindro: ");
		scanf("%f",&altura);
		printf("\nDigite o raio do cilindro: ");
		scanf("%f",&raio);
		volume = M_PI * pow(raio,2.0) * altura;
		printf("\nO volume do cilindro é %0.2f\n",volume);
		
		printf("\nDeseja realizar outro cálculo? 1 para SIM ou 2 para NÃO ");
		scanf("%d",&controle);	
	}while(controle == 1);
	
	return 0;
}
