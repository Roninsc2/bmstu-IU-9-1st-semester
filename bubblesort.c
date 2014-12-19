#include <stdlib.h> 
#include <stdio.h> 
 
int *array; 
 
int compare(unsigned long i, unsigned long j) 
{
        if (array[i] == array[j]) return 0; 
        return array[i] < array[j] ? -1 : 1; 
} 
 
void swap(unsigned long i, unsigned long j) 
{
        int t = array[i]; 
        array[i] = array[j]; 
        array[j] = t; 
} 
 
void bubblesort(unsigned long, 
        int (*)(unsigned long, unsigned long), 
        void (*)(unsigned long, unsigned long)); 
 
int main(int argc, char **argv) 
{ 
        int i, n; 
        scanf("%d", &n); 
 
        array = (int*)malloc(n * sizeof(int)); 
        for (i = 0; i < n; i++) scanf("%d", array+i); 
 
        bubblesort(n, compare, swap); 
        for (i = 0; i < n; i++) printf("%d ", array[i]); 
        printf("\n"); 
 
        free(array); 
        return 0; 
}

void bubblesort(unsigned long nel, int (*compare)(unsigned long, unsigned long), void (*swap)(unsigned long, unsigned long))
{
	int k = nel - 1;
	int m = 0;
	int z = 0;
	int n = 0;
	int i = 0;
	while (k > 0 && m < nel - 1)
	{
		z = k;
		n = m;
		k = 0;
		m = nel - 1;
		for (i = n; i < z; i++)
		{
			if (compare(i, i + 1) == 1) 
			{
				swap(i, i + 1);
				k = i;
			}
		}
		for (i = k; i > n; i--)
 		{
			if (compare(i, i - 1) == -1)
			{
				swap(i, i - 1);
				m = i;
			}
		}
	}
}
