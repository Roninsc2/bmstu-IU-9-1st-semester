#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void insertSort(int * arr, int low, int high);
void merge(int k, int l, int m, int * arr);
void mergeSort(int size, int * arr);
int mergeSortRec(int low, int high, int * arr);


int main(void)
{
        int size = 0;
	int i = 0;
	scanf("%d", &size);
	int * arr = malloc(sizeof(int) * size);
	for(i = 0; i < size; i++)
	{
		scanf("%d", &arr[i]);
	}
	mergeSort(size, arr);
	for(i = 0; i < size; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
	free(arr);
	return 0;
}
//сортировка сляинением

void merge(int low, int mid, int high, int * arr)//функция слияния
{
	int * helpArr = malloc(sizeof(int) * (high - low + 1));//вспомогательный массив
	int low_cur= low;//нижний счетчик
	int high_cur = mid+1;//верхний счетчик
	int helpArr_cur= 0;//счетчик вспомогательного массива
	int i = 0;
	int j = 0;
	while(helpArr_cur < (high - low + 1))
	{
		if(high_cur <= high && low_cur <= mid)
		{
			if(abs(arr[high_cur]) < abs(arr[low_cur]))
			{
				helpArr[helpArr_cur] = arr[high_cur];
				high_cur++;
			}
			else
			{
				helpArr[helpArr_cur] = arr[low_cur];
				low_cur++;
			}
		}
		else//если в одной из половинок больше элементов, чем в другой
		{
			if(low_cur > mid)
			{
				helpArr[helpArr_cur] = arr[high_cur];
				high_cur++;
			}
			else//
			{
				helpArr[helpArr_cur] = arr[low_cur];
				low_cur++;
			}
		}
		helpArr_cur++;
	}
	for(i = low; i <= high; i++)//записываем отсортированный массив
	{
		arr[i] = helpArr[i - low];
	}
	free(helpArr);
}

void mergeSort(int size, int * arr)
{
	mergeSortRec(0, size-1, arr);
}

int mergeSortRec(int low, int high, int * arr)//рекусривная функция, которая разбивает массив пополами, а затем отсортировывает его
{
	if((high - low) < 5)
	{
		insertSort(arr,low,high);
		return 0;
	}
	int mid = 0;
	while(low < high)
	{
		mid = (high - low)/2 + low;
		mergeSortRec(low, mid, arr);
		mergeSortRec(mid+1, high, arr);
		merge(low, mid, high, arr);
		break;
	}
	return 0;
}
//сортировка вставками
void insertSort(int * arr, int low, int high)
{
	int i = 0;
	int j = 0;
	int temp = 0;
	for(i = low; i <= high; i++)
	{
		temp = arr[i];
		for(j = i-1; j >= 0; j--)
		{
			if(abs(arr[j]) <= abs(temp))
			{
				break;
			}
			else
			{
				arr[j + 1] = arr[j];
				arr[j] = temp;
			}	
		}
	}
}
