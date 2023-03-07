/*
Potência de grau 2

Potência de grau 2 do número 5 = 25

5^2 = 1 + 3 + 5 + 7 + 9 = 25 
3^2 = 1 + 3 + 5 = 9

Potência de grau de 2 de um número n, é a soma dos n
primeiros números naturais ímpares.

para obter a potencia de grau 2 de um numero, primeiro
eu devo obter este numero (pedir para o usuário digitar
e armazenar em uma variável)
somar o primeiro número ímpar (que é 1)
depois eu preciso adicionar 2 ao número ímpar (1), para
obter o próximo número ímpar (3)
preciso verificar se já somei a quantidade necessária
de números ímpares (números somados na mesma quantidade da
base da potência)
se eu já somei a quantidade de números necessária, devo
mostrar o resultado, senão 

*/
#include <stdio.h>
int main()
{
	int numero, soma, impar, quantidade;
	
	soma = 0;
	impar = 1;
	quantidade = 1;
	
	printf("\nDigite um numero inteiro: ");
	scanf("%d",&numero);
	
	while(quantidade <= numero)
	{
		soma = soma + impar;
		impar = impar + 2;
		quantidade = quantidade + 1;
	}
	
	printf("\nA potencia de grau 2 de %d e %d",numero, soma);
	
	return 0;
}
