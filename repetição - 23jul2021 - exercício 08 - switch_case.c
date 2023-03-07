/*
08) Perguntar ao usuário se ele deseja calcular:
a) a área de um triângulo
b) a área de um círculo
c) a área de um cubo
d) a área de um cilindro
Solicitar os dados necessários para calcular a área escolhida,
e mostrar o resultado na tela.

entradas de dados:
------------------
	triângulo
		base, altura
	círculo
		raio
	cubo
		aresta
	cilindro
		altura, raio

saídas de dados:
----------------
	a área de um triângulo
	ou
	a área de um círculo
	ou
	a área de um cubo
	ou
	a área de um cilindro

processamento:
--------------
	mostrar na tela as opções para o usuário
		a - a área de um triângulo
		b - a área de um círculo
		c - a área de um cubo
		d - a área de um cilindro
	obter a opção desejada
	SE a opção for (a) ENTÃO
		obter a base
		obter a altura
		area = base * altura / 2
		mostrar a area calculada
		SENÃO
			SE a opção for (b) ENTÃO
				obter o raio
				area = PI * raio ^ 2
				mostrar a area calculada
				SENÃO
					SE opção for (c) ENTÃO
						obter a aresta
						area = aresta ^ 2 * 6
						mostrar a area calculada
						SENÃO
							SE a opção for (d) ENTÃO
								obter o raio
								obter a altura
								area = 2 * PI * raio ^ 2 + PI * raio * altura
								mostrar a area calculada
								SENÃO
									mostrar mensagem "opção incorreta"
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
int main()
{
	float area, base, altura, raio, aresta;
	int opcao, fim;

	fim = 1;

	while(fim == 1)
		{
			printf("\nEscolha uma das opcoes abaixo");
			printf("\n1 - a area de um triangulo");
			printf("\n2 - a area de um circulo");
			printf("\n3 - a area de um cubo");
			printf("\n4 - a area de um cilindro");
			printf("\n --> ");
			scanf("%d",&opcao);

			switch(opcao)
				{
					case 1:
						printf("\nDigite a base do triangulo: ");
						scanf("%f",&base);
						printf("\nDigite a altura do triangulo: ");
						scanf("%f",&altura);
						area = base * altura / 2;
						printf("\nA area do triangulo e igual a %0.2f",area);
						break;
					case 2:
						printf("\nDigita o raio do circulo: ");
						scanf("%f",&raio);
						area = M_PI * pow(raio,2.0);
						printf("\nA area do circulo e igual a %0.2f",area);
						break;
					case 3:
						printf("\nDigita a aresta do cubo: ");
						scanf("%f",&aresta);
						area = pow(aresta,2.0) * 6;
						printf("\nA area do cubo e igual a %0.2f",area);
						break;
					case 4:
						printf("\nDigite o raio do cilindro: ");
						scanf("%f",&raio);
						printf("\nDigite a altura do cilindro: ");
						scanf("%f",&altura);
						area = 2 * M_PI * pow(raio,2.0) + M_PI * raio * altura;
						printf("\nA area do cilindro e igual a %0.2f",area);
						break;
					default:
						printf("\nopcao incorreta\n");
				}
			printf("\nDeseja continuar? 1 para SIM ou 0 para NAO: ");
			scanf("%d",&fim);
			system("cls");
		}

	return 0;
}
