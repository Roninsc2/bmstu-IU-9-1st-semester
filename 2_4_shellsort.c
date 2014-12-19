#include <stdlib.h> 
#include <stdio.h> 
 
int *array; 
 
int compare(unsigned long i, unsigned long j) 
{ 
        /*if (i <= j) { 
                printf("COMPARE␣%d␣%d\n", i, j); 
        } else { 
                printf("COMPARE␣%d␣%d\n", j, i); 
        } */
 
        if (array[i] == array[j]) return 0; 
        return array[i] < array[j] ? -1 : 1; 
} 
 
void swap(unsigned long i, unsigned long j) 
{ 
       /* if (i <= j) { 
                printf("SWAP␣%d␣%d\n", i, j); 
        } else { 
                printf("SWAP␣%d␣%d\n", j, i); 
        } */
 
        int t = array[i]; 
        array[i] = array[j]; 
        array[j] = t; 
} 
 
void shellsort(unsigned long, int (*)(unsigned long, unsigned long), void (*)(unsigned long, unsigned long)); 
 
int main(int argc, char **argv) 
{ 
        int i, n; 
        scanf("%d", &n); 
 
        array = (int*)malloc(n * sizeof(int)); 
        for (i = 0; i < n; i++) scanf("%d", array+i); 
 
        shellsort(n, compare, swap); 
        for (i = 0; i < n; i++) printf("%d ", array[i]); 
        printf("\n"); 
 
        free(array); 
        return 0; 
}


void shellsort(unsigned long nel, int (*compare)(unsigned long i, unsigned long j), void (*swap)(unsigned long i, unsigned long j)) 
{ 
        unsigned int i = 0;
	unsigned int j = 0;
	unsigned int fibMax = 0;
	unsigned int a = 1;
	unsigned int b = 0;
	while((a + b) < nel)
	{
		fibMax = a + b;
		b = a;
		a = fibMax;
	}
	while(b > 0)
	{
        	for(i = fibMax; i < nel; i++)
		{
           		j = i - fibMax;
			while(j < nel && (compare(j, j + fibMax) == 1))
            		{
                		swap(j, j + fibMax);
				j -= fibMax;
			}
		}
		b = fibMax  - b;
		fibMax -= b;
	}
}
