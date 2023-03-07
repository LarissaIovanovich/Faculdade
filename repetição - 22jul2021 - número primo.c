#include <stdio.h>
int main()
{
	int num, C, soma;
	
	printf("Digite um numero para verificar se o mesmo e primo: ");
	scanf("%d",&num);
	
	soma = 0;
	C = num;
	while(C >= 1)
	{
		if(num % C == 0)
		{
			soma = soma + 1;
			if(soma == 3)
			{
				break;
			}
		}
		C = C - 1;
	}
	if(soma == 2)
	{
		printf("\nO numero %d e primo ",num);
	}
	else
	{
		printf("\nO numero %d nao e primo ",num);
	}
	
	return 0;
}