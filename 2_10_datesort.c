#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int saveArr[] ={61, 12, 31};
int saveArr1[] = {1970, 1, 1};

struct Date 
{ 
	int Year;
	int Month;
	int Day;
};


void sort(int n, struct Date * arr, int m, struct Date * resultArr);
void radixSort(int n, struct Date * arr);



int main(void)
{
	int n = 0;
	scanf("%d", &n);
	struct Date * arr = (struct Date *)malloc(sizeof(struct Date) * n);
	int i = 0;
	for(i = 0; i < n; i++)
	{
		scanf("%d %d %d", &arr[i].Year, &arr[i].Month, &arr[i].Day);
	}
	radixSort(n, arr);
	for(i = 0; i < n; i++)
	{
		printf("%d %d %d \n",  arr[i].Year, arr[i].Month, arr[i].Day);
	}
	free(arr);
	return 0;
}

void radixSort(int n, struct Date * arr)
{
	struct Date * resultArr = (struct Date *)malloc(sizeof(struct Date) * n);
	int i = 0;
	int j = 0;
	for(i = 2; i >= 0; i--)
	{
		sort(n, arr, i, resultArr);
		for(j = 0; j < n; j++)
		{
			arr[j] = resultArr[j];
		}
	}
	free(resultArr);
}

void sort(int n, struct Date * arr, int m, struct Date * resultArr)
{
	int * helpArr = calloc(saveArr[m], sizeof(int));
	if(m == 0)
	{
		int j = 0;	
		int i = 0;
		for(j = 0; j < n; j++)
		{
			helpArr[arr[j].Year-saveArr1[m]]++;
		}
		for(i = 1; i < saveArr[m]; i++)
		{
			helpArr[i] += helpArr[i-1]; 
		}
		j = n - 1;
		while(j >= 0)
		{
			i = helpArr[arr[j].Year -saveArr1[m]] - 1;
			helpArr[arr[j].Year - saveArr1[m]] = i;
			resultArr[i] = arr[j];
			j--;
		}	
	}
	if(m == 1)
	{
		int j = 0;	
		int i = 0;
		for(j = 0; j < n; j++)
		{
			helpArr[arr[j].Month - saveArr1[m]]++;
		}
		for(i = 1; i < saveArr[m]; i++)
		{
			helpArr[i] += helpArr[i-1]; 
		}
		j = n - 1;
		while(j >= 0)
		{
			i = helpArr[arr[j].Month - saveArr1[m]] - 1;
			helpArr[arr[j].Month - saveArr1[m]] = i;
			resultArr[i] = arr[j];
			j--;
		}
	}
	if(m == 2)
	{
		int j = 0;	
		int i = 0;
		for(j = 0; j < n; j++)
		{
			helpArr[arr[j].Day-saveArr1[m]]++;
		}
		for(i = 1; i < saveArr[m]; i++)
		{
			helpArr[i] += helpArr[i-1]; 
		}
		j = n - 1;
		while(j >= 0)
		{
			i = helpArr[arr[j].Day -saveArr1[m]] - 1;
			helpArr[arr[j].Day-saveArr1[m]] = i;
			resultArr[i] = arr[j];
			j--;
		}
	}	
	free(helpArr);
}

