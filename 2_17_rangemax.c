#include <stdlib.h>
#include <stdio.h>

int segmentTree_Query(int * arr, int n, int l, int r);
int query(int * arr, int l, int r, int i, int a, int b);
void segmentTree_Build(int nel, int * arr, int * outArr);
void build(int * arr, int i, int a, int b, int * outArr);
void segmentTree_Update(int j, int v, int n, int * outArr);
void update(int j, int v, int i, int a, int b, int * outArr);

int main(void)
{
	int nel;
	scanf("%d", &nel);
	int i = 0;
	int * arr = malloc(sizeof(int) * nel);
	int * outArr = calloc(4*nel, sizeof(int)); 
	for(i = 0; i < nel; i++)
	{
		scanf("%d", &arr[i]);
	}
	int funcNel = 0;
	scanf("%d ", &funcNel);
	char * str = malloc(sizeof(char)*3);
	int x = 0;
	int y = 0;
	int j = 0;
	segmentTree_Build(nel, arr, outArr);
	for(i = 0; i < funcNel; i++)
	{
		for(j = 0; j < 3; j++)
		{
			scanf("%c", &str[j]);
		}
		scanf("%d %d ", &x, &y);
		if(str[0] == 'M')
		{
			printf("%d \n", segmentTree_Query(outArr, nel, x, y));
		}
		else
		{
			segmentTree_Update(x, y, nel, outArr);
		}
	}
	free(outArr);
	free(arr);
	free(str);
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
				if(query(arr, l, m, (2*i + 1), a, m) > query(arr, m+1, r, 2*i + 2, m + 1, b))
				{
					 return query(arr, l, m, (2*i + 1), a, m);
				}
				else
				{
					return query(arr, m+1, r, 2*i + 2, m + 1, b);
				}
			}
		}
	}
}

void segmentTree_Build(int nel, int * arr, int * outArr)
{
	build(arr, 0, 0, nel - 1, outArr);
}

void build(int * arr, int i, int a, int b, int * outArr)
{
	int m = 0;
	if(a == b)
	{
		outArr[i] = arr[a];
	}
	else
	{
		m = (a+b)/2;
		build(arr,(2*i + 1), a, m, outArr);
		build(arr, 2*i + 2, m+1, b, outArr);
		if(outArr[2*i + 1] > outArr[2*i + 2])
		{
			outArr[i] = outArr[2*i + 1];
		}
		else
		{
			outArr[i] = outArr[2*i + 2];
		}

	}
}

void segmentTree_Update(int j, int v, int n, int * outArr)
{
	update(j, v, 0, 0, n-1, outArr);
}

void update(int j, int v, int i, int a, int b, int * outArr)
{
	int m = 0;
	if(a == b)
	{
		outArr[i] = v;
	}
	else
	{
		m = (a+b)/2;
		if(j <= m)
		{
			update(j, v, 2*i + 1, a, m, outArr);
		}
		else
		{
			update(j, v, 2*i + 2, m+1, b, outArr);
		}
		if(outArr[2*i + 1] > outArr[2*i + 2])
		{
			outArr[i] = outArr[2*i + 1];
		}
		else
		{
			outArr[i] = outArr[2*i + 2];
		}
	}
}
