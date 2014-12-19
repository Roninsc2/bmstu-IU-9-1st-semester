#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

int segmentTree_Query(int * arr, int n, int l, int r);
int query(int * arr, int l, int r, int i, int a, int b);
void segmentTree_Build(int nel, char * arr, int * outArr);
void build(char * arr, int i, int a, int b, int * outArr);
void segmentTree_Update(int j, char v, int n, int * outArr);
void update(int j, char v, int i, int a, int b, int * outArr);
int ifPower2(int x);

int main(void)
{
        int i = 0;
	char * arr = malloc(sizeof(char) * 1000001);
	gets(arr);
	int nel = strlen(arr);
	int * outArr = calloc(4*nel, sizeof(int)); 
	int funcNel = 0;
	scanf("%d ", &funcNel);
	char str[3];
	int x = 0;
	char * helpStr = malloc(1000001*sizeof(char));
	int y = 0;
	int j = 0;
	int k = 0;
	int z = 0;
	int b = nel/ log2(nel);
	segmentTree_Build(nel, arr, outArr);
	for(i = 0; i < funcNel; i++)
	{
		z = funcNel;
		scanf("%s", str);
		if(str[0] == 'H')
		{
			scanf("%d %d", &x, &y);
			if(segmentTree_Query(outArr, nel, x, y) == 1)
			{
				printf("YES \n");
			}
			else
			{
				printf("NO \n");
			}
		}
		else
		{
			scanf("%d %s", &x , helpStr);
			k = strlen(helpStr);
			memcpy(arr+x, helpStr, k);
			if(b < k)
			{
				segmentTree_Build(nel, arr, outArr);
			}
			else
			{
				for(j = 0; j < k; j++)
				{
					segmentTree_Update(x+j, helpStr[j], nel, outArr);
				}
			}
		}
		funcNel = z;
	}
	free(helpStr);
	free(outArr);
	free(arr);
	return 0;
}
int segmentTree_Query(int * arr, int n, int l, int r)
{
	return ifPower2(query(arr, l, r, 0, 0, (n-1)));
}

int query(int * arr, int l, int r, int i, int a, int b)
{
	int v = 0;
	int m = 0;
	if(l == a && b == r)
	{
		v = arr[i];
	}
	else
	{
		m = (a + b)/2;
		if(r <= m)
		{
			v = query(arr, l, r, (2*i + 1), a, m);
		}
		else
		{
			if(l > m)
			{
				v = query(arr, l, r, (2*i + 2), m+1, b);
			}
			else
			{
				v = (query(arr, l, m, (2*i + 1), a, m) ^ query(arr, m+1, r, 2*i + 2, m + 1, b));
			}
		}
	}
	return v;
	
}

int ifPower2(int x)
{
	int count = 0;
	if(x == 0)
	{
		return 1;
	}
	else
	{
		if(x > 33554432)
		{
			return 0;
		}
	}
	while(x != 0)
	{
		if(x % 2 == 1)
		{
			count++;
		}
		x = x / 2;
	}
	if(count > 1)
	{
		return 0;
	}
	else
	{
		return 1;
	}
	
}

void segmentTree_Build(int nel, char * arr,int * outArr)
{
	build(arr, 0, 0, nel - 1, outArr);
}

void build(char * arr, int i, int a, int b, int * outArr)
{
	int m = 0;
	if(a == b)
	{
		outArr[i] = 1 << (arr[a] - 97);
	}
	else
	{
		m = (a+b)/2;
		build(arr,(2*i + 1), a, m, outArr);
		build(arr, 2*i + 2, m+1, b, outArr);
		outArr[i] = outArr[2*i + 1] ^ outArr[2*i + 2];
	}
}

void segmentTree_Update(int j, char v, int n, int * outArr)
{
	update(j, v, 0, 0, n-1, outArr);
}


void update(int j, char v, int i, int a, int b, int * outArr)
{
	int m = 0;
	if(a == b)
	{
		outArr[i] = 1 << (v-97);
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
		outArr[i] = outArr[2*i + 1] ^ outArr[2*i + 2];
	}
}
