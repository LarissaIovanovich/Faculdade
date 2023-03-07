/*
1) Obter o nome e a idade de um usuário e escrever na tela a 
seguinte mensagem: Hello! FULANO, você
tem XX anos, para um grupo de 10 pessoas.

*/
#include <stdio.h>
#include <stdlib.h>
int main()
{
	char letra;
	char nome[100]; //string (corda - string é sequencia de vários char)
	int idade, qpessoas;
	
	qpessoas = 1;
	
	while(qpessoas <= 10)
	{
		printf("\nDigite seu nome: ");
		fflush(stdin); //limpa buffer de teclado - incluir stdlib.h
		gets(nome);
		
    printf("\nDigite sua idade: ");
		scanf("%d",&idade);
				
		printf("\nHello! %s, voce tem %d anos",nome,idade);
		
		qpessoas = qpessoas + 1;			
	}
  return 0;	
}