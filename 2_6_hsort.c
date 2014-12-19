//зачем сортировка произвольного массива, если мы сортируем строки?!


#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void buildHeap (void *base, int nel, int width);
int compare(const void *a, const void *b);
void hsort (void *base, int nel, int width);
void heapify (void *base, int i, int nel, int width);
void swap(const void * a, const void * b, int width);


int main(void)
{
        int n = 0;
	scanf("%d ", &n);
	char ** strArr = malloc(sizeof(char *)*n);
	int i = 0;
	for(i = 0; i < n; i++)
	{
		strArr[i] = (char *)calloc(50,sizeof(char));
		gets(strArr[i]);
	}
	hsort(strArr, n, 50*sizeof(char));
	for(i = 0; i < n; i++)
	{
		printf("%s \n", ((char *)strArr[i]));
	}
	for(i = 0; i < n; i++)
	{
		free(strArr[i]);
	}
	free(strArr);
}


void swap(const void * a, const void * b, int width)
{
	char * arr = malloc(sizeof(char)*width);
	memcpy(arr, ((char **)a), width);
       	memcpy(((char **)a), ((char **)b), width);
        memcpy(((char **)b), arr, width);
	free(arr);
}

int compare(const void *a, const void *b) 
{
	int i = 0;
	int countA = 0;
	int countB = 0;
    	while(((char*)a)[i] != '\0')
	{
		if (((char*)a)[i]=='a')
		{
			countA++;
		}
		i++;
	}
	i = 0;
	while(((char*)b)[i]!='\0')
	{
		 if (((char*)b)[i]=='a')
		{
			countB++;
		}
		i++;
	}
  	if(countA <= countB)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

void hsort (void *base, int nel, int width)
{
    	int i = nel - 1;
    	buildHeap(base, nel, width);
    	while(i > 0)
	{
		swap(((char **)base)[i], ((char **)base)[0], width);
		heapify(base, 0, i, width);
		i--;
	}
}

void heapify (void *base, int i, int nel, int width)
{
    	int l = 0;
	int j = 0; 
	int r = 0;
	while(1)
	{
		l = 2*i + 1;
		r = l + 1;
		j = i;
		if (l < nel && (compare(((char**)base)[i], ((char**)base)[l])==1))
		{
			i = l;
		}
        	if (r < nel && (compare(((char**)base)[i], ((char**)base)[r]) == 1)) 
		{
			i = r;
		}
       		if (i==j) 
		{
			break;
		}
		swap(((char **)base)[i], ((char **)base)[j], width);
	}
}

void buildHeap (void *base, int nel, int width)
{
    	int i = nel/2;
	while (i >= 0)
	{
		heapify(base, i, nel, width);
		i--;
	}

}
