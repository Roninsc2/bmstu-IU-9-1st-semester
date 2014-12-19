//в данной задаче выполняется алгоритм азреженной таблицы, как в лекциях
//только в место функции min мы используем функцию НОД
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void computelLogarithms(int m, int * lgArr);
int NOD(int x, int y);
int sparseTable_Query(int ** buildArr, int l, int r, int * lgArr);
void sparsetable_Build(int * arr, int n, int * lgArr, int ** buildArr);



int main(void)
{
        int n; 
	scanf("%d", &n);
	int * arr = malloc(n*sizeof(int));
	int ** buildArr = calloc(n, sizeof(int *));
	int i;
        int a = log2(n) + 1;
	for(i = 0; i < n; i++)
	{
		buildArr[i] = calloc(a, sizeof(int));
	}
	for(i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
	}
	int m;
	scanf("%d", &m);
	int * lgArr = calloc((1<<a), sizeof(int));
	int l, r;
	computelLogarithms(a, lgArr);
	sparsetable_Build(arr, n, lgArr, buildArr);
	for(i = 0; i < m; i++)
	{
		scanf("%d %d", &l, &r);
		printf("%d \n", sparseTable_Query(buildArr, l, r, lgArr));
		
	}
	for(i = 0; i < n;i++)
	{
		free(buildArr[i]);
	}
	free(buildArr);
	free(lgArr);
	free(arr);
	return 0;
}

int NOD(int x, int y)
{
	x = abs(x);
	y = abs(y);
        if (y == 0)
	{
              return x;
	}
        else
	{
                return NOD(y, x%y);
	}
}

void computelLogarithms(int m, int * lgArr)
{
	int i = 1;
	int j = 0;
	for(; i <= m; i++)
	{
		for(; j < (1<<i); j++)
		{
			lgArr[j] = i - 1;
		}
	}
}

int sparseTable_Query(int ** buildArr, int l, int r, int * lgArr)
{
	int j = lgArr[r - l + 1];
	return NOD(buildArr[l][j], buildArr[r - (1<<j) + 1][j]);
}

void sparsetable_Build(int * arr, int n, int * lgArr, int ** buildArr)
{
	int m = lgArr[n] + 1;
	int i = 0;
	while(i < n)
	{
		buildArr[i][0] = arr[i];
		i++;
	}
	int j = 1;	
	while(j < m)
	{
		i = 0;
		while(i <= n- (1<<j))
		{
			buildArr[i][j] = NOD(buildArr[i][j - 1], buildArr[i + (1<<(j - 1))][j - 1]);
			i++;
		}
		j++;
	}
}

