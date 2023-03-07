#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define lin 15
#define col 5
int main()
{
	int **matriz;
	int i, j;

	srand(time(NULL));

	matriz = malloc(lin * sizeof(int *));

	for(i = 0; i < lin; i++)
		matriz[i] = malloc (col * sizeof (int));

	for(i = 0; i < lin; i = i + 1)
		for(j = 0; j < col; j = j + 1)
			matriz[i][j] = rand()/100+1;

	printf("\n");

	for(i = 0; i < lin; i = i + 1)
		{
			for(j = 0; j < col; j = j + 1)
				printf("%5d",matriz[i][j]);
			printf("\n");
		}

	return 0;
}
