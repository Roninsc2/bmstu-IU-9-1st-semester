#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int segmentTree_Query(int * arr, int n, int l, int r);
int query(int * arr, int l, int r, int i, int a, int b);
void segmentTree_Build(int nel, int * arr, int * outArr);
void build(int * arr, int i, int a, int b, int * outArr, int nel);
void segmentTree_Update(int j, int n, int * outArr, int * arr);
void update(int j, int i, int a, int b, int * outArr, int * arr, int nel);
int peakCount(int a, int b, int * arr, int nel);

int main(void)
{
	int nel = 0;
	scanf("%d", &nel);
	int * arr = malloc(nel*sizeof(int));
	int * outArr = calloc(nel*4, sizeof(int)); 
	int i = 0;
	for(i = 0; i < nel; i++)
	{
		scanf("%d", &arr[i]);
	}
	int funcNel = 0;
	scanf("%d ", &funcNel);
	char str[4];
	int x = 0;
	int y = 0;
	segmentTree_Build(nel, arr, outArr);
	for(i = 0; i < funcNel; i++)
	{
		scanf("%s %d %d", str, &x, &y);
		if(str[0] == 'P')
		{
			printf("%d \n", segmentTree_Query(outArr, nel, x, y));
		}
		else
		{
			arr[x] = y;
			segmentTree_Update(x, nel, outArr, arr);
		}
	}
	free(arr);
	free(outArr);
	return 0;
}

int segmentTree_Query(int * arr, int n, int l, int r)
{
	return query(arr, l, r, 0, 0, (n-1));
}

int query(int * arr, int l, int r, int i, int a, int b)
{
	int m = 0;
	if(l == a && b == r)
	{
		return arr[i];
	}
	else
	{
		m = (a + b)/2;
		if(r <= m)
		{
			return query(arr, l, r, (2*i + 1), a, m);
		}
		else
		{
			if(l > m)
			{
				return query(arr, l, r, (2*i + 2), m+1, b);
			}
			else
			{
				return (query(arr, m+1, r, 2*i + 2, m + 1, b) + query(arr, l, m, (2*i + 1), a, m));
			}
		}
	}
}

void segmentTree_Build(int nel, int * arr, int * outArr)
{
	build(arr, 0, 0, nel - 1, outArr, nel);
}

void build(int * arr, int i, int a, int b, int * outArr, int nel)
{
	int m = 0;
	if(a == b)
	{
		outArr[i] = peakCount(a, b, arr, nel);
	}
	else
	{
		m = (a+b)/2;
		build(arr,(2*i + 1), a, m, outArr, nel);
		build(arr, 2*i + 2, m+1, b, outArr, nel);
		outArr[i] = peakCount(a, b, arr, nel);

	}
}

void segmentTree_Update(int j, int n, int * outArr, int * arr)
{
	update(j, 0, 0, n-1, outArr, arr, n);
	if (j > 0) 
	{
		update(j - 1, 0, 0, n - 1, outArr, arr, n);
	}
        if (j < n - 1)
	{
		update(j + 1, 0, 0, n - 1, outArr, arr, n);
	}
}
 
void update(int j, int i, int a, int b, int * outArr, int * arr, int nel)
{
	int m = 0;
	if(a == b)
	{
		outArr[i] = peakCount(j,j, arr, nel);
	}
	else
	{
		m = (a+b)/2;
		if(j <= m)
		{
			update(j, 2*i + 1, a, m, outArr, arr, nel);
		}
		else
		{
			update(j, 2*i + 2, m+1, b, outArr, arr, nel);
		}
		outArr[i] = outArr[2*i + 1] + outArr[2*i + 2];
	}
}

int peakCount(int a, int b, int * arr, int nel)
{
	if(nel == 1)
	{
		return 1;
	}
	int i = 0;
	int count = 0;
	for(i = a; i <= b; i++)
	{
		if((i == 0 && arr[i+1] <= arr[i]) ||  (i == nel - 1 && arr[i] >= arr[i-1])) 
		{
			count++;
		}
		else
		{
			if(i != 0 && i != nel-1 && arr[i-1] <= arr[i] && arr[i+1] <= arr[i]) 
			{
				count++;
			}
		}
	}
	return count;
}
