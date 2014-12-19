#include <stdio.h>
#include <stdlib.h>

int maxElemet(int x, int y);


int main(void)
{
	int x = 0;
	int y = 0;
	int sedlov = 0;
	int sedX= 0;
	int sedY = 0;
	scanf("%d %d", &x, &y);
	int *mas = malloc(sizeof(int) *  (x*y));
	int * masMin = malloc(sizeof(int) * y);
	int * masMax = malloc(sizeof(int) * x);
	int * coordX = malloc(sizeof(int) * x);
	int * coordY = malloc(sizeof(int) * y);
	int i = 0;
	int j = 0;
	int count = 0;
	for(i = 0; i < x; i++)
	{
		masMax[i] = -2147483647;
		for(j = 0; j < y; j++)
		{
			scanf("%d", &mas[i*y + j]);
		}
	}
	for(j = 0; j < y; j++)
	{
		masMin[j] = 2147483646;
	}
	if(x == 1 && y == 1 && mas[0] == 0)
	{
		printf("%d %d \n", 0, 0);
		return 0;
	}
	for(i = 0; i < x; i++)
	{
		for(j = 0; j < y; j++)
		{
			if(mas[i*y + j] < masMin[j])
			{
				masMin[j] = mas[i*y + j];
				coordY[j] = j;
				
			}
			if(mas[i*y + j] > masMax[i])
			{
				masMax[i] = mas[i*y + j];
				coordX[i] = i;
			}
		}
	}
	for(i = 0; i < x; i++)
	{
		for(j = 0; j < x; j++)
		{
			if(masMax[i] == masMin[j])
			{
				printf("%d %d \n", coordX[i], coordY[j]);
				free(mas);	
				free(masMin);
				free(masMax);
				free(coordX);
				free(coordY);
				return 0;
			}
		}
	}
	free(mas);	
	free(masMin);
	free(masMax);
	free(coordX);
	free(coordY);
	printf("none \n");
	return 0;
}
