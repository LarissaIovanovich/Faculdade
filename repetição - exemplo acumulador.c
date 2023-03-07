//um determinado material radioativo perde 50% de sua massa a cada
//70 segundos
//determinar quanto tempo, em segundos, este material leva para que sua massa
//seja menor do que 0.05gramas, tendo como dado de entrada sua massa
//em gramas
#include <stdio.h>
#include <locale.h>

int main(){
  setlocale(LC_ALL,"Portuguese");  
  int t;
  float massa, m; 
  
  do{
    printf("Digite a massa do material em gramas: ");
    scanf("%f",&massa); 
  }while(massa <= 0);
  m = massa;
  printf("\nWHILE - primeiro verifica a condição e depois executa os comandos");
  t = 0;
  while (massa > 0.05){
  	massa = massa / 2.0;
 	t = t + 70;
  }
  printf("\nTempo -> %d",t);
  massa = m;
  printf("\n\nDO - WHILE - primeiro executa os comandos e depois verifica a condição");
  t = 0;
   do{ 
    massa = massa / 2.0;
 	t = t + 70;
  } while (massa > 0.05);
  printf("\nTempo -> %d",t);
  printf("\n\nFOR - primeiro verifica a condição e depois executa os comandos");
  t = 0;
  for(t = 0, massa = m; massa > 0.05;massa = massa / 2.0,t = t + 70);
  printf("\nTempo -> %d",t);  

  return 0;	  
}