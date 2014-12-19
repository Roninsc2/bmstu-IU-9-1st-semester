#include <stdio.h>
#include <stdlib.h>

void quicksort(int n, int m, int * arr);
int quicksortRec(int low, int high, int * arr, int m);//функция рекурсивного вызова, в которой
//я избавляюсь от второго рекурсивного вызова
void selectSort(int low, int high, int * arr);//функция сортировки прямым выбором
int partition(int low, int high, int * arr);//разделение подпоследовательности относительно
//элемета с индексом high. Возвращает границу разделения

int main(void)
{
        int m = 0;
	int n = 0;
	scanf("%d %d", &n, &m);
	int * arr = malloc(sizeof(int) * n);
	int i = 0;
	for(i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
	}
	quicksort(n, m, arr);
	for(i = 0; i < n; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
	free(arr);
	return 0;
}


void quicksort(int n, int m, int * arr)
{
	quicksortRec(0, n-1, arr, m);

}

int quicksortRec(int low, int high, int * arr, int m)
{
	int q = 0;
	while((high-low) >= m)
	{
		q = partition(low, high, arr);
		if((high - q) < (q - low))
		{
			quicksortRec(q+1, high, arr, m);
			high = q - 1;
		}
		else
		{
			quicksortRec(low, q-1, arr, m);
			low = q + 1;
		}
	}
	selectSort(low, high, arr);
	return 0;
}

int partition(int low, int high, int * arr)
{
	int i = low;
	int j = low;
	int t = 0;
	while(j < high)
	{
		if(arr[j] < arr[high])
		{
			t = arr[i];
			arr[i] = arr[j];
			arr[j] = t;
			i++;
		}
		j++;
	}
	t = arr[i];
	arr[i] = arr[high];
	arr[high] = t;
	return i;
}


void selectSort(int low, int high, int * arr)
{
	int j = high;
	int k = 0;
	int i = 0;
	int t = 0;
	while(j >= low)
	{
		k = j;
		i = j - 1;
		while(i >= 0)
		{
			if(arr[k] < arr[i])
			{
				k = i;
			}
			i--;
		}
		t = arr[j];
		arr[j] = arr[k];
		arr[k] = t;
		j--;
	}
}
