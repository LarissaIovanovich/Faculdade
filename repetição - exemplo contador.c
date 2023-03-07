#include <stdio.h>
#include <locale.h>

int main(){
  setlocale(LC_ALL,"Portuguese");  
  int n, x; 
  
  do{
    printf("Digite um n�mero par e positivo: ");
    scanf("%d",&n); 
  }while((n <= 0) || (n % 2 != 0));
  
  printf("\nWHILE - primeiro verifica a condi��o e depois executa os comandos");
  x = 1; //inicializa��o do contador da estrutura de repeti��o
  while (x <= 10){ //condi��o de parada da estrutura de repeti��o
	printf("\n%2d X %2d = %2d",n,x,n*x);
	x = x + 1;//incremento do contador, para atingir o valor da condi��o de parada
  }
  
  printf("\n\nDO - WHILE - primeiro executa os comandos e depois verifica a condi��o");
  x = 1; //inicializa��o do contador da estrutura de repeti��o
  do{ //condi��o de parada da estrutura de repeti��o
	printf("\n%2d X %2d = %2d",n,x,n*x);
	x = x + 1;//incremento do contador, para atingir o valor da condi��o de parada
  }while (x <= 10);

//FOR(ini;cond;inc/dec){
// comandos
//}
//ini - inicializa��o das vari�veis de controle do la�o
//cond - condi��o de parada do la�o
//inc/dec - incremento ou decremento das vari�veis de controle do la�o	  
  
  printf("\n\nFOR - primeiro verifica a condi��o e depois executa os comandos");
  for(x = 1;x <= 10;x = x + 1)
  	printf("\n%2d X %2d = %2d",n,x,n*x);
  
  return 0;	  
}