#include <stdio.h>
#include <stdlib.h>

union Int32 { 
    int x; 
    unsigned char bytes[4]; 
};

void sort(int n, union Int32 * arr, int m, union Int32 * resultArr);
void radixSort(int n,union Int32 * arr);

int main(void)
{
	int n = 0;
	scanf("%d", &n);
	union Int32 * arr = malloc(sizeof(union Int32) * n);
	int i = 0;
	for(i = 0; i < n; i++)
	{
		scanf("%d", &arr[i].x);
	}
	radixSort(n, arr);
	for(i = 0; i < n; i++)
	{
		printf("%d ", arr[i].x);
	}
	printf("\n");
	free(arr); 
	return 0;
}

void radixSort(int n, union Int32 * arr)
{
	union Int32 * helpArr = malloc(sizeof(union Int32) * n);
	int i = 0;
	int j = 0;
	for(i = 0; i  < 4; i++)
	{
		sort(n, arr, i , helpArr);
		for(j = 0; j < n; j++)
		{
			arr[j] = helpArr[j];
		}
	}
	free(helpArr);
}

void sort(int n, union Int32 * arr, int m, union Int32 * resultArr)
{
	unsigned char * helpArr = calloc(256, sizeof(unsigned char));
	int j = 0;	
	int i = 0;
	for(j = 0; j < n; j++)
	{
		helpArr[arr[j].bytes[m]]++;
	}
	if(m != 3)
	{
		for(i = 1; i < 256; i++)
		{
			helpArr[i] += helpArr[i-1];
		}
	}
	else
	{
		for(i = 129; i < 256; i++)
		{
			helpArr[i] += helpArr[i-1];
		}
		helpArr[0] += helpArr[255];
		for(i = 1; i < 128; i++)
		{
			helpArr[i] += helpArr[i-1];
		}
	}
	j = n - 1;
	while(j >= 0)
	{
		i = helpArr[arr[j].bytes[m]] - 1;
		helpArr[arr[j].bytes[m]] = i;
		resultArr[i] = arr[j];
		j--;
	}	
	free(helpArr);
}
