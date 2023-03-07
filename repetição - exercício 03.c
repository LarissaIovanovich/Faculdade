/*
2) Calcular a média final obtida por um grupo de 22 alunos, 
para 4 notas bimestrais.
-----------------------------------------
entradas de dados:
  quatro notas bimestrais, para um grupo de 22 alunos
saídas de dados:
  média da turma
processamento:
  para cada um dos 22 alunos de uma turma:
    obter a nota1
    obter a nota2
    obter a nota3
    obter a nota4
    calcular a media das quatro notas
    somar a media calculada
  dividir a soma das medias calculadas por 22 
	mostrar o resultado encontrado
*/
#include <stdio.h>
#include <locale.h>
int main(){
	setlocale(LC_ALL,"Portuguese");
	float n1, n2, n3, n4, media, soma;
	int quantidade;
	
	printf("\nCalcula a media de uma turma de 22 alunos, para 4 notas bimestrais");
	
	soma = 0;
	quantidade = 1;
	while(quantidade <= 22){
	  
		do{
		  printf("\nDigite a primeira nota do %dº aluno: ",quantidade);
		  scanf("%f",&n1);
		}while ((n1 < 0) || (n1 > 10));
		
		do{	
		  printf("\nDigite a segunda nota do %dº aluno: ",quantidade);
		  scanf("%f",&n2);
		}while ((n2 < 0) || (n2 > 10));
		
		do{
		  printf("\nDigite a terceira nota do %dº aluno: ",quantidade);
		  scanf("%f",&n3);
		}while ((n3 < 0) || (n3 > 10));
		
		do{
		  printf("\nDigite a quarta nota do %dº aluno: ",quantidade);
		  scanf("%f",&n4);
		}while ((n4 < 0) || (n4 > 10));
		
		media = (n1 + n2 + n3 + n4) / 4;
		soma = soma + media;
		quantidade = quantidade + 1;
	}
	printf("\nA media da turma e %2.1f",soma / 22);
	return 0;
}


