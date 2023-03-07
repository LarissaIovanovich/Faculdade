#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
#include <windows.h>
#include <stdint.h>
uint32_t stampstart();
uint32_t stampstop(uint32_t start);
struct tmp
{
	uint32_t ini, fim;
};
typedef struct tmp TMP;

//******************************
//HORA DO SISTEMA INICIAL
//******************************
uint32_t stampstart()
{
	struct timeval  tv;
	struct timezone tz;
	struct tm      *tm;
	uint32_t        start;
	gettimeofday(&tv, &tz);
	tm = localtime(&tv.tv_sec);
	printf("\nTIMESTAMP-START\t  %d:%02d:%02d:%d (~%d ms)\n", tm->tm_hour,
	       tm->tm_min, tm->tm_sec, tv.tv_usec,
	       tm->tm_hour * 3600 * 1000 + tm->tm_min * 60 * 1000 +
	       tm->tm_sec * 1000 + tv.tv_usec / 1000);
	start = tm->tm_hour * 3600 * 1000 + tm->tm_min * 60 * 1000 +
	        tm->tm_sec * 1000 + tv.tv_usec / 1000;
	return (start);
}
//******************************
//HORA DO SISTEMA FINAL
//******************************
uint32_t
stampstop(uint32_t start)
{
	struct timeval  tv;
	struct timezone tz;
	struct tm      *tm;
	uint32_t         stop;
	gettimeofday(&tv, &tz);
	tm = localtime(&tv.tv_sec);
	stop = tm->tm_hour * 3600 * 1000 + tm->tm_min * 60 * 1000 +
	       tm->tm_sec * 1000 + tv.tv_usec / 1000;
	printf("\nTIMESTAMP-END\t  %d:%02d:%02d:%d (~%d ms) \n", tm->tm_hour,
	       tm->tm_min, tm->tm_sec, tv.tv_usec,
	       tm->tm_hour * 3600 * 1000 + tm->tm_min * 60 * 1000 +
	       tm->tm_sec * 1000 + tv.tv_usec / 1000);
	printf("ELAPSED\t  %d ms\n", stop - start);
	return (stop);
}

int main()
{
	TMP compara[2];
	int *vetor1;
	int *vetor2;
	int i;

  compara[0].ini = stampstart();
  vetor1 = malloc(10000000 * sizeof(int));
	compara[0].fim  = stampstop(compara[0].ini);

  compara[1].ini = stampstart();
  vetor2 = calloc(10000000,sizeof(int));
	compara[1].fim  = stampstop(compara[1].ini);

	printf("\nVetor 1 ------> ~%10d ms", compara[0].fim - compara[0].ini);
	printf("\nVetor 2 ------> ~%10d ms", compara[1].fim - compara[1].ini);

  free(vetor1);
  free(vetor2);

  return 0;
}
