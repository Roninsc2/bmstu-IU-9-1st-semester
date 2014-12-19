#include <stdlib.h>
#include <stdio.h>
#include <math.h>

void kadane(float * arr, int nel, int * resultArr);

int main(void)
{
	unsigned int nel = 0;
	scanf("%u", &nel);
	float * mainArr = malloc(sizeof(float)*nel);
	int i = 0;
	int x = 0;
	int y = 0;
	char str;
 	for(i = 0; i < nel; i++)
	{
		scanf("%d%c%d", &x, &str, &y );
		mainArr[i] = log((float)x/(float)y);
	}
	int result[2] = {0, 0};
	kadane(mainArr, nel, result);
	printf("%d %d \n", result[0], result[1]);
	free(mainArr);
	return 0;
}

void kadane(float * arr, int nel, int * resultArr)
{
	int l = 0;
	int r = 0;
 	float max = -100000;
	int start = 0;
	float countMax = 0;
	int i = 0;
	while(i < nel)
	{
		countMax = countMax + arr[i];
		if(countMax > max)
		{
			max  = countMax;
			resultArr[0] = start;
			resultArr[1] = i;
		}
		i++;
		if(countMax  < 0)
		{
			countMax = 0;
			start = i;
		}
	}
}
