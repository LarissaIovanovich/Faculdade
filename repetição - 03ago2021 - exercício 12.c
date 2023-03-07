/*
4. Escreva um programa que calcule:
a) a área de um triângulo
b) a área de um círculo
c) a área de um cubo
d) a área de um cilindro
Solicitar os dados necessários para calcular cada área,
mostrando o resultado na tela

entradas de dados:
------------------
	triângulo
		base, altura
	círculo
		raio
	cubo
		aresta
	cilindro
		raio, altura

saídas de dados:
----------------
	área
		triângulo
		círculo
		cubo
		cilindro

processamento:
--------------
	obter a altura do triângulo
	obter a base do triângulo
	calcular a área do triângulo
		área = base * altura / 2
	mostrar o valor calculado
		área (triângulo)
-----------------------------------
	obter o raio do círculo
	calcular a área do círculo
		área = 3.14 * raio^2
	mostrar o valor calculado
		área (círculo)
-----------------------------------
	obter a aresta do cubo
	calcular a área do cubo
		área = aresta^2 * 6
	mostrar o valor calculado
		área (cubo)
-----------------------------------
	obter a altura do cilindro
	obter o raio do cilindro
	calcular a área do cilindro
		área = 2 * 3.14 * raio^2 + 2 * 3.14 * raio * altura
	mostrar o valor calculado
		área (cilindro)
-----------------------------------
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
	float area, raio, base, altura, aresta;
	int opcao, final, tri;

	final = 1;

	while(final == 1)
		{
			printf("\nSelecione uma opcao");
			printf("\n1 - a area de um triangulo");
			printf("\n2 - a area de um circulo");
			printf("\n3 - a area de um cubo");
			printf("\n4 - a area de um cilindro\n");
			scanf("%d",&opcao);

			switch(opcao)
				{
					case 1:
						tri = 1;
						while(tri == 1)
							{
								printf("\n----------------------------------------------");
								printf("\nCalcular a area de um triangulo");
								printf("\n----------------------------------------------");
								printf("\nDigite a base e a altura, separados por ENTER\n");
								scanf("%f%f",&base,&altura);
								area = base * altura / 2;
								printf("\nA area do triangulo e %f",area);
								printf("\n\nDeseja calcular outro triangulo? 1 SIM ou 2 NAO ");
								scanf("%d",&tri);
							}
						break;
					case 2:
						printf("\n----------------------------------------------");
						printf("\nCalcular a area de um circulo");
						printf("\n----------------------------------------------");
						printf("\nDigite o raio do circulo\n");
						scanf("%f",&raio);
						area = M_PI * pow(raio,2.0);
						printf("\nA area do circulo e %f",area);
						break;
					case 3:
						printf("\n----------------------------------------------");
						printf("\nCalcular a area de um cubo");
						printf("\n----------------------------------------------");
						printf("\nDigite a aresta do cubo\n");
						scanf("%f",&aresta);
						area = pow(aresta,2.0) * 6.0;
						printf("\nA area do cubo e %f",area);
						break;
					case 4:
						printf("\n----------------------------------------------");
						printf("\nCalcular a area de um cilindro");
						printf("\n----------------------------------------------");
						printf("\nDigite a altura e o raio, separados por ENTER\n");
						scanf("%f%f",&altura,&raio);
						area = 2 * M_PI * pow(raio,2.0) + 2 * M_PI * raio * altura;
						printf("\nA area do cilindro e %f",area);
						break;
					default:
						printf("\nOpcao incorreta\n");
				}
			printf("\n\nDeseja continuar com outros calculos? 1 para SIM ou 2 para NAO ");
			scanf("%d",&final);
			system("cls");
		}
	return 0;
}
