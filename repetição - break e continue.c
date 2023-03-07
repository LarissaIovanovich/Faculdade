#include <stdio.h>
int main(){
  int i;

  for(i = 1;i <= 10;i = i + 1){
    if (i % 3 == 0)
      continue;
    printf("\ncontinue - %d",i);
  }

  for(i = 1;i <= 10;i = i + 1){
    if (i % 3 == 0)
      break;
    printf("\nbreak - %d",i);
  }
  return 0;
}
