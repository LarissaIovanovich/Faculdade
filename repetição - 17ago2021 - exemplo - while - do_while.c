#include <stdio.h>
#include <stdlib.h>
int main()
{
	float raio, area;
	int opcao;

	opcao = 1;

	while(opcao == 1)
		{
			system("cls");
			do
				{
					printf("\nDigite o raio da circunferencia: ");
					scanf("%f",&raio);
					if(raio <= 0)
					{
						printf("\nAs medidas devem ser sempre positivas\n\n");
						system("pause");
						system("cls");
					}
				}while(raio <= 0);
			area = 3.14 * raio * raio;
			printf("\nA area da circunferencia e %0.2f\n", area);
			do
				{
					printf("\nDeseja realizar outro calculo? 1 para SIM ou 2 para NAO ");
					scanf("%d",&opcao);
				}
			while((opcao != 1) && (opcao != 2));
		}

	return 0;
}
