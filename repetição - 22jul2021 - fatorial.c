#include <stdio.h>
int main()
{
	double num, fat;
	
	printf("Digite um numero para calcular seu fatorial: ");
	scanf("%lf",&num);
	
	fat = num - 1;
	while(fat >= 1)
	{
		num = num * fat;
		fat = fat - 1;
	}
	printf("\n%lf\n",num);

	return 0;	
}