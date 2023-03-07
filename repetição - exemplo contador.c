#include <stdio.h>
#include <locale.h>

int main(){
  setlocale(LC_ALL,"Portuguese");  
  int n, x; 
  
  do{
    printf("Digite um número par e positivo: ");
    scanf("%d",&n); 
  }while((n <= 0) || (n % 2 != 0));
  
  printf("\nWHILE - primeiro verifica a condição e depois executa os comandos");
  x = 1; //inicialização do contador da estrutura de repetição
  while (x <= 10){ //condição de parada da estrutura de repetição
	printf("\n%2d X %2d = %2d",n,x,n*x);
	x = x + 1;//incremento do contador, para atingir o valor da condição de parada
  }
  
  printf("\n\nDO - WHILE - primeiro executa os comandos e depois verifica a condição");
  x = 1; //inicialização do contador da estrutura de repetição
  do{ //condição de parada da estrutura de repetição
	printf("\n%2d X %2d = %2d",n,x,n*x);
	x = x + 1;//incremento do contador, para atingir o valor da condição de parada
  }while (x <= 10);

//FOR(ini;cond;inc/dec){
// comandos
//}
//ini - inicialização das variáveis de controle do laço
//cond - condição de parada do laço
//inc/dec - incremento ou decremento das variáveis de controle do laço	  
  
  printf("\n\nFOR - primeiro verifica a condição e depois executa os comandos");
  for(x = 1;x <= 10;x = x + 1)
  	printf("\n%2d X %2d = %2d",n,x,n*x);
  
  return 0;	  
}