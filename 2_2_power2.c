#include <stdio.h>
#include <stdlib.h>

void sums(long int countSum, int i, int n);
void ifPower2(long int x);

int power2;
long int * masNum;

int main(void)
{
	int n = 0;
	int i = 0;
	power2 = 0;
	scanf("%d", &n);
	masNum = (long int *)malloc(sizeof(long int) * n);
	if(masNum == NULL)
	{
		printf("Malloc ERROR");
		return 1;
	}
	for(i = 0; i < n; i++)
	{
		scanf("%ld", &masNum[i]);
	}
	sums(0, 0, n);
	printf("%d \n", power2);
	free(masNum);
	return 0;
}

void sums(long int countSum, int i, int n)
{
	for(; i < n; i++)
	{
		ifPower2(countSum+masNum[i]);
		sums(countSum+masNum[i], i + 1, n);
	}
}

void ifPower2(long int x)
{
	int count = 0;
	while(x != 0)
	{
		if(x == 1 && count == 0)
		{
			power2++;
			break;
		}
		if(x % 2 == 1)
		{
			count++;
		}
		x = x / 2;
	}
	
}

